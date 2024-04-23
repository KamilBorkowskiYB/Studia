package z1;

import java.util.Random;
class Klient implements Runnable {
    private final Monitor monitor;
    private final int id;
    private final int c, d;
    private final Random random = new Random();

    public Klient(Monitor monitor, int id, int c, int d) {
        this.monitor = monitor;
        this.id = id;
        this.c = c;
        this.d = d;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 50; i++) {
                int czasSnu = c + random.nextInt(d - c + 1);
                Thread.sleep(czasSnu);
                String wiadomosc = monitor.wyciagnij(id, i);
                System.out.println(wiadomosc);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
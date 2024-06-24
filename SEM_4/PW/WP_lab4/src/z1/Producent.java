package z1;

import java.util.Random;

class Producent implements Runnable {
    private final Monitor monitor;
    private final int id;
    private final int a, b;
    private final Random random = new Random();

    public Producent(Monitor monitor, int id, int a, int b) {
        this.monitor = monitor;
        this.id = id;
        this.a = a;
        this.b = b;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 65; i++) {
                int czasCzekania = a + random.nextInt(b - a + 1);
                int wartosc = random.nextInt(100);
                Thread.sleep(czasCzekania);
                monitor.wstaw(id, i, wartosc);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}
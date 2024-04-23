package z2;

import java.util.Random;
class Czytelnik implements Runnable {
    private final Monitor monitor;
    private final int id;
    private final int a,b,c, d;
    private final int pow;
    private final Random random = new Random();

    public Czytelnik(Monitor monitor, int id, int a,int b, int c, int d,int p) {
        this.monitor = monitor;
        this.id = id;
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.pow = p;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < pow; i++) {
                String wiadomosc1 = monitor.czytaj_pocz(id, i);
                System.out.println(wiadomosc1);
                int czasCzekania = a + random.nextInt(b - a + 1);
                Thread.sleep(czasCzekania);
                String wiadomosc2 = monitor.czytaj_kon(id, i);
                System.out.println(wiadomosc2);
                int czasCzekania2 = c + random.nextInt(d - c + 1);
                Thread.sleep(czasCzekania2);
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

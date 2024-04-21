package zad3;

import java.util.concurrent.Semaphore;

public class Czytelnik extends Thread{
    private Semaphore czytelnik;
    private int p;

    public Czytelnik(String num,Semaphore czytelnik,int pow){
        super(num);
        this.czytelnik = czytelnik;
        this.p = pow;
    }
    public void _czytaj() {
        for (int i = 1; i <= p; i++) {
            try {
                //wlasne sprawy
                int czasCzekania = (int) (Math.random() * 15) + 5;
                Thread.sleep(czasCzekania);

                czytelnik.acquire();
                System.out.println(">>>[C-" + Thread.currentThread().getName() + ", " + i + "]");
                //czytanie
                int czasCzekania2 = (int) (Math.random() * 5) + 1;
                Thread.sleep(czasCzekania2);

                System.out.println("<<<[C-" + Thread.currentThread().getName() + ", " + i + "]");
                czytelnik.release();
            }
            catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void run()
    {
        _czytaj();
    }
}

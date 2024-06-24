package zad3;

import java.util.concurrent.Semaphore;

public class Pisarz extends Thread{
    private Semaphore pisarz;
    private Semaphore czytelnik;
    private int p;

    public Pisarz(String num,Semaphore pisarz,Semaphore czytelnik, int pow){
        super(num);
        this.pisarz = pisarz;
        this.czytelnik = czytelnik;
        this.p = pow;
    }
    public void _pisz(){
        for(int i=1; i<=p; i++) {
            try{
                //sprawy wlasne
                int czasCzekania = (int) (Math.random() * 15) + 5;
                Thread.sleep(czasCzekania);

                pisarz.acquire();
                for(int j = 0; j<3; j++) {
                    czytelnik.acquire();
                }
                System.out.println("==>[P-" +Thread.currentThread().getName() + ", " + i + "]");
                //pisanie
                int czasCzekania2 = (int) (Math.random() * 5) + 1;
                Thread.sleep(czasCzekania2);

                System.out.println("<==[P-" + Thread.currentThread().getName() + ", " + i + "]");
                for(int j = 0; j<3; j++) {
                    czytelnik.release();
                }
                pisarz.release();
            }
            catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }

        }

    }
    public void run()
    {
        _pisz();
    }
}
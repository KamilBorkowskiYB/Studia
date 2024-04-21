package zad1;

import java.util.concurrent.Semaphore;

public class Producent extends Thread{
    private int p;
    private Semaphore wolny;
    private Semaphore zajety;
    private Semaphore chron;
    private static volatile int l =0;
    private int N;
    private String elemT;
    private static volatile String[] Buffor;

    public Producent(String num,int p,Semaphore wolne,Semaphore zajete,Semaphore chron,int N,String[] Buffor){
        super(num);
        this.p = p;
        this.wolny = wolne;
        this.zajety = zajete;
        this.chron = chron;
        this.N =N;
        this.Buffor = Buffor;
    }
    public void _produkcja(int p) {
        for (int i = 1; i <= p; i++) {
            try
            {
                //sek_lok - produkcja elementu
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);
                int wartosc = (int) (Math.random() * 99);

                //sek_kryt
                wolny.acquire();
                chron.acquire();
                elemT = "Dana=[" + "P-" + Thread.currentThread().getName() + ", " + i + ", " + l + ", " + wartosc +"]";
                Buffor[l] = elemT;
                //System.out.println(elemT);
                zajety.release();
                l = (l+1) % N;
                chron.release();
            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void run(){
        _produkcja(p);
    }
}
package zad1;

import java.util.concurrent.Semaphore;

public class Klient extends Thread{
    private int p;
    private Semaphore wolny;
    private Semaphore zajety;
    private Semaphore chron;
    private static volatile int k =0;
    private String elemT;
    private int N;
    private static volatile String[] Buffor;
    public Klient(String num, int p, Semaphore wolne,Semaphore zajete,Semaphore chron,int N,String[] Buffor){
        super(num);
        this.p = p;
        this.wolny = wolne;
        this.zajety = zajete;
        this.chron = chron;
        this.N = N;
        this.Buffor = Buffor;
    }
    int pom;
    public void _konsumpcja(int p) {
        for(int i = 1; i <= p; i++){
            try
            {
                //sek_kryt
                zajety.acquire();
                chron.acquire();
                elemT = Buffor[k];
                wolny.release();
                pom=k;
                k = (k+1)%N;
                chron.release();
                //

                //sek_lok - konsumowanie elementu
                int czasCzekania = (int) (Math.random() * 12) + 2;
                Thread.sleep(czasCzekania);
                System.out.println("[K-" +Thread.currentThread().getName()+", " + i + ", " + pom + "] :: " + elemT);

            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void run(){
        _konsumpcja(p);
    }
}

package zad4;

import java.util.concurrent.Semaphore;

public class Semafor extends Thread{
    private int nr;
    private int p;
    private  int synth;
    private Semaphore semaphore;
    static  private  Object lock = new Object();
    private static volatile int[] numerek ={0,0,0,0,0};
    private int maksimum;
    private char[] znaki = {'+', '-','*','/','o'};

    public Semafor(String num,int nr,int p,int synth,Semaphore semaphore){
        super(num);
        this.nr = nr;
        this.p = p;
        this.synth = synth;
        this.semaphore = semaphore;
    }
    public void dzialanieNiesynchr(int p){
        for(int i = 0;i < p;i++){
            try{
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
                for(int j =0;j<100;j++){
                    System.out.print(znaki[nr]);
                }
                System.out.println();
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void dzialanieSynchr1(int p) {
        for (int i = 0; i < p; i++) {
            try
            {
                //sek_lok
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);
                semaphore.acquire();
                //sek_kryt
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
                for (int j = 0; j < 100; j++) {
                    System.out.print(znaki[nr]);
                }
                System.out.println();
                //
                semaphore.release();


            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void dzialanieSynchr2(int p){
        for(int i=0; i<p; i++){
            //sek_lok
            try{
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);

                synchronized(lock) {
                    System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
                    for (int j = 0; j < 100; j++) {
                        System.out.print(znaki[nr]);
                    }
                    System.out.println();
                }
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }

        }
    }
    public void run(){
        if (synth == 0) {
            dzialanieNiesynchr(p);
        } else {
            if(synth == 1){
                dzialanieSynchr1(p);
            }else{
                dzialanieSynchr2(p);
            }

        }
    }
}

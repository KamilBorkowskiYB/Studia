package zad4;

import java.util.concurrent.Semaphore;

public class Filozof extends Thread{
    private Semaphore wolno_jesc;
    private Semaphore[] widelece;
    private int index;

    public Filozof(String num,Semaphore wolno_jesc,Semaphore[] widelece) {
        super(num);
        this.wolno_jesc = wolno_jesc;
        this.widelece = widelece;
    }

    public void run() {
        int i =1;
        while(true) {
            try {
                index = Integer.parseInt(Thread.currentThread().getName())-1;
                //myslenie
                int czasCzekania = (int) (Math.random() * 15) + 5;
                Thread.sleep(czasCzekania);

                wolno_jesc.acquire();
                widelece[index].acquire();
                widelece[(index+1)%5].acquire();
                int ile_fizo = 4 - wolno_jesc.availablePermits();
                System.out.println(">>>[F-" + Thread.currentThread().getName() + ", " + i + "] :: licz_fil_przy_stole= " + ile_fizo + ", [w0=" + widelece[0].availablePermits() + ", w1="  + widelece[1].availablePermits() + ", w2=" + widelece[2].availablePermits() + ", w3=" + widelece[3].availablePermits() + ", w4=" + widelece[4].availablePermits() + "]");

                //jedzenie
                int czasCzekania2 = (int) (Math.random() * 5) + 1;
                Thread.sleep(czasCzekania2);

                widelece[index].release();
                widelece[(index+1)%5].release();
                wolno_jesc.release();
                ile_fizo = 4 - wolno_jesc.availablePermits();
                System.out.println("<<<[F-" + Thread.currentThread().getName() + ", " + i + "] :: licz_fil_przy_stole= " + ile_fizo + ", [w0=" + widelece[0].availablePermits() + ", w1="  + widelece[1].availablePermits() + ", w2=" + widelece[2].availablePermits() + ", w3=" + widelece[3].availablePermits() + ", w4=" + widelece[4].availablePermits() + "]");
            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
            i++;
        }
    }
}

package zad2;

import java.util.concurrent.Semaphore;

public class Pisarz extends Thread{
    private Semaphore pisarz;
    private Semaphore czytelnik;
    private Semaphore chron;

    public Pisarz(String num,Semaphore pisarz,Semaphore czytelnik,Semaphore chron){
        super(num);
        this.pisarz = pisarz;
        this.czytelnik = czytelnik;
        this.chron = chron;
    }
    public void _pisz(){
        int i=1;
        while(1==1){
            try
            {
                //wlasne sprawy
                int czasCzekania = (int) (Math.random() * 15) + 5;
                Thread.sleep(czasCzekania);
                chron.acquire();
                System.out.println("==>(1) [P-" + Thread.currentThread().getName() + ", " + i + "] :: [licz_czyt=" + Main.cc + ", licz_czyt_pocz=" + Main.cp + ", licz_pis=" + Main.pc + ", licz_pis_pocz=" + Main.pp+"]");
                if(Main.cc + Main.pc == 0) {
                    Main.pc = 1;

                    pisarz.release();
                }
                else {
                    Main.pp = Main.pp + 1;
                }
                System.out.println("==>(2) [P-" + Thread.currentThread().getName() + ", " + i + "] :: [licz_czyt=" + Main.cc + ", licz_czyt_pocz=" + Main.cp + ", licz_pis=" + Main.pc + ", licz_pis_pocz=" + Main.pp+"]");
                chron.release();

                pisarz.acquire();

                //pisanie
                int czasCzekania2 = (int) (Math.random() * 5) + 1;
                Thread.sleep(czasCzekania2);

                chron.acquire();
                System.out.println("<==(1) [P-" + Thread.currentThread().getName() + ", " + i + "] :: [licz_czyt=" + Main.cc + ", licz_czyt_pocz=" + Main.cp + ", licz_pis=" + Main.pc + ", licz_pis_pocz=" + Main.pp+"]");
                Main.pc = 0;
                if(Main.cp > 0) {
                    while(Main.cp > 0) {
                        Main.cc = Main.cc + 1;
                        Main.cp = Main.cp - 1;
                        czytelnik.release();
                    }
                }
                else if(Main.pp>0){
                    Main.pc = 1;
                    Main.pp = Main.pp - 1;
                    pisarz.release();
                }
                System.out.println("<==(2) [P-" + Thread.currentThread().getName() + ", " + i + "] :: [licz_czyt=" + Main.cc + ", licz_czyt_pocz=" + Main.cp + ", licz_pis=" + Main.pc + ", licz_pis_pocz=" + Main.pp+"]");
                chron.release();
            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
            i++;
        }
    }
    public void run()
    {
        _pisz();
    }
}
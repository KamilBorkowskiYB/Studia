package zad4;

import java.util.concurrent.Semaphore;

public class Main {

    public static void main(String[] args) {
        int liczba_Filozofow = 5;
        int liczba_widelcy = 5;
        Thread[] watki = new Thread[liczba_Filozofow];
        Semaphore[] widelce = new Semaphore[liczba_widelcy];
        Semaphore wolno_jesc = new Semaphore(4);

        for(int i = 0; i < liczba_Filozofow; i++)
        {
            widelce[i] = new Semaphore(1);
        }
        for(int i = 0; i < liczba_Filozofow; i++)
        {
            watki[i] = new Filozof(""+(i+1),wolno_jesc,widelce);
        }
        for(int i =0; i<liczba_Filozofow; i++){
            watki[i].start();
        }
        try{
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            System.out.println("PRZERWANIE");
        }
        for(int i=0;i<liczba_Filozofow;i++){
            watki[i].interrupt();
        }
        for(int i=0;i<liczba_Filozofow;i++){
            try{
                watki[i].join();
            }
            catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
}
package zad4;

import java.util.concurrent.Semaphore;

public class Test {
    public static void main(String[] args) {
        Thread[] watki = new Thread[5];
        Semaphore semaphore = new Semaphore(1);
        //0 - niesynchronicznie ; 1 - synchronizacja1 ; 2 -synchronizacja2
        int synth = 1;
        for(int i = 0; i < 5; i++)
        {
            watki[i] = new Semafor(""+i,i,201,synth,semaphore);
        }
        for(int i =0; i<5; i++){
            watki[i].start();
        }
        for(int i=0;i<5;i++){
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
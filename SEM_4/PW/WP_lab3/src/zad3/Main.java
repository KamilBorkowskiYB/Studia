package zad3;

import java.util.concurrent.Semaphore;

public class Main {

    public static void main(String[] args) {
        int liczba_Czytelnikow = 4;
        int liczba_Pisarzy = 2;
        int miejsca_czytelni = 3;
        int liczba_powtorzen = 50;
        Thread[] watki = new Thread[liczba_Czytelnikow+liczba_Pisarzy];

        Semaphore pisarz = new Semaphore(1);
        Semaphore czytelnik = new Semaphore(miejsca_czytelni);


        int j = 0;
        for(int i = 0; i < liczba_Czytelnikow+liczba_Pisarzy; i++)
        {
            if(i<liczba_Czytelnikow){
                watki[i] = new Czytelnik(""+(i+1),czytelnik,liczba_powtorzen);
            }
            else{
                watki[i] = new Pisarz(""+(j+1),pisarz,czytelnik,liczba_powtorzen);
                j++;
            }
        }
        for(int i =0; i<liczba_Czytelnikow+liczba_Pisarzy;i++){
            watki[i].start();
        }

        for(int i=0;i<liczba_Czytelnikow+liczba_Pisarzy;i++){
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
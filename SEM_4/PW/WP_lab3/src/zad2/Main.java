package zad2;

import java.util.concurrent.Semaphore;

public class Main {
    static volatile int cp=0;//czytelnicy w poczekalni
    static volatile int cc=0;//czytelnicy w czytelni
    static volatile int pp=0;//pisarze w poczekalni
    static volatile int pc=0;//pisarze w czytelni
    public static void main(String[] args) {
        int liczba_Czytelnikow = 4;
        int liczba_Pisarzy = 2;
        Thread[] watki = new Thread[liczba_Czytelnikow+liczba_Pisarzy];

        Semaphore pisarz = new Semaphore(0);
        Semaphore czytelnik = new Semaphore(0);
        Semaphore chron = new Semaphore(1);

        int j = 0;
        for(int i = 0; i < liczba_Czytelnikow+liczba_Pisarzy; i++)
        {
            if(i<liczba_Czytelnikow){
                watki[i] = new Czytelnik(""+(i+1),pisarz,czytelnik,chron);
            }
            else{
                watki[i] = new Pisarz(""+(j+1),pisarz,czytelnik,chron);
                j++;
            }
        }
        for(int i =0; i<liczba_Czytelnikow+liczba_Pisarzy; i++){
            watki[i].start();
        }
        try{
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            System.out.println("PRZERWANIE");
        }
        for(int i=0;i<liczba_Czytelnikow+liczba_Pisarzy;i++){
            watki[i].interrupt();
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
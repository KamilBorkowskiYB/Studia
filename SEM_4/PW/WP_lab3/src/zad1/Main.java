package zad1;

import java.util.concurrent.Semaphore;

public class Main {

    public static void main(String[] args) {
        int liczba_Producentow = 4;
        int liczba_Klientow = 5;
        int rozmiar_Bufforu = 5;
        int liczba_powtorzen = 50;
        String[] Buffor = new String[rozmiar_Bufforu];
        Thread[] watki = new Thread[liczba_Klientow+liczba_Producentow];

        Semaphore wolne = new Semaphore(rozmiar_Bufforu);
        Semaphore zajete = new Semaphore(0);

        Semaphore chron_k = new Semaphore(1);
        Semaphore chron_l = new Semaphore(1);

        int j = 0;
        for(int i = 0; i < liczba_Klientow+liczba_Producentow; i++)
        {
            if(i<liczba_Producentow){
                watki[i] = new Producent(""+(i+1),liczba_powtorzen,wolne,zajete,chron_l,rozmiar_Bufforu,Buffor);
            }
            else{
                watki[i] = new Klient(""+(j+1),liczba_powtorzen*liczba_Producentow/liczba_Klientow,wolne,zajete,chron_k,rozmiar_Bufforu,Buffor);
                j++;
            }
        }
        for(int i =0; i<liczba_Klientow+liczba_Producentow; i++){
            watki[i].start();
        }
        for(int i=0;i<liczba_Klientow+liczba_Producentow;i++){
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
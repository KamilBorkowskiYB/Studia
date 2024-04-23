package z1;

public class Main {
    public static void main(String[] args) {
        int liczba_Producentow = 4, liczba_Klientow = 5,rozmiar_Bufforu = 5, a = 1, b = 10, c = 2, d = 12;
        Monitor bufor = new Monitor(rozmiar_Bufforu);
        Thread[] producenci = new Thread[liczba_Producentow];
        Thread[] klienci = new Thread[liczba_Klientow];
        for (int i = 0; i < liczba_Producentow; i++) {
            new Thread(new Producent(bufor, i + 1, a, b)).start();
        }

        for (int i = 0; i < liczba_Klientow; i++) {
            new Thread(new Klient(bufor, i + 1, c, d)).start();
        }

    }
}
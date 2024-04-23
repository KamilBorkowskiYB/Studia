package z2;

public class Main {
    public static void main(String[] args) {
        int liczba_Czytelnikow = 5, liczba_Pisarzy = 2,rozmiar_Bufforu = 5, a = 1, b = 10, c = 2, d = 12;
        int powtorzenia=200;
        Monitor monitor = new Monitor(rozmiar_Bufforu);

        for (int i = 0; i < liczba_Czytelnikow; i++) {
            new Thread(new Czytelnik(monitor, i + 1, a, b,c,d,powtorzenia)).start();
        }

        for (int i = 0; i < liczba_Pisarzy; i++) {
            new Thread(new Pisarz(monitor, i + 1, c, d,c,d,powtorzenia)).start();
        }

    }
}

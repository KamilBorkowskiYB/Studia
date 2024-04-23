package z1;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
class Monitor {
    private final String[] bufor;
    private final int pojemnosc;
    private int pozycjaWstawienia = 0;
    private int pozycjaWyciagania = 0;
    private final ReentrantLock lock = new ReentrantLock();
    private final Condition Pelny = lock.newCondition();
    private final Condition Pusty = lock.newCondition();

    public Monitor(int pojemnosc) {
        this.pojemnosc = pojemnosc;
        this.bufor = new String[pojemnosc];
    }

    public void wstaw(int idProducenta, int powtorzenie, int wartosc) throws InterruptedException {
        lock.lock();
        try {
            while (pozycjaWstawienia == pozycjaWyciagania + pojemnosc) {
                Pusty.await();
            }
            int pozycja = pozycjaWstawienia;
            bufor[pozycja] = String.format("Dana=[P-%d, %d, %d]", idProducenta, powtorzenie, wartosc);
            pozycjaWstawienia = (pozycjaWstawienia + 1) % pojemnosc;
            Pelny.signal();
        } finally {
            lock.unlock();
        }
    }

    public String wyciagnij(int idKonsumenta, int powtorzenie) throws InterruptedException {
        lock.lock();
        try {
            while (pozycjaWstawienia == pozycjaWyciagania) {
                Pelny.await();
            }
            int pozycja = pozycjaWyciagania;
            String dane = bufor[pozycja];
            pozycjaWyciagania = (pozycjaWyciagania + 1) % pojemnosc;
            Pusty.signal();
            return String.format("[K-%d, %d] >> %s", idKonsumenta, powtorzenie, dane);
        } finally {
            lock.unlock();
        }
    }
}
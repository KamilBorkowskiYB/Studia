package z2;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
class Monitor {
    private final String[] bufor;
    private final int pojemnosc;
    private int pozycjaWstawienia = 0;
    private int pozycjaWyciagania = 0;
    private final ReentrantLock lock = new ReentrantLock();
    private final Condition czytelnicy = lock.newCondition();
    private final Condition pisarze = lock.newCondition();
    private int licz_czyt =0;
    private int licz_pisz =0;
    private int czyt_pocz =0;
    private int pisz_pocz =0;
    public Monitor(int pojemnosc) {
        this.pojemnosc = pojemnosc;
        this.bufor = new String[pojemnosc];
    }

    public String pisz_pocz(int idProducenta, int powtorzenie) throws InterruptedException {
        lock.lock();
        try {
            if(licz_czyt+licz_pisz>0){
                pisz_pocz +=1;
                pisarze.await();
                pisz_pocz -=1;
            }
            licz_pisz =1;
            return String.format("==>(1) [P-%d, %d] ::[licz_czyt=%d, licz_czyt_pocz=%d, licz_pis=%d, licz_pis_pocz=%d]",
                    idProducenta, powtorzenie,licz_czyt,czyt_pocz,licz_pisz,pisz_pocz);
        } finally {
            lock.unlock();
        }
    }
    public String pisz_kon(int idProducenta, int powtorzenie) throws InterruptedException {
        lock.lock();
        try {
            licz_pisz =0;
            if(czyt_pocz >0){
                czytelnicy.signalAll();
            }
            else{
                pisarze.signal();
            }
            return String.format("<==(2) [P-%d, %d] ::[licz_czyt=%d, licz_czyt_pocz=%d, licz_pis=%d, licz_pis_pocz=%d]",
                    idProducenta, powtorzenie,licz_czyt,czyt_pocz,licz_pisz,pisz_pocz);
        } finally {
            lock.unlock();
        }
    }

    public String czytaj_pocz(int idKonsumenta, int powtorzenie) throws InterruptedException {
        lock.lock();
        try {
            if(licz_pisz + pisz_pocz > 0){
                czyt_pocz += 1;
                czytelnicy.await();
                czyt_pocz -=1;
            }
            licz_czyt += 1;
            return String.format(">>>(1) [C-%d, %d] ::[licz_czyt=%d, licz_czyt_pocz=%d, licz_pis=%d, licz_pis_pocz=%d]",
                    idKonsumenta, powtorzenie,licz_czyt,czyt_pocz,licz_pisz,pisz_pocz);
        } finally {
            lock.unlock();
        }
    }
    public String czytaj_kon(int idKonsumenta, int powtorzenie) throws InterruptedException {
        lock.lock();
        try {
            licz_czyt -= 1;
            if(licz_czyt ==0){
                pisarze.signal();
            }
            return String.format("<<<(2) [C-%d, %d] ::[licz_czyt=%d, licz_czyt_pocz=%d, licz_pis=%d, licz_pis_pocz=%d]",
                    idKonsumenta, powtorzenie,licz_czyt,czyt_pocz,licz_pisz,pisz_pocz);
        } finally {
            lock.unlock();
        }
    }
}
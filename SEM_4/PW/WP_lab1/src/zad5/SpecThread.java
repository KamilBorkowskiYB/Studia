package zad5;

public class SpecThread extends Thread{
    private static Licznik licznik;
    public SpecThread(Licznik licz){
        this.licznik = licz;
    }

    public void run(){
        for(int i=0;i<5000000;i++) {
            licznik.incNiesynch();
        }
    }
}

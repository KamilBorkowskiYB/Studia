package zad5;

public class Licznik {
    private long war = 0;
    public long get(){
        return war;
    }
    public void incNiesynch(){
        war = war + 1;
    }
}

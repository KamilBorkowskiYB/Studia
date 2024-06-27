package zad3;

public class Test {
    int lw=5;
    public static void main(String[] args) {

        Thread[] watki = new Thread[5];
        //0 - niesynchronicznie ; 1 - synchronizacja
        int synth = 1;
        for(int i = 0; i < 5; i++)
        {
            watki[i] = new Lamport(""+i,i,201,synth);
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
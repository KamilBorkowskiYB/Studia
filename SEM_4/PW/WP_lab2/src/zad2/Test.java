package zad2;

public class Test {
    public static void main(String[] args) {
        Thread[] watki = new Thread[2];
        //0 - niesynchronicznie ; 1 - synchronizacja
        int synth = 1;
        for(int i = 0; i < 2; i++)
        {
            watki[i] = new Peterson(""+i,i,201,synth);
        }
        for(int i =0; i<2; i++){
            watki[i].start();
        }
        for(int i=0;i<2;i++){
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

package zad1;

public class Main {
    public static void main(String[] args) {
        Thread[] watki = new Thread[2];
        for(int i = 0; i < 2; i++)
        {
            watki[i] = new Dekker(""+i,i);
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
        System.out.println("KONIEC");

    }
}
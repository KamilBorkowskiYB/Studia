package zad1;

public class Test {
    public static void main(String[] args) {
        Thread[] watki = new Thread[10];
        for(int i = 0; i < watki.length; i++)
        {
            watki[i] = new SpecjalizacjaThread(""+ i);
        }
        for(int i =0; i<10; i++){
            watki[i].start();
        }
        for(int i=0;i<10;i++){
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
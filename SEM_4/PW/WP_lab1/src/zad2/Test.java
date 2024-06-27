package zad2;

public class Test {
    public static void main(String[] args) {
        Thread[] w = new Thread[10];
        for(int i = 0; i < w.length; i++)
        {
            ThreadRunnable t = new ThreadRunnable();
            w[i] = new Thread(t, ""+ i);
        }
        for(int i =0; i<10; i++){
            w[i].start();
        }
        for(int i =0; i<10; i++){
            try{
                w[i].join();
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }
        }
        System.out.println("KONIEC");
    }
}

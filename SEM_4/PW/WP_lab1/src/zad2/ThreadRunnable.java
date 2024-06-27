package zad2;

public class ThreadRunnable implements Runnable {
    public void run(){

        for(int i =0;i<10;i++)
        {
            try{
                System.out.println("Pozdrowienia z wątku " + Thread.currentThread().getName() + "nr powtorzenia " + i);
                int czasCzekania = (int) (Math.random() * 100) + 100;
                Thread.sleep(czasCzekania);
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }
        }

    }
}

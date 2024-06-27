package zad2;


import java.util.concurrent.Executors;
import java.util.concurrent.RejectedExecutionException;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Test {
    public static void main(String[] args) {
        ScheduledExecutorService exec = Executors.newScheduledThreadPool(2);
        MyTask task1 = new MyTask("TASK_1");
        MyTask task2 = new MyTask("TASK_2");

        exec.schedule(task1, 3, TimeUnit.SECONDS);

        exec.scheduleAtFixedRate(task2, 0, 2, TimeUnit.SECONDS);

        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        exec.shutdown();
        try {
            exec.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Koniec");
        try{
            exec.execute(task1);
        } catch (RejectedExecutionException e){
            System.out.println("Proba zlecenia dodatkowego zadania");
        }

    }
}

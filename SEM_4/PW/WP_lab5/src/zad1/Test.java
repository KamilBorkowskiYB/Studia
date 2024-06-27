package zad1;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class Test {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(2);

        MyTask task1 = new MyTask("TASK_1");
        exec.execute(task1);

        exec.execute(new MyTask("TASK_2"));

        /*
        Runnable task3 = () -> {

        };
        exec.execute(task3);*/

        exec.shutdown();

        try {
            exec.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Koniec");
    }
}

package zad4;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Test {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newSingleThreadExecutor();
        Future<Long> future = exec.submit(new MyCallableTask());

        long startTime = System.currentTimeMillis();
        long currentTime = startTime;
        while (!future.isDone() && (currentTime - startTime) < 3500) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            currentTime = System.currentTimeMillis();
        }

        if (!future.isDone()) {
            future.cancel(true);
        }

        try {
            if (!future.isCancelled()) {
                Long result = future.get();
                if (result != null) {
                    System.out.println("Czas wykonywania zadania: " + result + " milisekundy.");
                }
            } else {
                System.out.println("TASK PRZERWANO.");
            }
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        exec.shutdown();
        System.out.println("Koniec");
    }
}
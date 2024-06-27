package zad3;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Test {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newSingleThreadExecutor();
        Future<String> future = exec.submit(new MyCallableTask());

        while (!future.isDone()) {
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        try {
            String result = future.get();
            System.out.println("Zwrocona nazwa watku: " + result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        exec.shutdown();
        System.out.println("Koniec");
    }
}
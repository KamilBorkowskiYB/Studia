package zad6;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;

public class Test {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(4);

        Callable<Integer> task1 = new MyTask("TASK_1");
        Callable<Integer> task2 = new MyTask("TASK_2");
        Callable<Integer> task3 = new MyTask("TASK_3");
        Callable<Integer> task4 = new MyTask("TASK_4");
        List<Callable<Integer>> tasks = Arrays.asList(task1, task2, task3, task4);

        try {
            List<Future<Integer>> results = exec.invokeAll(tasks);//return od kazdego Tasku
            // obliczanie sumy
            int sum = 0;
            for (Future<Integer> result : results) {
                sum += result.get();
            }
            System.out.println("Suma wyników: " + sum);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        exec.shutdown();
        System.out.println("Koniec");
    }
}
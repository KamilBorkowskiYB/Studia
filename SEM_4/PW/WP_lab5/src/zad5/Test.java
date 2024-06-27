package zad5;

import java.util.Arrays;
import java.util.List;
import java.util.concurrent.*;

public class Test {
    public static void main(String[] args) {
        ExecutorService exec = Executors.newFixedThreadPool(4);

        Callable<String> task1 = new MyTask("TASK_1");
        Callable<String> task2 = new MyTask("TASK_2");
        Callable<String> task3 = new MyTask("TASK_3");
        Callable<String> task4 = new MyTask("TASK_4");
        List<Callable<String>> tasks = Arrays.asList(task1, task2, task3, task4);

        try {
            String result = exec.invokeAny(tasks);//invoke z pierwszzego skonczonego Tasku
            System.out.println("Pierwszy zakonczony Task: " + result);
        } catch (InterruptedException | ExecutionException e) {
            e.printStackTrace();
        }

        exec.shutdown();
        System.out.println("Koniec");
    }
}
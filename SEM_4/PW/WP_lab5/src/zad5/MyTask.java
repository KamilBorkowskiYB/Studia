package zad5;

import java.util.Random;
import java.util.concurrent.Callable;

class MyTask implements Callable<String> {
    private final String taskName;

    public MyTask(String taskName) {
        this.taskName = taskName;
    }

    @Override
    public String call() throws Exception {
        Random rand = new Random();
        int time = rand.nextInt(4) + 2;
        Thread.sleep(time * 1000);
        return taskName;
    }
}
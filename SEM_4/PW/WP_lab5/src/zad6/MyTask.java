package zad6;

import java.util.Random;
import java.util.concurrent.Callable;

class MyTask implements Callable<Integer> {
    private final String name;

    public MyTask(String name) {
        this.name = name;
    }

    @Override
    public Integer call() throws Exception {
        Random rand = new Random();
        int sleepTime = rand.nextInt(4) + 2;
        Thread.sleep(sleepTime * 1000);

        String threadName = Thread.currentThread().getName();
        int wylosowana = rand.nextInt(11);
        System.out.println("nazwa_tasku: " + name + "  nazwa_wątku: " + Thread.currentThread().getName() + "  wynik: " + wylosowana);

        return wylosowana;
    }
}


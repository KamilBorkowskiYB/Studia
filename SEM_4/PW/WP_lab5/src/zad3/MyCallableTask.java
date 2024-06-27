package zad3;

import java.util.concurrent.*;

class MyCallableTask implements Callable<String> {
    public String call() {
        try {
            TimeUnit.SECONDS.sleep(2);
            return Thread.currentThread().getName();
        } catch (InterruptedException e) {
            e.printStackTrace();
            return null;
        }
    }
}

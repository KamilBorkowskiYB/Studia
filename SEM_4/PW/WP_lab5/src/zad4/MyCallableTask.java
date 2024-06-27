package zad4;

import java.util.Random;
import java.util.concurrent.*;

public class MyCallableTask implements Callable<Long> {
    public Long call() {
        long startTime = System.currentTimeMillis();
        try {
            int sleepTime = new Random().nextInt(4) + 2;
            TimeUnit.SECONDS.sleep(sleepTime);
        } catch (InterruptedException e) {
            System.out.println("PRZERWANIE.");
            return null;
        }
        return System.currentTimeMillis() - startTime;
    }
}

package zad2;

import java.util.concurrent.*;

class MyTask implements Runnable {
    private String name;

    public MyTask(String name) {
        this.name = name;
    }

    public void run() {
        try {
            long startTime = System.currentTimeMillis();
            System.out.println("Czas od uruchomienia: " + startTime + " milisekund " + " nazwa_tasku: "+ name + "  wej: " + Thread.currentThread().getName());
            TimeUnit.SECONDS.sleep((long) (Math.random() * 6) + 1);
            System.out.println("Czas od uruchomienia: " + startTime + " milisekund " + " nazwa_tasku: "+ name + " wyj: " + Thread.currentThread().getName());
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
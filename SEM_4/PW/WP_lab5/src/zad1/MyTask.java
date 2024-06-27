package zad1;


import java.util.Random;
import java.util.concurrent.TimeUnit;

class MyTask implements Runnable {
    private String name;
    Random random = new Random();
    private long startTime = 0;
    public MyTask(String name) {
        this.name = name;

    }
    public void run() {
        long startTime = System.currentTimeMillis();
        int time = random.nextInt(6) + 1;
        long czas_uruchomienia = System.currentTimeMillis() - startTime;
        System.out.println("Czas od uruchomienia: " + czas_uruchomienia + " milisekund " +  " nazwa_tasku: " + name +  " wej: "+ Thread.currentThread().getName());

        try {
            TimeUnit.SECONDS.sleep(time);
        } catch (InterruptedException e) {
            System.out.println("Blad przy usypianiu");
        }

        czas_uruchomienia = System.nanoTime() - startTime;
        System.out.println("Czas od uruchomienia: " + czas_uruchomienia +  " milisekund " + " nazwa_tasku: " + name +  " wyj: " + Thread.currentThread().getName());

        Thread.yield();

    }
}

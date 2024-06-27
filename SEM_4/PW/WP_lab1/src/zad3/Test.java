package zad3;


public class Test {
    public static void main(String[] args) {
        Thread[] w = new Thread[10];
            for(int i =0;i<w.length;i++) {
                w[i] = new Thread(
                        new Runnable() {
                            @Override
                            public void run() {
                                for (int i = 0; i < 10; i++) {
                                    try {
                                        System.out.println("Pozdrowienia z wątku " + Thread.currentThread().getName() + "nr powtorzenia " + i);
                                        int czasCzekania = (int) (Math.random() * 100) + 100;
                                        Thread.sleep(czasCzekania);
                                    } catch (InterruptedException e) {
                                        System.out.println("PRZERWANIE");
                                        break;
                                    }
                                }
                            }
                        }
                );
        }
            for(int i=0;i<10;i++)
            {
                w[i].start();
            }
        for(int i =0; i<10; i++){
            try{
                w[i].join();
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }
        }
        System.out.println("KONIEC");
    }
}

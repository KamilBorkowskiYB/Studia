package zad1;

public class Dekker extends Thread {
    private   int nr;
    private static boolean[] chce = new boolean[2];
    private static int czyjaKolej = 0;
    private char[] znaki = {'+', '-'};

    public Dekker(String num,int nr){
        super(num);
        this.nr = nr;
    }
    public void dzialanieNiesynchr(int p){
        for(int i = 0;i < p;i++){
            try{
                int czasCzekania = (int) (Math.random() * 100) + 100;
                Thread.sleep(czasCzekania);
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr +" , nr powt.= " + i);
                for(int j =0;j<100;j++){
                    System.out.print(znaki[nr]);
                }
                System.out.println();
            }catch (InterruptedException e){
                System.out.println("PRZERWANIE");
                break;
            }

        }
    }

    public void dzialanieSynchr(int p){}

    public void run(){
        System.out.println("TEST");
        if (nr == 0) {
            dzialanieNiesynchr(5);
        } else {
            //dzialanieSynchr(5);
            dzialanieNiesynchr(5);
        }
    }
}

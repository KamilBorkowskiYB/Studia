package zad2;

public class Peterson extends Thread{
    private int nr;
    private int p;
    private  int synth;
    private static volatile boolean[] chce = {true, true};
    private static volatile int czyjaKolej = 0;
    private char[] znaki = {'+', '-'};

    public Peterson(String num,int nr,int p,int synth){
        super(num);
        this.nr = nr;
        this.p = p;
        this.synth = synth;
    }
    public void dzialanieNiesynchr(int p){
        for(int i = 0;i < p;i++){
            try{
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
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
    public void dzialanieSynchr(int p) {
        for (int i = 0; i < p; i++) {
            try {
                //sek_lok
                int czasCzekania = (int) (Math.random() * 10) + 1;
                Thread.sleep(czasCzekania);
                //
    ////chce 0 = true 1 = false
                chce[nr] = true;
                czyjaKolej = 1 - nr;
                while (chce[1 - nr] && czyjaKolej == 1-nr) {}


                //sek_kryt
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
                for (int j = 0; j < 100; j++) {
                    System.out.print(znaki[nr]);
                }
                System.out.println();
                //

                chce[nr] = false;

            } catch (InterruptedException e) {
                System.out.println("PRZERWANIE");
                break;
            }
        }
    }
    public void run(){
        if (synth == 0) {
            dzialanieNiesynchr(p);
        } else {
            dzialanieSynchr(p);
        }
    }
}

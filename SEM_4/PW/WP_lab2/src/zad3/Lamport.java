package zad3;

public class Lamport extends Thread{
    private int nr;
    private int p;
    private  int synth;

    private static volatile boolean[] wybieranie = {false,false,false,false,false};
    private static volatile int[] numerek ={0,0,0,0,0};
    private int maksimum;
    private char[] znaki = {'+', '-','*','/','o'};

    public Lamport(String num,int nr,int p,int synth){
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

                ////chce 0 = true 1 = false
                wybieranie[nr] = true;
                maksimum = numerek[0];
                for(int j=0;j<5;j++){
                    if(numerek[j]>maksimum){
                        maksimum=numerek[j];
                    }
                }
                numerek[nr]= maksimum+1;
                wybieranie[nr] = false;
                for(int k=0;k<5;k++){
                    while(wybieranie[k]){}
                    while(numerek[k] != 0 && (numerek[k] < numerek[nr] || (numerek[k] == numerek[nr] && k < nr))){}
                }


                //sek_kryt
                System.out.println("Sekcja krytyczna watku: Dekker-" + nr + " nr powt.= " + i);
                for (int j = 0; j < 100; j++) {
                    System.out.print(znaki[nr]);
                }
                System.out.println();
                //
                numerek[nr]=0;


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

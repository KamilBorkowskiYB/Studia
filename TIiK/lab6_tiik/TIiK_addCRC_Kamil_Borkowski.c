/*
Nazwa przetwarzanego pliku jest podawana w czasie dzia³ania programu w trybie konsolowym.
Program wykorzystuje domyœlny wielomian generuj¹cy (zaszyty w programie).
Zmiana wielomianu wymaga nowego zdefiniowania i nowej kompilacji.
Obliczona suma kontrolna CRC (CRC checksum) jest zapisywana binarnie do specjalnie tworzonego pliku.
Nazwa specjalnego pliku zostaje utworzona przez zmianê rozszerzenia na .CRC
Dodatkowo plik wejœciowy jest przepisywany do nowo tworzonego pliku i dopisywane jest doñ CRC.
Uzupe³niony o CRC plik ma nazwê z do³¹cznym przyrostkiem _zCRC, rozszenie pozostaje bez zmian.
*/


#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define kropka 46
#define buforekSize 256
#define CRCsize 4
#define buforSize 1

int zmienRozszerzenieNazwy(char *nazwa, char *rozszerzenie, char *nazwaNowa) 
{
    char *w_nazwy;
    int i,n;
    
    //Wydruk kontrolny
    //printf("Przekazana nazwa pliku do zmiany rozszerzenia:  %s \n", nazwa);
    //printf("Przekazane nowe rozszerzenie:  %s \n", rozszerzenie);
    //Type field  s describes null-terminated string.
    //https://en.wikipedia.org/wiki/Printf_format_string
	    
    //czyszczenie pamieci 
    for (n=0; n<24; ++n)
       nazwaNowa[n]=0;
    n=0;
    w_nazwy=nazwa;
    nazwaNowa[n]=*w_nazwy;
    while ((nazwa[n]!=kropka)&&(nazwa[n]!='\0'))
           {
           n++;
           w_nazwy++;
           nazwaNowa[n]=*w_nazwy;
           }
    n++;
    i=0;
    nazwaNowa[n]=rozszerzenie[i];
    while (rozszerzenie[i]!='\0')
           {
           n++;
           i++;
           nazwaNowa[n]=rozszerzenie[i];
           }     
    
	//printf("Nowa nazwa: %s \n", nazwaNowa);		       
    return 0;
}    
//#define kropka 46

int dopiszPrzyrostekDoNazwy(char *nazwa, char *przyrostek, char *nazwaNowa) 
{
    char *wNazwy;
    int i,n,nK;
    
    //Wydruk kontrolny
    printf("Przekazana nazwa pliku do zmiany:  %s \n", nazwa);
    printf("Przekazany nowy przyrostek:  %s \n", przyrostek);
    
    //Type field  s describes null-terminated string.
    //https://en.wikipedia.org/wiki/Printf_format_string
	    
    //czyszczenie pamieci 
    for (n=0; n<24; ++n)
       nazwaNowa[n]=0;
       
    n=0;
    wNazwy=nazwa;
    nazwaNowa[n]=*wNazwy;
    while ((nazwa[n]!=kropka)&&(nazwa[n]!='\0'))
       {
        n++;
        wNazwy++;
        nazwaNowa[n]=*wNazwy;
       }
    nK=n;
    i=0;
    nazwaNowa[n]=przyrostek[i];
    while (przyrostek[i]!='\0')
       {
        n++;
        i++;
        nazwaNowa[n]=przyrostek[i];
       }     
   
    while (nazwa[nK]!='\0')
       {
        nazwaNowa[n]=*wNazwy;
        n++;
        nK++;
        wNazwy++;
       }
    
	printf("Nowa nazwa: %s \n", nazwaNowa);		       
    return 0;
}    

int obliczCRC(char *nazwaPlikuIn, unsigned char reszta[], unsigned char wielomian[])
{
 


 unsigned char kolejka[CRCsize+buforSize]; 
 unsigned char buforWejscia[buforSize];   
 unsigned char start=0, koniec=0, maska=128, ostatniBit, pierwszyBit;
 int degreeGen=8*CRCsize;
 int licznikBitow=0;
 int licznikBajtowIn=0, licznikBuforu=0;
 int n,m,i;
 
   
	//Zerowanie ca³ej kolejki
     for (i=0; i<CRCsize+buforSize; i++)
       kolejka[i]=0;   
 
    FILE *wskaznikPlikuIn=NULL;
	wskaznikPlikuIn=fopen(nazwaPlikuIn,"rb"); 
    if (wskaznikPlikuIn == NULL)
	{
	  printf("Nie mozna otworzyc pliku: %s  \n", nazwaPlikuIn);
	  exit(EXIT_FAILURE);
	}

    while(n=fread(buforWejscia,sizeof(unsigned char),buforSize,wskaznikPlikuIn)) 
    {
        
        licznikBajtowIn+=n;
		//dopisanie odczytanego fragmentu pliku do kolejki
        for (i=0; i<n; i++)
            kolejka[CRCsize+i]=buforWejscia[i];
                  
        licznikBitow=8*n; //n- liczba odczytanych bajtów
        while (licznikBitow)
        {
            licznikBuforu=1+(licznikBitow-1)/8; 
          
            pierwszyBit=maska&kolejka[0];    
         
         //Przesuwanie kolejki o 1 bit w lewo
         //Realizacja przesuwania: kolelno bajtami
         //Uwaga: zmienne pierwszyBit i ostatniBit s¹ bajtami, tzn. typu unsigned char 
            for (i=0; i<CRCsize+licznikBuforu; i++)
               {
                kolejka[i]=(kolejka[i]<<1);
                ostatniBit=kolejka[i+1]>>7;//wyd³ubanie pierwszego bitu w nastêpnym bajcie i zapisanie go jako ostatniBit
                //Przejêcie bitu z nastêpnego bajtu 
                kolejka[i]=kolejka[i]|ostatniBit; 
                //printf("Bajt %d kolejki po przesunieciu: %#x\n", i, kolejka[i]);
               }
          
          //Wykonanie operacji XOR, jeœli pierwszyBit jest jedynk¹
		    if (pierwszyBit!=0)  //jesli pierwszy bit jest jedynka
                for(i=0; i<CRCsize; i++)
                   {
                    kolejka[i]=kolejka[i]^wielomian[i];          
                    //printf("Bajt %d kolejki po xorowaniu: %#x\n", i, kolejka[i]);
                   }     
          licznikBitow--;  
                   
        }   
    }
    
    fclose(wskaznikPlikuIn); 
    
    //Uzupe³nienie pliku zerami, tak aby po dopisaniu reszty do pliku uzupe³niony plik mia³ zerowe CRC
    //Liczba dopisywanych zer = stopieñ wielomianu (zmienna degreeGen)
    licznikBitow=degreeGen;
    while (licznikBitow>0)
       {
        pierwszyBit=maska&kolejka[0];    
        //printf("Pierwszy bit %#x\n", pierwszyBit);  
        for (i=0; i<CRCsize; i++)
           {
            kolejka[i]=(kolejka[i]<<1);
            ostatniBit=kolejka[i+1]>>7;
            kolejka[i]=kolejka[i]|ostatniBit; 
           }  
        //Zero na koncu jest pojawia siê samo - z definicji przesuniecia       
        if (pierwszyBit!=0)  //jesli pierwszy bit jest jedynka                              
            for(i=0; i<CRCsize; i++)
               {
                kolejka[i]=kolejka[i]^wielomian[i];          
                //printf("Bajt %d kolejki po xorowaniu: %#x\n", i, kolejka[i]);
               }     
        licznikBitow--;       
       }
 
    for(i=0; i<CRCsize; i++)
        reszta[i]=kolejka[i];          
                 
 return licznikBajtowIn;   

}

int przepiszFile(char *nazwaIn, char *nazwaOut) 
{
    int ile, licznikBajtow;
    unsigned char buforWejscia[buforekSize];   
   
    FILE *wskaznikFileIn=NULL;
    wskaznikFileIn=fopen(nazwaIn,"rb"); 
    if(wskaznikFileIn==NULL)
       {  
	    printf("\n Unable to open file for reading \n");
        exit(1);
       };
    FILE *wskaznikFileOut=NULL;
    wskaznikFileOut=fopen(nazwaOut,"wb"); 
    if(wskaznikFileOut==NULL)
       { 
	    printf("\n Unable to open file for writing\n ");
        exit(2);
       };
    licznikBajtow=0;
    while(ile=fread(buforWejscia,sizeof(unsigned char),buforekSize,wskaznikFileIn)) 
       {
       	licznikBajtow+=ile;
		fwrite(buforWejscia, sizeof(unsigned char), ile, wskaznikFileOut);
	   }
    fclose(wskaznikFileIn); 
    fclose(wskaznikFileOut);
       
return 0;
}

int main()
{
    unsigned char wielomian[CRCsize], reszta[CRCsize];
    unsigned char bajt[CRCsize];
    char nazwaPlikuIn[24];
    char rozszerzenieCRC[]= "CRC";
    char przyrostekCRC[]="_zCRC";
    char nazwaDlaCRC[24];
    char nazwaPlikPlusCRC[24];
    int n, stopien=32;
    int i;

//Wielomian generuj¹cy domyœlny
    wielomian[0]=0x04;
    wielomian[1]=0xc1;
    wielomian[2]=0x1d;
    wielomian[3]=0xb7;


    for (i=0; i<CRCsize; i++)
        {
        //printf("Podaj szesnastkowo %d. bajt wielomianu generujacego: \n", i+1);
        //scanf("%x",&wielomian[i]);
        printf("Wartosc %d. bajtu wielomianu to: %02x\n", i, wielomian[i]);
        }

    printf("Podaj nazwe pliku, dla ktorego wyznaczane jest CRC:\n");
    scanf("%s",nazwaPlikuIn);
    printf("Nazwa przetwarzanego pliku to: %s\n", nazwaPlikuIn);  
 

    n=obliczCRC(nazwaPlikuIn, reszta, wielomian);
    
    printf("Liczba bajtow w pliku %d\n", n);
    printf("Obliczona wartosc CRC:\n"); 
    for(i=0; i<CRCsize; i++) 
        printf("Bajt %d wartosci CRC: %#x\n", i, reszta[i]);
   
    zmienRozszerzenieNazwy(nazwaPlikuIn, rozszerzenieCRC, nazwaDlaCRC);  
    FILE *wskaznikPlikuOut=NULL;
    wskaznikPlikuOut=fopen(nazwaDlaCRC,"wb");
    fwrite(reszta, sizeof(reszta), 1,wskaznikPlikuOut);
    fclose(wskaznikPlikuOut); 
  	printf("Wartosc CRC zostala zapisana jako nowy plik: %s\n", nazwaDlaCRC);     
	
	//Odczyt kontrolny  
	printf("Odczyt kontrolny z pliku: %s\n", nazwaDlaCRC);     
    FILE *wskaznikPlikuCRC=NULL;
    wskaznikPlikuCRC=fopen(nazwaDlaCRC,"rb"); 
    n=fread(bajt,sizeof(unsigned char),CRCsize,wskaznikPlikuCRC);
    for(i=0; i<CRCsize; i++) 
   	    printf("Bajt o indeksie %d:  zapis hex: %#x\n", i, bajt[i]);
    fclose(wskaznikPlikuCRC); 
    
    //Tworzenie nowego pliku przez przepisanie pliku przetwarzanego i dopisanie doñ CRC
    dopiszPrzyrostekDoNazwy(nazwaPlikuIn, przyrostekCRC, nazwaPlikPlusCRC); 

    przepiszFile(nazwaPlikuIn, nazwaPlikPlusCRC); 
    printf("Plik %s zostal przepisany do nowego pliku %s\n", nazwaPlikuIn, nazwaPlikPlusCRC);    
    
    FILE *wskaznikPlikuAdd=NULL;
    wskaznikPlikuAdd=fopen(nazwaPlikPlusCRC,"ab");
    fwrite(reszta, sizeof(reszta), 1,wskaznikPlikuAdd);
    fclose(wskaznikPlikuAdd);
    printf("CRC zostalo dopisane do pliku %s\n", nazwaPlikPlusCRC);  
     
    return 0;
    
} 

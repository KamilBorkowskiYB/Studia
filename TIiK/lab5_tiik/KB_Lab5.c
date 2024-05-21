#include <stdlib.h>
#include <stdio.h>

int CRC(char *plikWej, unsigned char reszta[], unsigned char wielomian[])
{
unsigned char kolejka[5];
unsigned char buforWejscia[1];
unsigned char maska=128, ostatniBit, pierwszyBit;
int stopien=32;
int ileBajt=0, bufs=0, ileBit=0;
int n,i;// n = odczytane bajty

    for(i=0; i<5; i++)
    {
        kolejka[i]=0;
    }

    FILE *wskaznikPlikuIn=fopen(plikWej,"rb");
    if(wskaznikPlikuIn == NULL)
	{
        printf("Error_1");
        exit(EXIT_FAILURE);
	}

    while(n=fread(buforWejscia,sizeof(unsigned char),1,wskaznikPlikuIn))
    {
        ileBajt+=n;
        for(i=0; i<n; i++)
        {
            kolejka[4+i]=buforWejscia[i];
        }

        ileBit=8*n;
        while(ileBit)
        {
            bufs=1+(ileBit-1)/8;
            pierwszyBit=maska&kolejka[0];

            for(i=0; i<4+bufs; i++)//sprawdzanie kolejnych bitow
            {
                kolejka[i]=(kolejka[i]<<1);
                ostatniBit=kolejka[i+1]>>7;//pierwszy bit nastepnego bajtu staje sie ostatnim bitem w aktualnym bajcie
                kolejka[i]=kolejka[i]|ostatniBit;//przesuniecie bitu miedzy kolejnymi bajtami
            }
            if(pierwszyBit != 0)// operacja xor jestli pierwszyBit nie jest 0
            {
                for(i=0; i<4; i++)
                {
                    kolejka[i]=kolejka[i]^wielomian[i];
                }
            }
            ileBit--;
        }
    }
    fclose(wskaznikPlikuIn);


    ileBit=stopien;
    while(ileBit>0)
    {
        pierwszyBit=maska&kolejka[0];
        for (i=0; i<4; i++)
        {
            kolejka[i]=(kolejka[i]<<1);
            ostatniBit=kolejka[i+1]>>7;
            kolejka[i]=kolejka[i]|ostatniBit;
        }
        if (pierwszyBit!=0)  //jesli pierwszy bit jest jedynka
        {
            for(i=0; i<4; i++)
            {
                kolejka[i]=kolejka[i]^wielomian[i];
            }
        }
        ileBit--;
    }
    for(i=0; i<4; i++)
    {
        reszta[i]=kolejka[i];
    }

 return ileBajt;
}
int main()
{
    unsigned char wielomian[4], reszta[4], bajt[4];
    char plikWej[24], plikWyj[24];
    char kropkaCRC[]= "CRC";
    int i, n, stopien=32;

    //default wielomian
    wielomian[0]=0x04;
    wielomian[1]=0xc1;
    wielomian[2]=0x1d;
    wielomian[3]=0xb7;

    printf("Poczatkowe wartosci bajtow wielomianu\n");
    for (i=0; i<4; i++)
    {
        printf("%d. bajt wielomianu ma wartosc - %#x\n", i+1, wielomian[i]);
    }
    printf("Podaj nazwe pliku wraz z rozszerzeniem do obliczenia CRC\n");
    scanf("%s",plikWej);
    n=CRC(plikWej, reszta, wielomian);

    printf("Plik zawiera %d bajtow\n", n);
    printf("Obliczone CRC:\n");
    for(i=0; i<4; i++)
    {
        printf("%d. bajt wielomianu ma wartosc - %#x\n", i+1, reszta[i]);
    }
    //uzupelnianie pliku wyjsciowego
    char *plik;
    for(n=0; n<24; ++n)
    {
       plikWyj[n]=0;
    }
    n=0;
    plik=plikWej;
    plikWyj[n]=*plik;
    while((plikWej[n]!=46)&&(plikWej[n]!='\0'))
    {
        n++;
        plik++;
        plikWyj[n]=*plik;
    }
    n++;
    i=0;
    plikWyj[n]=kropkaCRC[i];
    while(kropkaCRC[i]!='\0')
    {
       n++;
       i++;
       plikWyj[n]=kropkaCRC[i];
    }

    FILE *wskaznikPlikuOut=fopen(plikWyj,"wb");
    fwrite(reszta, sizeof(reszta), 1,wskaznikPlikuOut);
    fclose(wskaznikPlikuOut);
    printf("Wartosc CRC zapisano w pliku: %s\n", plikWyj);
    return 0;
}

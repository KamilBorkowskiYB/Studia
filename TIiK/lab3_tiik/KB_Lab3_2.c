#include <stdlib.h>
#include <stdio.h>
#define BUFSIZE 128
#define kropka 46
#define rozTAB 24
void dekompresja()
{
    extern char plikWejsciowy[rozTAB];
    extern char plikWyjsciowy[rozTAB];

    struct wezel
    {
        int parent;
        int childL;
        int childR;
    };
    struct wezel drzewoKodowania[256];

    unsigned int bityNaWejsciu, bajtyKodu, bityKodu,zdekodowaneBajty, bajtyNaWejsciu, zdekodowaneBity;
    int brancheDrzewa, indeksDrzewa,odczytD[3],father,child1,child2,n,i,m,k;
    unsigned char bajtIn, bajtOut, jakiBit,maska=128;

    printf("Nazwa pliku do dekompresji: %s  \n", plikWejsciowy);

    FILE *wskaznikPlikuZipIn=fopen(plikWejsciowy,"rb");

    if (wskaznikPlikuZipIn == NULL)
	{
		printf("Nie mozna otworzyc pliku: %s  \n", plikWejsciowy);
		exit(EXIT_FAILURE);
	}

	fread(&bajtyKodu,sizeof(unsigned int),1,wskaznikPlikuZipIn);
	printf("Plik do dekompresji zawiera %d  bajtow kodu\n",bajtyKodu);
	fread(&bityKodu,sizeof(unsigned int),1,wskaznikPlikuZipIn);
	printf("Plik do dekompresji zawiera %d  bitow kodu\n",bityKodu);
	fread(&bityNaWejsciu,sizeof(unsigned int),1,wskaznikPlikuZipIn);
	printf("Oryginal pliku zawiera %d  bajtow\n",bityNaWejsciu);
	fread(&brancheDrzewa,sizeof(int),1,wskaznikPlikuZipIn);
	printf("Plik do dekompresji zawiera tabele drzewa o %d rozgalezien\n",brancheDrzewa );

    printf("Tabela drzewa\n");
	for (n=0;n<brancheDrzewa; ++n)
    {
	    fread(&odczytD,sizeof(int),3,wskaznikPlikuZipIn);
        drzewoKodowania[n].parent=odczytD[0];
        drzewoKodowania[n].childL=odczytD[1];
        drzewoKodowania[n].childR=odczytD[2];
        printf("%d %d %d %d\n", n, odczytD[0], odczytD[1], odczytD[2]);
    }
    FILE *wskaznikPlikuRecovery=fopen(plikWyjsciowy,"wb");

    bajtyNaWejsciu=0;
    zdekodowaneBity=0;
    zdekodowaneBajty=0;
    indeksDrzewa=brancheDrzewa-1;
    father=drzewoKodowania[indeksDrzewa].parent;
    child1=drzewoKodowania[indeksDrzewa].childL;
    child2=drzewoKodowania[indeksDrzewa].childR;

    while(bajtyNaWejsciu<bajtyKodu)
    {
        n=fread(&bajtIn,sizeof(unsigned char),1,wskaznikPlikuZipIn);
        if (n==1)
        {
            bajtyNaWejsciu++;
            for (k=0;k<8; ++k)
            {
                jakiBit=bajtIn&maska;
                bajtIn=bajtIn<<1;
                zdekodowaneBity++;
                if(jakiBit){
                    father=child1;
                }
                else{
                  father=child2;
                }

                if(father<256)
                {
                   bajtOut=father;
                   fwrite(&bajtOut,sizeof(unsigned char),1,wskaznikPlikuRecovery);
                   zdekodowaneBajty++;
                   indeksDrzewa=brancheDrzewa-1;
                   father=drzewoKodowania[indeksDrzewa].parent;
                   child1=drzewoKodowania[indeksDrzewa].childL;
                   child2=drzewoKodowania[indeksDrzewa].childR;
                   if(zdekodowaneBajty == bityNaWejsciu)
                   {
                      break;
                   }
                }
                else
                {
                    m=brancheDrzewa-1;
                    while (m>=0)
                    {
                       if(drzewoKodowania[m].parent==father)
                       {
                            indeksDrzewa=m;
                            m=-1;
                       }
                       m=m-1;
                    }
                    child1=drzewoKodowania[indeksDrzewa].childL;
                    child2=drzewoKodowania[indeksDrzewa].childR;
                }
            }
        }
    }

printf("Zdekodowano %d bajtow z %d\n", bityNaWejsciu, zdekodowaneBajty);
fclose(wskaznikPlikuZipIn);
fclose(wskaznikPlikuRecovery);
}

char plikWejsciowy[rozTAB];
char plikWyjsciowy[rozTAB];

int noweRozszerzenie(char *nazwa, char *rozszerzenie, char *nowaNazwa)
{
    char *znakNazwy;
    int i=0,j=0;
    for(i=0; i<rozTAB; ++i){
        nowaNazwa[i]=0;
    }
    i=0;
    znakNazwy=nazwa;
    nowaNazwa[i]=*znakNazwy;
    while ((nazwa[i]!=kropka)&&(nazwa[i]!='\0'))
    {
        i++;
        znakNazwy++;
        nowaNazwa[i]=*znakNazwy;
    }
    i++;
    nowaNazwa[i]=rozszerzenie[j];
    while (rozszerzenie[j]!='\0')
    {
        i++;
        j++;
        nowaNazwa[i]=rozszerzenie[j];
    }
    return 0;
}

void przepiszNazwe(char *nazwa, char *nowaNazwa)
{
    char *znakNazwy;
    int i;

    for (i=0;i<rozTAB;++i){
       nowaNazwa[i]=0;
    }
    i=0;
    znakNazwy=nazwa;
    nowaNazwa[i]=*znakNazwy;
    while (nazwa[i]!='\0')// \0 - symbol koncza linii
    {
        i++;
        znakNazwy++;
        nowaNazwa[i]=*znakNazwy;
    }
}

void bazaNazwDeKomp(char *nazwa)
{
	char rozPlikuRecovery[]="recovery";

   	przepiszNazwe(nazwa,plikWejsciowy);
    printf("bazaNazw:  %s \n", plikWejsciowy);

    noweRozszerzenie(nazwa,rozPlikuRecovery, plikWyjsciowy);
    printf("bazaNazw:  %s \n", plikWyjsciowy);
}

int main(int argc, char *argv[])
{
    char *nazwaPliku;

    if(argc==2)
    {
        nazwaPliku=argv[1];
    }
	else
    {
   		printf("Zla liczba parametrow.  ","%d", argc);
		exit(EXIT_FAILURE);
    }
    bazaNazwDeKomp(nazwaPliku);
    dekompresja();

	return 0;
}


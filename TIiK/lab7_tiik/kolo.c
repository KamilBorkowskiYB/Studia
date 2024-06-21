#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 216 //rozmiar tablicy bufora
#define rozTAB 24 //rozmiar tablic nazw plikow

char plikWejsciowy[rozTAB];
char plikWyjsciowy[rozTAB];
char nazwaPlikuZipIn[rozTAB];
char nazwaPlikuRecovery[rozTAB];

//struktura tablicy dla modelu Shannona
struct symbolDane
{
    int symbol;
    int ilosc;
};
struct symbolDane modelShannona[256];
struct symbolDane modelSortShannon[256];

struct wezel
{
    int parent;
    int childL;
    int childR;
};
struct wezel drzewo[256];

struct slowoDlaSymbolu
{
    int symbol;
    unsigned char slowo[4];
    int liczbaBitow;
};
struct slowoDlaSymbolu tablicaKoduFull[512];
struct slowoDlaSymbolu tablicaKodu[256];

struct zrodlo
{
    char nazwaPlikuModel[rozTAB];
    char nazwaPlikuModelSort[rozTAB];
    char nazwaPlikuIleBajtow[rozTAB];
    char nazwaPlikuDrzewo[rozTAB];
    char nazwaPlikuTabelaKoduFull[rozTAB];
    char nazwaPlikuTabelaKodu[rozTAB];
    unsigned int bajtyNum;
    int symboleNum;
    int dodaneSymbole;
};
struct zrodlo dokumentacja;

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

int noweRozszerzenie(char *nazwa, char *rozszerzenie, char *nowaNazwa)
{
    char *znakNazwy;
    int i=0,j=0;

    //czyszczenie pamieci
    for(i=0; i<rozTAB; ++i){
        nowaNazwa[i]=0;
    }
    i=0;
    znakNazwy=nazwa;
    nowaNazwa[i]=*znakNazwy;
    while ((nazwa[i]!=46)&&(nazwa[i]!='\0'))
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

void bazaNazw(char *nazwa)
{
	char rozModel[]= "model";
    char rozModelSort[]= "modelSort";
    char rozIleBajtow[]= "ileBajtow";
	char rozDrzewo[]="drzewo";
	char rozTabelaKoduFull[]="tabelaKoduFull";
	char rozTabelaKodu[]="tabelaKodu";
	char rozPlikOut[]="Huffman";

	dokumentacja.bajtyNum=0;
    dokumentacja.symboleNum=0;

	przepiszNazwe(nazwa,plikWejsciowy);
    printf("bazaNazw:  %s \n", plikWejsciowy);

    noweRozszerzenie(nazwa,rozModel, dokumentacja.nazwaPlikuModel);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuModel);

    noweRozszerzenie(nazwa,rozModelSort, dokumentacja.nazwaPlikuModelSort);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuModelSort);

    noweRozszerzenie(nazwa,rozIleBajtow, dokumentacja.nazwaPlikuIleBajtow);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuIleBajtow);

    noweRozszerzenie(nazwa,rozDrzewo, dokumentacja.nazwaPlikuDrzewo);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuDrzewo);

    noweRozszerzenie(nazwa,rozTabelaKoduFull, dokumentacja.nazwaPlikuTabelaKoduFull);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuTabelaKoduFull);

    noweRozszerzenie(nazwa,rozTabelaKodu, dokumentacja.nazwaPlikuTabelaKodu);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuTabelaKodu);

    noweRozszerzenie(nazwa,rozPlikOut, plikWyjsciowy);
    printf("bazaNazw:  %s \n", plikWyjsciowy);

}

void modelNieSort(){
 unsigned char buforIn[BUFSIZE];
 int i=0,id=0, symboleNum=0, rozLinii=0, bajtyNumMain=0;
 FILE *wskaznikPlikuIn=fopen(plikWejsciowy,"rb");

    if(wskaznikPlikuIn==NULL)
	{
		printf("Nie mozna otworzyc pliku: %s  \n", plikWejsciowy);
		exit(EXIT_FAILURE);
	}
    for(i=0; i<256; ++i)//poczatkowe wyzerowanie tablicy
    {
        modelShannona[i].symbol=i;
        modelShannona[i].ilosc=0;
    }

	while(rozLinii=fread(buforIn,sizeof(unsigned char),BUFSIZE,wskaznikPlikuIn))//czytanie do pustej linii
    {
        for(i=0;i<rozLinii;++i)//zliczanie wystapien symbolu
        {
            id = buforIn[i];
            modelShannona[id].ilosc++;
        }
        bajtyNumMain+=rozLinii;
    }
    fclose(wskaznikPlikuIn);

    //uzupelnienie pliku .ileBajtow
    FILE *wskaznikIle=fopen(dokumentacja.nazwaPlikuIleBajtow,"wb");
    if (wskaznikIle == NULL)
	{
		printf("Nie udalo sie otworzyc pliku .ileBajtow\n");
		exit(EXIT_FAILURE);
	}
    printf("Przeczytano %d bajty/ow.\n",bajtyNumMain);
    fprintf(wskaznikIle,"%d",bajtyNumMain);
    printf("Uzupelniono plik .ileBajtow \n");
    fclose(wskaznikIle);

    for (i=0;i<256; ++i)
    {
        if  (modelShannona[i].ilosc!=0)
        {
            modelShannona[symboleNum].symbol=modelShannona[i].symbol;
            modelShannona[symboleNum].ilosc=modelShannona[i].ilosc;
            symboleNum++;
        }
    }
    FILE *wskaznikModel=fopen(dokumentacja.nazwaPlikuModel,"wb");

    if (wskaznikModel==NULL)
	{
		printf("Nie udalo sie otworzyc pliku .model\n");
		exit(EXIT_FAILURE);
	}
    for(i=0;i<symboleNum;++i)
    {
        fprintf(wskaznikModel,"%d %d\n", modelShannona[i].symbol, modelShannona[i].ilosc);
    }

    dokumentacja.symboleNum=symboleNum;
    dokumentacja.bajtyNum= bajtyNumMain;

    printf("Uzupelniono plik .model nieposortowanym schematem Shannona\n");
	fclose(wskaznikModel);
}



int sortPom(const void *parL,const void *parR)
{
    const struct symbolDane *wskL = (const struct symbolDane*) parL;
    const struct symbolDane *wskR = (const struct symbolDane*) parR;
    if((wskL->ilosc)==(wskR->ilosc)) return 0;
    else if((wskL->ilosc)<(wskR->ilosc))return 1;
    else return -1;
}


void modelSort()
{
	struct symbolDane modelRobol[256];
	int liczbaSymboli;
	int i;

    liczbaSymboli=dokumentacja.symboleNum;
    printf("Liczba symboli  %d \n", liczbaSymboli);
    for( i=0; i<liczbaSymboli; ++i)
        {
            modelRobol[i].symbol= modelShannona[i].symbol;
            modelRobol[i].ilosc=modelShannona[i].ilosc;
        }

	qsort(modelRobol,liczbaSymboli,sizeof(struct symbolDane), sortPom);

    FILE *wskaznikPliku=NULL;
	wskaznikPliku=fopen(dokumentacja.nazwaPlikuModelSort,"wb");
    if (wskaznikPliku == NULL)
	{
		printf("Nie mozna utworzyc pliku: %s \n", dokumentacja.nazwaPlikuModelSort);
		exit(EXIT_FAILURE);
	}

    printf("Model posortowany zrodla \n");
    for( i=0; i<liczbaSymboli; ++i)
        {
            modelSortShannon[i].symbol= modelRobol[i].symbol;
            modelSortShannon[i].ilosc=modelRobol[i].ilosc;
            fprintf(wskaznikPliku, "  %d  %d\n", modelSortShannon[i].symbol, modelSortShannon[i].ilosc);
            printf("%d indeks tablicy %d liczebnosc  %d\n", i, modelRobol[i].symbol, modelRobol[i].ilosc);
        }

    fclose(wskaznikPliku);
    printf("Model Shannona posortowany zapisano do pliku  %s \n", dokumentacja.nazwaPlikuModelSort);

}


void zrobDrzewo(void)
{
int liczbaSymboli =  dokumentacja.symboleNum;
int licznikSymboli;
int licznikSymboliDodanych = 0;
int n,k;
struct symbolDane modelDlaDrzewa[256];

    for(k=0; k<liczbaSymboli; k++)
    {
        modelDlaDrzewa[k].symbol   = modelSortShannon[k].symbol;
        modelDlaDrzewa[k].ilosc = modelSortShannon[k].ilosc;

     };


    licznikSymboli=dokumentacja.symboleNum;

    for(k=0; k<liczbaSymboli-1; k++)
    {
        drzewo[k].parent = 256+k;
        drzewo[k].childL =  modelDlaDrzewa[liczbaSymboli-1-k].symbol;
        drzewo[k].childR =  modelDlaDrzewa[liczbaSymboli-2-k].symbol;
        modelDlaDrzewa[liczbaSymboli-2-k].symbol = 256+k;
        modelDlaDrzewa[liczbaSymboli-2-k].ilosc = modelDlaDrzewa[liczbaSymboli-1-k].ilosc + modelDlaDrzewa[liczbaSymboli-2-k].ilosc;
        licznikSymboli--;
        qsort(modelDlaDrzewa,licznikSymboli,sizeof(struct symbolDane), sortPom);
        licznikSymboliDodanych++;
     }

    FILE *wskaznikPliku=NULL;
	wskaznikPliku=fopen(dokumentacja.nazwaPlikuDrzewo,"wb");

    if (wskaznikPliku == NULL)
	    {
		printf("Nie mozna utworzyc pliku: \n", dokumentacja.nazwaPlikuDrzewo);
		exit(EXIT_FAILURE);
	    };


    printf("Drzewo Huffmana \n");
    for(k=0; k<licznikSymboliDodanych; k++)
          {
           fprintf(wskaznikPliku, "%d %d %d\n ", drzewo[k].parent, drzewo[k].childL, drzewo[k].childR );
           printf("%d %d %d\n ", drzewo[k].parent, drzewo[k].childL, drzewo[k].childR );
          };

    fclose(wskaznikPliku);

    dokumentacja.dodaneSymbole=licznikSymboliDodanych;

    FILE *wskaznikPlikuIle=NULL;
	wskaznikPlikuIle=fopen(dokumentacja.nazwaPlikuIleBajtow,"ab");

    if (wskaznikPliku == NULL)
	    {
		printf("Nie mozna utworzyc pliku: \n", dokumentacja.nazwaPlikuDrzewo);
		exit(EXIT_FAILURE);
	    };

	fprintf(wskaznikPlikuIle, "%d \n ", licznikSymboliDodanych);

    fclose(wskaznikPlikuIle);

}

void uzupelnijTabKodu(int numSymbole, struct slowoDlaSymbolu tablicaKodu[], char *nazwaPliku)
{
	int i,j;
	unsigned char Bajty[4];
	FILE *wskaznikPliku=fopen(nazwaPliku,"wb");

    if(wskaznikPliku==NULL)
	{
		printf("Nie mozna utworzyc pliku: %s \n", nazwaPliku);
		exit(EXIT_FAILURE);
	}
    printf("Uzupelniono plik %s zapisem bajtowym\n", nazwaPliku);
    for(i=0; i<numSymbole; ++i)
    {
        for(j=0; j<4; ++j)
        {
           Bajty[j]=tablicaKodu[i].slowo[j];
        }
        printf( " %d %d  %d  %d %d %d \n", tablicaKodu[i].symbol, Bajty[0],Bajty[1],Bajty[2],Bajty[3],tablicaKodu[i].liczbaBitow);
        fprintf(wskaznikPliku, " %d %d  %d  %d %d %d \n", tablicaKodu[i].symbol, Bajty[0],Bajty[1],Bajty[2],Bajty[3],tablicaKodu[i].liczbaBitow);
    }
    fclose(wskaznikPliku);
}

void tabeleKodu()
{
	int numSymbole = dokumentacja.symboleNum;
	int symbol;//aktualnie przetwarzany symbol
    int i,j;
    int parentId, parentSymbol;
    int treeNum;//liczba pozostalych wezlow
    int tabPoz;//id tabeli kodu
    int iloscBit=0;//liczba bitow dla symbolu
    int poz, bajtId, bitId;//informacje bajtu
    unsigned char bajt, jedynka=1;//zmienne pom

    for(i=0;i<512;++i)
    {
        for(j=0;j<4;++j)
        {
           tablicaKoduFull[i].slowo[j]=0;
        }
        tablicaKoduFull[i].symbol=0;
        tablicaKoduFull[i].liczbaBitow=0;
    }
    treeNum=numSymbole-2;
    tabPoz=0;
    tablicaKoduFull[tabPoz].symbol=drzewo[treeNum].parent;

    while(treeNum+1)
    {
        parentSymbol=drzewo[treeNum].parent;
        tablicaKoduFull[tabPoz+1].symbol=drzewo[treeNum].childL;
        tablicaKoduFull[tabPoz+2].symbol=drzewo[treeNum].childR;
        parentId=-1;
        for(i=0; i<tabPoz+1; ++i)
        {
            if((tablicaKoduFull[i].symbol)==(parentSymbol))
            {
                parentId=i;
                break;
            }
        }

        iloscBit=tablicaKoduFull[parentId].liczbaBitow;
        for(i=0;i<4;++i)
        {
            tablicaKoduFull[tabPoz+1].slowo[i]=tablicaKoduFull[parentId].slowo[i];
            tablicaKoduFull[tabPoz+2].slowo[i]=tablicaKoduFull[parentId].slowo[i];
        }

        poz=iloscBit;
        bajtId=poz/8;
        bitId=poz%8;

        jedynka=1;
        jedynka=jedynka<<7-bitId;//przesuniecie bitowe

        bajt=tablicaKoduFull[parentId].slowo[bajtId];
        bajt=bajt|jedynka;

        tablicaKoduFull[tabPoz+1].slowo[bajtId]=bajt;
        tablicaKoduFull[tabPoz+1].liczbaBitow=iloscBit+1;
        tablicaKoduFull[tabPoz+2].liczbaBitow=iloscBit+1;
        tabPoz+=2;
        treeNum--;
    }
    uzupelnijTabKodu (tabPoz+1, tablicaKoduFull, dokumentacja.nazwaPlikuTabelaKoduFull);//zapis do tablicy koduFULL
    //usuwanie symboli dodanych
    tabPoz=0;
    for(i=0;i<256;++i)
    {
        for(j=0;j<4;++j)
        {
           tablicaKodu[i].slowo[j]=0;
        }
        tablicaKodu[i].symbol=0;
        tablicaKodu[i].liczbaBitow=0;
    }
    for(i=0;i<2*numSymbole-1;++i)
    {
        symbol=tablicaKoduFull[i].symbol;
        if(symbol<256)
        {
            tablicaKodu[tabPoz].symbol=symbol;
            tablicaKodu[tabPoz].liczbaBitow=tablicaKoduFull[i].liczbaBitow;
            for(j=0;j<4;++j)
            {
                tablicaKodu[tabPoz].slowo[j]=tablicaKoduFull[i].slowo[j];
            }
            tabPoz++;
        }
    }
    uzupelnijTabKodu(numSymbole,tablicaKodu,dokumentacja.nazwaPlikuTabelaKodu);//zapis do tablicy kodu
}


int main(int argc, char *argv[])
{
    char *nazwaPliku;

    if(argc==2){
        nazwaPliku=argv[1];
    }
	else
    {
        printf("Podano zla liczbe argumentow");
        exit(EXIT_FAILURE);
    }
    bazaNazw(nazwaPliku);
    modelNieSort();
    modelSort();
    printf("GLOWNY WYNIK PROGRAMU\n");
    zrobDrzewo();//2.1
    tabeleKodu();//2.2
	return 0;
}

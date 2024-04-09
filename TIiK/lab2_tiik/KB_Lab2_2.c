#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 216 //rozmiar tablicy bufora
#define kropka 46 //wartosc kropki w kodzie ASCII
#define rozTAB 24 //rozmiar tablic nazw plikow

char plikWejsciowy[rozTAB];
char plikWyjsciowy[rozTAB];
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
//funkcja przepisuje nazwe pliku dla nowych plikow z innymi rozszerzeniami
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

//Struktura DODATKOWYCH WYNIKOW PROGRAMU
struct zrodlo
{
    char nazwaPlikuSource[rozTAB];
    char nazwaPlikuModel[rozTAB];
    char nazwaPlikuModelSort[rozTAB];
    char nazwaPlikuileBajtow[rozTAB];
    char nazwaPlikuDrzewo[rozTAB];
    char nazwaPlikuTabelaKoduFull[rozTAB];
    char nazwaPlikuTabelaKodu[rozTAB];
    char plikWyjsciowy[rozTAB];
    int bajtyNum;
    int symboleNum;
};
struct zrodlo dokumentacja;
//Funkcja uzupelniajaca DODATKOWE WYNIK PROGRAMU
void bazaNazw(char *nazwa)
{
    printf("DODATKOWE WYNIKI PROGRAMU\n");
	char rozModel[]= "model";
    char rozModelSort[]= "modelSort";
    char rozileBajtow[]= "ileBajtow";
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

    noweRozszerzenie(nazwa,rozileBajtow, dokumentacja.nazwaPlikuileBajtow);
    printf("bazaNazw:  %s \n", dokumentacja.nazwaPlikuileBajtow);

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
    FILE *wskaznikIle=fopen(dokumentacja.nazwaPlikuileBajtow,"wb");
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
void modelSort(){
	struct symbolDane pomModel[256];
    int symboleNum=dokumentacja.symboleNum,i,j;
    for( i=0; i<symboleNum; ++i)
        {
            pomModel[i].symbol= modelShannona[i].symbol;
            pomModel[i].ilosc=modelShannona[i].ilosc;
        }

    //bubble sort
    for(i=0;i<symboleNum-1;++i)
    {
        for(j=0;j<symboleNum-i-1;++j)
        {
            if (pomModel[j].ilosc < pomModel[j + 1].ilosc)
            {
                struct symbolDane temp = pomModel[j];
                pomModel[j] = pomModel[j + 1];
                pomModel[j + 1] = temp;
            }
        }
    }

	FILE *wskaznikPliku=fopen(dokumentacja.nazwaPlikuModelSort,"wb");
    if (wskaznikPliku==NULL)
	{
		printf("Nie udalo sie otworzyc pliku .modelSort\n", dokumentacja.nazwaPlikuModelSort);
		exit(EXIT_FAILURE);
	}

    for( i=0; i<symboleNum; ++i)
        {
            modelSortShannon[i].symbol= pomModel[i].symbol;
            modelSortShannon[i].ilosc=pomModel[i].ilosc;
            fprintf(wskaznikPliku, "  %d  %d\n", modelSortShannon[i].symbol, modelSortShannon[i].ilosc);
        }

    fclose(wskaznikPliku);
    printf("Uzupelniono plik .modelSort posortowanym schematem Shannona\n");
}
void zrobDrzewo()
{
int numSymbole = dokumentacja.symboleNum,numSymboleDwa = dokumentacja.symboleNum;
int numSybmoleTrzy = 0;
int i,j,k;
struct symbolDane modelDlaDrzewa[256];
    for(i=0;i<numSymbole; i++)
    {
        modelDlaDrzewa[i].symbol = modelSortShannon[i].symbol;
        modelDlaDrzewa[i].ilosc = modelSortShannon[i].ilosc;
    }
    for(i=0;i<numSymbole-1;i++)
    {
        drzewo[i].parent = 256+i;
        drzewo[i].childL = modelDlaDrzewa[numSymbole-1-i].symbol;
        drzewo[i].childR = modelDlaDrzewa[numSymbole-2-i].symbol;
        modelDlaDrzewa[numSymbole-2-i].symbol = 256+i;
        modelDlaDrzewa[numSymbole-2-i].ilosc = modelDlaDrzewa[numSymbole-1-i].ilosc + modelDlaDrzewa[numSymbole-2-i].ilosc;
        numSymboleDwa--;
        for(j=0;j<numSymboleDwa;++j)
        {
            for(k=0;k<numSymboleDwa-j-1;++k)
            {
                if(modelDlaDrzewa[k].ilosc < modelDlaDrzewa[k+1].ilosc)
                {
                    struct symbolDane temp = modelDlaDrzewa[k];
                    modelDlaDrzewa[k] = modelDlaDrzewa[k + 1];
                    modelDlaDrzewa[k + 1] = temp;
                }
            }
        }
        numSybmoleTrzy++;
     }
    FILE *wskaznikPliku=fopen(dokumentacja.nazwaPlikuDrzewo,"wb");
    if(wskaznikPliku == NULL)
    {
		printf("Nie mozna utworzyc pliku .drzewo \n");
		exit(EXIT_FAILURE);
    }
    printf("Uzupelniono plik .drzewo drzewem Huffmana\n");
    for(i=0;i<numSybmoleTrzy;i++)
    {
        fprintf(wskaznikPliku, " %d %d %d\n", drzewo[i].parent, drzewo[i].childL, drzewo[i].childR );
    }
    fclose(wskaznikPliku);
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
        printf("Podano zla liczbe argumentow, podaj L1.txt");
        exit(EXIT_FAILURE);
    }
    bazaNazw(nazwaPliku);
    modelNieSort();
    modelSort();
    zrobDrzewo();
    printf("GLOWNY WYNIK PROGRAMU\n");
    tabeleKodu();
	return 0;
}

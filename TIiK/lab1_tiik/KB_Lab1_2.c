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

int main(int argc, char *argv[])
{
    char *nazwaPliku;
    unsigned char buforIn[BUFSIZE];
    int i=0,id=0, symboleNum=0, rozLinii=0, bajtyNumMain=0,j=0;

    if(argc==2){
        nazwaPliku=argv[1];
    }
	else
    {
        printf("Podano zla liczbe argumentow, podaj L1.txt");
        exit(EXIT_FAILURE);
    }
    bazaNazw(nazwaPliku);
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



	struct symbolDane pomModel[256];
    symboleNum=dokumentacja.symboleNum;
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

    printf("GLOWNY WYNIK PROGRAMU\n");
    for( i=0; i<symboleNum; ++i)
        {
            modelSortShannon[i].symbol= pomModel[i].symbol;
            modelSortShannon[i].ilosc=pomModel[i].ilosc;
            fprintf(wskaznikPliku, "  %d  %d\n", modelSortShannon[i].symbol, modelSortShannon[i].ilosc);
            printf("Wartosc ASCII %d ilosc %d\n", pomModel[i].symbol, pomModel[i].ilosc);
        }

    fclose(wskaznikPliku);
    printf("Uzupelniono plik .modelSort posortowanym schematem Shannona\n");

	return 0;
}

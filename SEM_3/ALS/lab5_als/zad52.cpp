//================================================
//Zadanie 5_02 jezyk C++
//Symulacja laczenia rozmow telefonicznych
//WCY21IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Klient
{
    char kod_klienta;
    int numer_klienta;
    int czas_rozmowy;
    Klient* nastepny;
};

struct Infolinia1
{
    int aktualny_rozmowca;
    int pozostaly_czas;
    Infolinia1* nastepny_rozmowca;
};
struct Infolinia2
{
    int aktualny_rozmowca;
    int pozostaly_czas;
    Infolinia2* nastepny_rozmowca;
};
struct Infolinia3
{
    int aktualny_rozmowca;
    int pozostaly_czas;
    Infolinia3* nastepny_rozmowca;
};

int main()
{
    ifstream we;
    we.open("we.txt");
    ofstream wy;
    wy.open("wy.txt");
    //deklaracja kolejek dla klientow o rozych priorytetach
    Klient* Phead = NULL;
    Klient* Ghead = NULL;
    Klient* Shead = NULL;

    Klient* Pcurr = NULL;
    Klient* Gcurr = NULL;
    Klient* Scurr = NULL;

    //utworzenie kolejek
    char kod;
    int numer;
    int czas;
    while (we>>kod>>numer>>czas)
    {
        if(kod=='P')//wypelnianie kolejki PLATINIUM
        {
        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = kod;
        nowy->numer_klienta = numer;
        nowy->czas_rozmowy = czas;
        nowy->nastepny = NULL;

        if(Phead == NULL)
		{
            Phead = nowy;
            Pcurr = nowy;
        }
		else
		{
            Pcurr->nastepny = nowy;
            Pcurr = nowy;
        }
        }

        if(kod=='G')//wypelnianie kolejki GOLD
        {

        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = kod;
        nowy->numer_klienta = numer;
        nowy->czas_rozmowy = czas;
        nowy->nastepny = NULL;

        if(Ghead == NULL)
		{
            Ghead = nowy;
            Gcurr = nowy;
        }
		else
		{
            Gcurr->nastepny = nowy;
            Gcurr = nowy;
        }
        }
        if(kod=='S')//wypelnianie kolejki SILVER
        {

        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = kod;
        nowy->numer_klienta = numer;
        nowy->czas_rozmowy = czas;
        nowy->nastepny = NULL;

        if(Shead == NULL)
		{
            Shead = nowy;
            Scurr = nowy;
        }
		else
		{
            Scurr->nastepny = nowy;
            Scurr = nowy;
        }
        }
    }
    //Polaczenie kolejek w jedna, z klientami P na czele i S na koncu
    Klient* head = NULL;
    Klient* curr = NULL;

    Pcurr = Phead;//dodanie kolejki P
    while(Pcurr != NULL)
    {
        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = Pcurr->kod_klienta;
        nowy->numer_klienta = Pcurr->numer_klienta;
        nowy->czas_rozmowy = Pcurr->czas_rozmowy;
        nowy->nastepny = NULL;

        if(head == NULL)
		{
            head = nowy;
            curr = nowy;
        }
		else
		{
            curr->nastepny = nowy;
            curr = nowy;
        }
        Pcurr = Pcurr->nastepny;
    }
    Gcurr = Ghead;//dodanie kolejki G
    while(Gcurr != NULL)
    {
        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = Gcurr->kod_klienta;
        nowy->numer_klienta = Gcurr->numer_klienta;
        nowy->czas_rozmowy = Gcurr->czas_rozmowy;
        nowy->nastepny = NULL;

        if(head == NULL)
		{
            head = nowy;
            curr = nowy;
        }
		else
		{
            curr->nastepny = nowy;
            curr = nowy;
        }
        Gcurr = Gcurr->nastepny;
    }
    Scurr = Shead;//dodanie kolejki S
    while(Scurr != NULL)
    {
        Klient* nowy = (Klient*)malloc(sizeof(Klient));
        nowy->kod_klienta = Scurr->kod_klienta;
        nowy->numer_klienta = Scurr->numer_klienta;
        nowy->czas_rozmowy = Scurr->czas_rozmowy;
        nowy->nastepny = NULL;

        if(head == NULL)
		{
            head = nowy;
            curr = nowy;
        }
		else
		{
            curr->nastepny = nowy;
            curr = nowy;
        }
        Scurr = Scurr->nastepny;
    }

    //deklaracja linitelefonicznych
    Infolinia1* head1 = NULL;
    Infolinia2* head2 = NULL;
    Infolinia3* head3 = NULL;

    Infolinia1* curr1 = NULL;
    Infolinia2* curr2 = NULL;
    Infolinia3* curr3 = NULL;

    //Polaczenie pierwszych trzech klientow do kazdej z lini
    curr = head;
        //pierwszy klient pierwszej infolini
        Infolinia1* nowy = (Infolinia1*)malloc(sizeof(Infolinia1));
        nowy->aktualny_rozmowca = curr->numer_klienta;
        nowy->pozostaly_czas = curr->czas_rozmowy;
        nowy->nastepny_rozmowca = NULL;

            head1 = nowy;
            curr1 = nowy;

        curr = curr->nastepny;
        //pierwszy klient drugiej infolini
        Infolinia2* nowy2 = (Infolinia2*)malloc(sizeof(Infolinia2));
        nowy2->aktualny_rozmowca = curr->numer_klienta;
        nowy2->pozostaly_czas = curr->czas_rozmowy;
        nowy2->nastepny_rozmowca = NULL;

            head2 = nowy2;
            curr2 = nowy2;

        curr = curr->nastepny;
        //pierwszy klient trzeciej infolini
        Infolinia3* nowy3 = (Infolinia3*)malloc(sizeof(Infolinia3));
        nowy3->aktualny_rozmowca = curr->numer_klienta;
        nowy3->pozostaly_czas = curr->czas_rozmowy;
        nowy3->nastepny_rozmowca = NULL;

            head3 = nowy3;
            curr3 = nowy3;

        curr = curr->nastepny;

        int min_czas;
        while(curr != NULL)
        {
            //sprawdzenie kto pierwszy zejdzie z linii
            if( (curr1->pozostaly_czas <= curr2->pozostaly_czas)  && (curr1->pozostaly_czas <= curr3->pozostaly_czas) ) min_czas=curr1->pozostaly_czas;
            if( (curr2->pozostaly_czas<=curr1->pozostaly_czas)  && (curr2->pozostaly_czas<=curr3->pozostaly_czas) ) min_czas=curr2->pozostaly_czas;
            if( (curr3->pozostaly_czas<=curr1->pozostaly_czas)  && (curr3->pozostaly_czas<=curr2->pozostaly_czas) ) min_czas=curr3->pozostaly_czas;

            //wejscie na linie kolejnego klienta
            if(curr1->pozostaly_czas==min_czas)
            {
                Infolinia1* nowy3 = (Infolinia1*)malloc(sizeof(Infolinia1));
                nowy3->aktualny_rozmowca = curr->numer_klienta;
                nowy3->pozostaly_czas = curr->czas_rozmowy;
                nowy3->nastepny_rozmowca = NULL;

                curr1->nastepny_rozmowca = nowy3;
                curr1 = nowy3;

                curr3->pozostaly_czas = curr3->pozostaly_czas - min_czas;
                curr2->pozostaly_czas = curr2->pozostaly_czas - min_czas;
            }
            if(curr3->pozostaly_czas==min_czas)
            {
                Infolinia3* nowy3 = (Infolinia3*)malloc(sizeof(Infolinia3));
                nowy3->aktualny_rozmowca = curr->numer_klienta;
                nowy3->pozostaly_czas = curr->czas_rozmowy;
                nowy3->nastepny_rozmowca = NULL;

                curr3->nastepny_rozmowca = nowy3;
                curr3 = nowy3;

                curr1->pozostaly_czas = curr1->pozostaly_czas - min_czas;
                curr2->pozostaly_czas = curr2->pozostaly_czas - min_czas;
            }
            if(curr2->pozostaly_czas==min_czas)
            {
                Infolinia2* nowy3 = (Infolinia2*)malloc(sizeof(Infolinia2));
                nowy3->aktualny_rozmowca = curr->numer_klienta;
                nowy3->pozostaly_czas = curr->czas_rozmowy;
                nowy3->nastepny_rozmowca = NULL;

                curr2->nastepny_rozmowca = nowy3;
                curr2 = nowy3;

                curr3->pozostaly_czas = curr3->pozostaly_czas - min_czas;
                curr1->pozostaly_czas = curr1->pozostaly_czas - min_czas;
            }
            curr = curr->nastepny;
        }

    cout<<"Uzytkownicy na linii 1"<<endl;
    wy<<"Uzytkownicy na linii 1"<<endl;
    curr1 = head1;
    while(curr1 != NULL)
    {
        cout <<curr1->aktualny_rozmowca<<endl;
        wy <<curr1->aktualny_rozmowca<<endl;
        curr1 = curr1->nastepny_rozmowca;
    }
    cout<<endl;
    wy<<endl;

    cout<<"Uzytkownicy na linii 2"<<endl;
    wy<<"Uzytkownicy na linii 2"<<endl;
    curr2 = head2;
    while(curr2 != NULL)
    {
        cout <<curr2->aktualny_rozmowca<<endl;
        wy <<curr2->aktualny_rozmowca<<endl;
        curr2 = curr2->nastepny_rozmowca;
    }
    cout<<endl;
    wy<<endl;

    cout<<"Uzytkownicy na linii 3"<<endl;
    wy<<"Uzytkownicy na linii 3"<<endl;
    curr3 = head3;
    while(curr3 != NULL)
    {
        cout <<curr3->aktualny_rozmowca<<endl;
        wy <<curr3->aktualny_rozmowca<<endl;
        curr3 = curr3->nastepny_rozmowca;
    }
    cout<<endl;
    wy<<endl;

    //zwalnianie pamieci

    Pcurr= Phead;
    while(Pcurr != NULL)
    {
        Klient* pom = Pcurr;
        Pcurr = Pcurr->nastepny;
        free(pom);//zwolniamy pammiec
    }
    Gcurr= Ghead;
    while(Gcurr != NULL)
    {
        Klient* pom = Gcurr;
        Gcurr = Gcurr->nastepny;
        free(pom);//zwolniamy pammiec
    }
    Scurr= Shead;
    while(Scurr != NULL)
    {
        Klient* pom = Scurr;
        Scurr = Scurr->nastepny;
        free(pom);//zwolniamy pammiec
    }
    curr= head;
    while(curr != NULL)
    {
        Klient* pom = curr;
        curr = curr->nastepny;
        free(pom);//zwolniamy pammiec
    }
    curr1= head1;
    while(curr1 != NULL)
    {
        Infolinia1* pom = curr1;
        curr1 = curr1->nastepny_rozmowca;
        free(pom);//zwolniamy pammiec
    }
    curr2= head2;
    while(curr2 != NULL)
    {
        Infolinia2* pom = curr2;
        curr2 = curr2->nastepny_rozmowca;
        free(pom);//zwolniamy pammiec
    }
    curr3= head3;
    while(curr3 != NULL)
    {
        Infolinia3* pom = curr3;
        curr3 = curr3->nastepny_rozmowca;
        free(pom);//zwolniamy pammiec
    }
    we.close();
    wy.close();
    return 0;
}

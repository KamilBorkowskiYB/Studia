//================================================
//Zadanie 4_02 jezyk C++
//Dodawanie duzych lich przy wykorzystaniu stosu
//WCY21IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <cstdlib>
using namespace std;

struct val_POM
{
    int value;
    val_POM* prev;
};
struct val_ONE
{
    int value;
    val_ONE* prev;
};
struct val_TWO
{
    int value;
    val_TWO* prev;
};
struct val_THREE
{
    int value;
    val_THREE* prev;
};

int main()
{
int n1,n2,n3,over=0;
cout<<"Podaj pierwsza liczbe dodawania"<<endl;
cin>>n1;
cout<<"Podaj druga liczbe dodawania"<<endl;
cin>>n2;

//umieszczanie cyfr pierwszej liczby na stosie pomocniczym(w odwrotnej kolejnosci niz chciana)
    val_POM* head = NULL; //pierwszy element listy pomocniczej, poczatkowo pusty
    val_POM* current = head; //pomocniczy element listy, sluzacy do poruszania sie po liscie
    current = head;
    while(n1>0)
    {
        val_POM* new_node = (val_POM*)malloc(sizeof(val_POM));
        new_node->value = n1%10;
        n1=n1/10;
        new_node->prev = head;
        head = new_node;
    }
//wpisanie liczb z stosu pom do val_one (pierwszy element stosu pomocniczego bedzie ostatnim elementem stosu val_one)
    current = head;
    val_ONE* head1 = NULL; //pierwszy element listy dla pierwszej liczby, poczatkowo pusty
    val_ONE* current1 = head1; //pomocniczy element listy, sluzacy do poruszania sie po liscie
    current1 = head1;
    while(current)
    {
        val_ONE* new_node = (val_ONE*)malloc(sizeof(val_ONE));
        new_node->value=current->value;
        new_node->prev = head1;
        head1 = new_node;
        current = current->prev;
    }
    cout<<"Stos pierwszy - od lewej gora stosu:"<<endl;
    current1 = head1;
    while(current1 != NULL)
    {
        cout << current1->value<<'\t';
        current1 = current1->prev;
    }
    cout<<endl;
//zwalniamy pamiec stosu pomocniczego
    current = head;
    while(current != NULL)
    {
        val_POM* pom = current;
        current = current->prev;
        free(pom);
    }
//umieszczanie cyfr drugiej liczby na stosie pomocniczym(w odwrotnej kolejnosci niz chciana)
    head = NULL; //pierwszy element listy pomocniczej, poczatkowo pusty
    current = head; //pomocniczy element listy, sluzacy do poruszania sie po liscie
    while(n2>0)
    {
        val_POM* new_node = (val_POM*)malloc(sizeof(val_POM));
        new_node->value = n2%10;
        n2=n2/10;
        new_node->prev = head;
        head = new_node;
    }

//wpisanie liczb z stosu pom do val_two (pierwszy element stosu pomocniczego bedzie ostatnim elementem stosu val_two)
    current = head;

    val_TWO* head2 = NULL; //pierwszy element listy dla drugiej liczby, poczatkowo pusty
    val_TWO* current2 = head2; //pomocniczy element listy, sluzacy do poruszania sie po liscie
    current2 = head2;
    while(current)
    {
        val_TWO* new_node = (val_TWO*)malloc(sizeof(val_TWO));
        new_node->value=current->value;
        new_node->prev = head2;
        head2 = new_node;
        current = current->prev;
    }
    cout<<"Stos drugi - od lewej gora stosu"<<endl;
    current2 = head2;
    while(current2 != NULL)
    {
        cout << current2->value<<'\t';
        current2 = current2->prev;
    }
    cout<<endl;

//uzupelnianie stosu sumy
    val_THREE* head3 = NULL; //pierwszy element listy, poczatkowo pusty
    val_THREE* current3 = head3; //pomocniczy element listy, sluzacy do poruszania sie po liscie
    current1 = head1;
    current2 = head2;
    while((current1)||(current2)||over)
    {
        val_THREE* new_node = (val_THREE*)malloc(sizeof(val_THREE));

        new_node->value = ((current1 ? current1->value : 0) + (current2 ? current2->value : 0)+over)%10;//jezeli skonczy nam sie jeden stos to dodajemy 0
        if ((current1 ? current1->value : 0) + (current2 ? current2->value : 0)+over >= 10) over = 1;//jezeli dodawanie da wiecej niz 9 to w nastepnym sumowaniu dodamy +1
        else over=0;
        new_node->prev = head3;
        head3 = new_node;
        if (current1) current1 = current1->prev;
        if (current2) current2 = current2->prev;
    }
    cout<<"Wynik dodawania: "<<endl;
    current3 = head3;
    while(current3 != NULL)
    {
        cout << current3->value;
        current3 = current3->prev;
    }
//=========czyszczenie pamieci================
    current = head;
    while(current != NULL)
    {
        val_POM* pom = current;
        current = current->prev;
        free(pom);//zwolniamy pammiec
    }
    current1 = head1;
    while(current1 != NULL)
    {
        val_ONE* pom = current1;
        current1 = current1->prev;
        free(pom);//zwolniamy pammiec
    }
    current2 = head2;
    while(current2 != NULL)
    {
        val_TWO* pom = current2;
        current2 = current2->prev;
        free(pom);//zwolniamy pammiec
    }
    current3 = head3;
    while(current3 != NULL)
    {
        val_THREE* pom = current3;
        current3 = current3->prev;
        free(pom);//zwolniamy pammiec
    }
return 0;
}

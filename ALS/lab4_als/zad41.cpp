//================================================
//Zadanie 4_01 jezyk C++
//ONP
//WCY21IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <string>
using namespace std;

// Struktura reprezentująca stos operacji
struct ElementStosu
{
    char wartosc;
    ElementStosu* nastepny;
};
// Struktura reprezentująca stos wyjścia (postfiks)
struct Wyjscie
{
    char wartosc;
    Wyjscie* nastepny;
};

// Funkcja pomocnicza do dodawania elementu na stos operacji
void push(ElementStosu*& head, char wartosc)
{
    ElementStosu* nowy_element = (ElementStosu*)malloc(sizeof(ElementStosu));
    nowy_element->wartosc = wartosc;
    nowy_element->nastepny = head;
    head = nowy_element;
}
// Funkcja pomocnicza do usuwania elementu ze stosu operacji
void pop(ElementStosu*& head)
{
    if (head == NULL)return;
    ElementStosu* temp = head;
    head = head->nastepny;
    free(temp);
}
// Funkcja do zwracania wartości najwyższego elementu na stosie operacji
char top(ElementStosu* head)
{
    if (head == NULL)return 0;
    return head->wartosc;
}
// Funkcja do dodawania elementu na stos wyjścia
void push(Wyjscie*& head, char wartosc)
{
    Wyjscie* nowy_element = (Wyjscie*)malloc(sizeof(Wyjscie));
    nowy_element->wartosc = wartosc;
    nowy_element->nastepny = head;
    head = nowy_element;
}
// Funkcja do usuwania elementu ze stosu wyjścia
void pop(Wyjscie*& head)
{
    if (head == NULL)return;
    Wyjscie* temp = head;
    head = head->nastepny;
    free(temp);
}
// Funkcja do zwracania wartości najwyższego elementu na stosie wyjścia
char top(Wyjscie* head)
{
    if (head == NULL)return 0;
    return head->wartosc;
}
// Funkcja do wyświetlania zawartości stosu wyjscia
// Stos wyjscia przechowuje elementy w odwrotnej kolejnosci niz chciana, wiec przekladamy elementy do pomocniczego stosu
void wyswietlStos(Wyjscie* head)
{
    Wyjscie* temp = head;
    Wyjscie* odwroconyStos = NULL;
    // Odwracamy stos
    while (temp != NULL)
    {
        push(odwroconyStos, top(temp));// Wkladamy wierzchni element stosu wyjscia do stosu odwroconego
        pop(temp);
    }
    // Wyświetlamy odwrócony stos
    while (odwroconyStos != NULL)
    {
        cout << top(odwroconyStos);
        push(temp, top(odwroconyStos));// Wyswietlamy elementy stosu odwroconego
        pop(odwroconyStos);
    }
    cout << endl;
}

int main()
{
    cout << "Podaj wyrazenie matematyczne w postaci infiksowej: ";
    string wyrazenie_infiksowe;
    getline(cin, wyrazenie_infiksowe);

    Wyjscie* stos_wyjscia = NULL; // Inicjalizacja stosu wyjścia
    ElementStosu* stos_operacji = NULL;//Inicjalizacja stosu operacji

    for(char znak:wyrazenie_infiksowe)
    {
        if( (znak != '(') && (znak != ')') && (znak != '+') && (znak != '-') && (znak != '*') && (znak != '/'))//Jezeli znak nie jest operandem uznajemy go za stala lub nazwe zmiennej
        {
            push(stos_wyjscia, znak); //stale i nazwy zmiennych przesylamy na stos wyjscia
        }
        else if(znak == '(')
        {
            push(stos_operacji, znak); // ( dopisujemy na stos operacji
        }
        else if(znak == ')')
        {
            while(top(stos_operacji) != 0 && top(stos_operacji) != '(') // przesylamy wszystkie operandy na stos wyjscia az do (
            {
                push(stos_wyjscia, top(stos_operacji));
                pop(stos_operacji);
            }
            pop(stos_operacji);  // usuwamy otwierający nawias ze stosu operacji
        }
        else // Jeśli znak jest operatorem dodajemy go do stosu wyjscia
        {
            while(top(stos_operacji) != 0 && top(stos_operacji) != '(' && ((znak == '+' || znak == '-') && (top(stos_operacji) == '*' || top(stos_operacji) == '/')))
            {
                push(stos_wyjscia, top(stos_operacji));
                pop(stos_operacji);
            }
            push(stos_operacji, znak);
        }
    }
    while(top(stos_operacji))// przenosimy pozostale operatory na stos wyjscia
    {
        push(stos_wyjscia, top(stos_operacji));
        pop(stos_operacji);
    }

    //wyświetlamy zawartość stosu wyjścia
    cout << "Postac postfiksowa: ";
    wyswietlStos(stos_wyjscia);

    return 0;
}

//================================================
//Zadanie 5_01 jezyk C++
//Wieza Hanoi
//WCY21IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct wieza
{
    int k;
    wieza* prev;
};

void printTowerToFile(wieza* head, ofstream& file)
{
    wieza* current = head;
    while (current != NULL)
    {
        file << current->k << '\t';
        cout << current->k << '\t';
        current = current->prev;
    }
    file << endl;
    cout<< endl;
}

void przenies_krazek(wieza*& OD, wieza*& DO, wieza*& Ahead, wieza*& Bhead, wieza*& Chead, ofstream& file)
{
    wieza* temp = OD;
    OD = OD->prev;
    temp->prev = DO;
    DO = temp;

    // Dodatkowy kod do wypisywania stanu wiez po przeniesieniu krazka
    cout << "Wieza A" << endl;
    file << "Wieza A" << endl;
    printTowerToFile(Ahead, file);
    cout << "Wieza B" << endl;
    file << "Wieza B" << endl;
    printTowerToFile(Bhead, file);
    cout << "Wieza C" << endl;
    file << "Wieza C" << endl;
    printTowerToFile(Chead, file);
    cout << "-----------------------------------------" << endl;
    file << "-----------------------------------------" << endl;
}

void hanoi(int n, wieza*& OD, wieza*& PRZEZ, wieza*& DO, wieza*& Ahead, wieza*& Bhead, wieza*& Chead, ofstream& file)
{
    if (n == 1)
    {
        przenies_krazek(OD, DO, Ahead, Bhead, Chead, file);
        return;
    }
    hanoi(n - 1, OD, DO, PRZEZ, Ahead, Bhead, Chead, file);
    przenies_krazek(OD, DO, Ahead, Bhead, Chead, file);
    hanoi(n - 1, PRZEZ, OD, DO, Ahead, Bhead, Chead, file);
}

int main()
{
    int n, i;
    cout << "Podaj ilosc krazkow:" << endl;
    cin >> n;
    ofstream wy("wy.txt");

    wieza* Ahead = NULL; // deklaracja 3 wiez
    wieza* Bhead = NULL;
    wieza* Chead = NULL;

    i = n; // umieszczanie n krazkow na stosie A
    while (i > 0)
    {
        wieza* krazek = (wieza*)malloc(sizeof(wieza));
        krazek->k = i;
        i--;
        krazek->prev = Ahead;
        Ahead = krazek;
    }

    cout << "Poczatkowy stan wiez z krazkami" << endl;
    wy << "Poczatkowy stan wiez z krazkami" << endl;
    cout << "Wieza A" << endl;
    wy << "Wieza A" << endl;
    printTowerToFile(Ahead, wy);
    cout << "Wieza B" << endl;
    wy << "Wieza B" << endl;
    printTowerToFile(Bhead, wy);
    cout << "Wieza C" << endl;
    wy << "Wieza C" << endl;
    printTowerToFile(Chead, wy);
    wy << "===============================" << endl;
    cout << "===============================" << endl;

    hanoi(n, Ahead, Bhead, Chead, Ahead, Bhead, Chead, wy);

    cout << "Koncowy stan wiez z krazkami" << endl;
    wy << "Koncowy stan wiez z krazkami" << endl;
    cout << "Wieza A" << endl;
    wy << "Wieza A" << endl;
    printTowerToFile(Ahead, wy);
    cout << "Wieza B" << endl;
    wy << "Wieza B" << endl;
    printTowerToFile(Bhead, wy);
    cout << "Wieza C" << endl;
    wy << "Wieza C" << endl;
    printTowerToFile(Chead, wy);

    wy.close();
    return 0;
}


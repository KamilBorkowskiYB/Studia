//=========================================
//          Algorytmy i Struktury Danych
// Zadnie 1_01
//Zadanie z Silnia
//WCY22IY1S1 Kamil Borkowksi
//
//=========================================

#include <iostream>
using namespace std;

int silnia_iteracyjnie(int n)
{
    int pom=1;
    for(int i=1;i<=n;i++)
    {
        pom=pom*i;
    }
    return pom;
}
int silnia_rekurencyjnie(int n)
{
    if(n==1)return 1;
    return n*silnia_rekurencyjnie(n-1);
}
int main()
{
int n;
cin>>n;
cout<<silnia_iteracyjnie(n)<<endl;
cout<<silnia_rekurencyjnie(n)<<endl;
return 0;
}

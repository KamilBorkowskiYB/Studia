//=========================================
//          Algorytmy i Struktury Danych
// Zadnie 1_02
//Zadanie z Fibbonacci
//WCY22IY1S1 Kamil Borkowksi
//
//=========================================
#include <iostream>
using namespace std;

int fibbo_iteracyjnie(int n)
{
    if(n<=2)return 1;
    int pom;
    int f1=1;
    int f2=1;
    for(int i=3;i<=n;i++)
    {
    pom=f1+f2;
    f1=f2;
    f2=pom;
    }
    return pom;
}
int fibbo_rekurencyjnie(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    return fibbo_rekurencyjnie(n-1)+fibbo_rekurencyjnie(n-2);
}
int main()
{
int n;
cin>>n;
cout<<fibbo_iteracyjnie(n)<<endl;
cout<<fibbo_rekurencyjnie(n)<<endl;
return 0;
}

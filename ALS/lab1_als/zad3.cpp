//=========================================
//          Algorytmy i Struktury Danych
// Zadnie 1_03
//Zadanie z Wielomianem
//WCY22IY1S1 Kamil Borkowksi
//
//=========================================
#include <iostream>
using namespace std;

int wielomian_klasycznie(int a2,int a1,int a0,int n)
{
int pom=0;
pom=pom+a0;
pom=pom+a1*n;
pom=pom+a2*n*n;
return pom;
}
int wielomian_horner(int a2,int a1,int a0,int n)
{
int pom;
pom=a2*n+a1;
pom=pom*n+a0;
return pom;
}

int main()
{
int a2,a1,a0,n;
cin >>a2>>a1>>a0>>n;
cout<<wielomian_klasycznie(a2,a1,a0,n)<<endl;
cout<<wielomian_horner(a2,a1,a0,n)<<endl;
return 0;
}

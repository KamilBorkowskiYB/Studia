//=========================================
//          Algorytmy i Struktury Danych
// Zadnie 1_05
//Zadanie z Wektorem
//WCY22IY1S1 Kamil Borkowksi
//
//=========================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

int n,mini,maks;
cin>>n;
int* V = new int[n];
srand(time(NULL));
for(int i=0;i<n;i++)
{
    V[i]=(rand()%6)+1;
    cout << V[i] << "\n";
}
mini = V[0];
maks = V[0];
for(int i=1;i<n;i++)
{
   if(mini>V[i])mini=V[i];
   if(maks<V[i])maks=V[i];
}
cout<<"minimalna wartosc: "<<mini<<endl;
cout<<"maksymalna wartosc: "<<maks<<endl;
return 0;
}


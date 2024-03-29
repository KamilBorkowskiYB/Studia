//=========================================
//          Algorytmy i Struktury Danych
// Zadnie 1_04
//Zadanie z Mno¿eniem macierzy
//WCY22IY1S1 Kamil Borkowksi
//
//=========================================
#include <iostream>
using namespace std;

int main()
{
int NM[3][3] = {1,2,3,4,5,6,7,8,9};
int MK[3][3] = {1,2,3,4,5,6,7,8,9};
int W[3][3];
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        W[i][j]=NM[i][0]*MK[0][j]+NM[i][1]*MK[1][j]+NM[i][2]*MK[2][j];
        cout<<W[i][j]<<'\t';
    }
    cout<<endl;
}
return 0;
}


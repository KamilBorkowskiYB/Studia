//================================================
//Zadanie 9_02 jezyk C++
//Library Sort
//WCY22IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
//funkcja przesuwajaca elementy tablicy
void shiftElements(int arr[], int start, int end) {
    for (int i = end; i > start; --i) {//przesuwanie od start do end wlacznie
        arr[i] = arr[i - 1];
    }
}

void librarySort(int arr[], int n) {
    int* shelves = (int*)malloc(n * sizeof(int));
    int shelvesSize = 0;

    for (int i = 0; i < n; ++i) {
        int current = arr[i];

        int j = 0;//szukanie miejsca na polce dla elementu
        while (j < shelvesSize && shelves[j] <= current) {
            ++j;
        }
        shiftElements(shelves, j, shelvesSize);//dodawanie pustych miejsc
        shelvesSize++;

        shelves[j] = current;//wstawianie elementu na polce
    }
    //przepisanie posortowanych elementow z polki do oryginalnej tablicy
    int sortedIndex = 0;
    for (int i = 0; i < shelvesSize; ++i) {
        if (shelves[i] == 0) {//obsluga pustych miejsc
            sortedIndex++;
        } else {
            arr[sortedIndex++] = shelves[i];//wstawianie elementu z polki do tablicy
        }
    }
    free(shelves);
}

int main()
{
    srand((time(0)));
    int arr[10000] = {};
    int i,k=0,n,g,d,w;

    int pom=1,z;//pom oblusguje interfejs, z= nr komendy z interfejsu
    cout << "WCY22IY1S1 Borkowski Kamil" << endl;
    cout << "Program sortowania Library Sort" << endl;
    cout << "[0] - wyjscie z programu" << endl;
    cout << "[1] - wczytaj dane z pliku(we.txt)" << endl;
    cout << "[2] - wczytaj dane z generatora" << endl;
    cout << "[3] - wczytaj dane z klawiatury" << endl;
    cout << "=========================================" << endl;

        while(pom){
        cout << "Wprowadz nr operacji: ";
        cin >> z;
        switch (z){
        case 0:
                cout<<"Wychodzenie..."<<endl;
                pom = 0;
                break;
        case 1:
            {
                k=0;
                ifstream in;
                in.open("we.txt");
                int p;
                i=0;
                while(in>>p)
                {
                arr[i]=p;
                i++;
                }
                n=i;
                cout<<"Tablica zostala usupelniona danymi z pliku we.txt"<<endl<<endl;
                cout <<"Przed sortowaniem metoda library sort: "<<endl;;
                for( i=0;i<n;i++)
                {
                    cout<<arr[i]<<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                librarySort(arr,n);
                k=0;
                cout<<endl<<"Po sortowaniu metoda library sort: "<<endl;;
                for (i = 0; i < n; i++) {
                    cout << arr[i] <<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                cout<<endl;
                in.close();
                break;
            }
        case 2:
            {
                k=0;
                cout<<"Podaj ilosc liczb do sortowania"<<endl;
                cin>>n;
                cout<<"Podaj zakres liczb do sortowania"<<endl;
                cout<<"Granica dolna: ";
                cin>>d;
                cout<<"Granica gorna: ";
                cin>>g;
                for (i = 0; i < n; ++i) {
                arr[i]=(rand() % (g-d+1))+d; // liczby od 1 do 100
                }
                cout <<"Przed sortowaniem metoda library sort: "<<endl;;
                for(int i=0;i<n;i++)
                {
                    cout<<arr[i]<<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                librarySort(arr,n);
                k=0;
                cout<<endl<<"Po sortowaniu metoda library sort: "<<endl;;
                for (i = 0; i < n; i++) {
                    cout << arr[i] <<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                cout<<endl;
                break;
            }
        case 3:
            {
                k=0;
                cout<<"Podaj ilosc liczb do sortowania"<<endl;
                cin>>n;
                for(i=0;i<n;i++)
                {
                    w=0;
                    cout<<"Podaj argument: ";
                    cin>>w;
                    arr[i]=w;
                }
                cout <<"Przed sortowaniem metoda library sort: "<<endl;;
                for(int i=0;i<n;i++)
                {
                    cout<<arr[i]<<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                librarySort(arr,n);
                k=0;
                cout<<endl<<"Po sortowaniu metoda library sort: "<<endl;;
                for (i = 0; i < n; i++) {
                    cout << arr[i] <<'\t';
                    k++;
                    if(k==10)
                    {
                        k=0;
                        cout<<endl;
                    }
                }
                cout<<endl;
                break;
            }

        default:
            {
                cout<<"Podano bledny nr operacji"<<endl<<endl;
                break;
            }
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

template<typename T, typename Sort> class Kolekcja{
    protected:
    T tablicaDanych[100];
    Sort rodzajSortowania;
    int rozmiar = 0;//zmienna do sledzenia pozycji najldalszego elementu tablicy

    public:
    virtual void dodaj(T wartosc)=0;
    virtual T zdejmij()=0;
    virtual void posortuj()=0;
    virtual void wydrukuj()=0;
    virtual void oproznij()=0;

};

template<typename T, typename Sort> class LIFO : public Kolekcja<T, Sort>{
    public:
    LIFO(Sort rdzSort)
    {
        this->rodzajSortowania=rdzSort;
    }
    void dodaj(T wartosc)
    {
        if(this->rozmiar<99)
        {
            cout<<"Dodano "<<wartosc<<" do kolejki LIFO"<<endl;
            this->tablicaDanych[this->rozmiar] = wartosc;
            this->rozmiar++;
        }
        else
        {
          cout<<"Osiagnieto maksymalna ilosc elementow tablicy"<<endl;
        }
    }
    void wydrukuj()
    {
        cout<<"Elementy tablicy LIFO:"<<endl;
        if(this->rozmiar==0)
        {
            cout<<"Tablica jest pusta";
        }
        for(int i=0;i<this->rozmiar;i++)
        {
            cout<<this->tablicaDanych[i]<<'\t';
        }
        cout<<endl;
    }
    void posortuj()
    {
        this->rodzajSortowania.posortuj(this->tablicaDanych,this->rozmiar);
    }
    T zdejmij()
    {
        if(this->rozmiar > 0)
        {
            cout<<"Zdjeto element"<<endl;
            this->rozmiar--;
            this->tablicaDanych[this->rozmiar];
        }
        else
        {
            cout<<"Tablica jest pusta"<<endl;
        }
    }
    void oproznij()
    {
        this->rozmiar = 0;
    }
};

template<typename T, typename Sort> class FIFO : public Kolekcja<T, Sort>{
    public:
    FIFO(Sort rdzSort)
    {
        this->rodzajSortowania=rdzSort;
    }
    void dodaj(T wartosc)
    {
        if(this->rozmiar<99)
        {
            cout<<"Dodano "<<wartosc<<" do kolejki FIFO"<<endl;
            this->tablicaDanych[this->rozmiar]=wartosc;
            this->rozmiar++;
        }
        else
        {
            cout<<"Osiagnieto maksymalna ilosc elementow tablicy"<<endl;
        }
    }
    void wydrukuj()
    {
        cout<<"Elementy tablicy FIFO:"<<endl;
        if(this->rozmiar==0)
        {
            cout<<"Tablica jest pusta";
        }
        for(int i=0;i<this->rozmiar;i++)
        {
            cout<<this->tablicaDanych[i]<<'\t';
        }
        cout<<endl;
    }
    void posortuj()
    {
        this->rodzajSortowania.posortuj(this->tablicaDanych,this->rozmiar);
    }
    T zdejmij()
    {
        if(this->rozmiar>0)
        {
            cout<<"Zdjeto element"<<endl;
            for(int i=0;i<this->rozmiar;i++)
            {
                this->tablicaDanych[i] = this->tablicaDanych[i+1];
            }
            this->rozmiar--;
        }
        else
        {
            cout<<"Tablica jest pusta"<<endl;
        }
    }
    void oproznij()
    {
        cout<<"Wyczyszczono tablice!"<<endl;
        for(int i=0;i<this->rozmiar;i++)
        {
            this->tablicaDanych[i]=0;
        }
        this->rozmiar = 0;
    }
};

template<typename T> class Sortowanie{
    public:
    virtual void posortuj(T* tablica, int rozmiar)=0;
};

template<typename T> class SortowanieMalejace : public Sortowanie<T>{
    public:
    void posortuj(T* tab, int size){
        cout<<"Sortowanie malejace!"<<endl;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
             if (tab[j] < tab[j + 1])
                swap(tab[j], tab[j + 1]);
            }
        }
    }
};

template<typename T> class SortowanieRosnace : public Sortowanie<T>{
    public:
    void posortuj(T* tab, int size){
        cout<<"Sortowanie rosnace!"<<endl;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
             if (tab[j] > tab[j + 1])
                swap(tab[j], tab[j + 1]);
            }
        }
    }
};

int main(){
    SortowanieMalejace<double> sDesc;
    SortowanieRosnace<double> sAsc;

    FIFO<double, SortowanieMalejace <double>> fifo(sDesc);
    LIFO<double, SortowanieRosnace <double>> lifo(sAsc);

    fifo.dodaj(7);
    fifo.dodaj(3.5);
    fifo.dodaj(21.37);
    fifo.dodaj(-5);
    fifo.dodaj(2024.01);
    fifo.wydrukuj();

    fifo.zdejmij();
    fifo.wydrukuj();

    fifo.posortuj();
    fifo.wydrukuj();

    fifo.oproznij();
    fifo.wydrukuj();

    cout<<"-----------------------------------------------"<<endl;
    lifo.dodaj(89);
    lifo.dodaj(28.01);
    lifo.dodaj(10.06);
    lifo.dodaj(7);
    lifo.dodaj(42);
    lifo.wydrukuj();

    lifo.zdejmij();
    lifo.wydrukuj();

    lifo.posortuj();
    lifo.wydrukuj();

    for(int i=0;i<5;i++)
    {
        lifo.zdejmij();
    }
    lifo.wydrukuj();

    cout<<"-----------------------------------------------"<<endl;
    SortowanieMalejace<double> ssDesc;
	FIFO<double, SortowanieMalejace <double>> fifo2(ssDesc);

	fifo2.dodaj(1.51);
	fifo2.dodaj (1.65);
	fifo2.dodaj(1.79);
	fifo2.dodaj(1.58);
	fifo2.wydrukuj();
	fifo2.posortuj();
	fifo2.wydrukuj();
	fifo2.zdejmij();
	fifo2.wydrukuj();
	fifo2.zdejmij();
	fifo2.wydrukuj();
	fifo2.dodaj(1.585);
	fifo2.dodaj(1.505);
	fifo2.wydrukuj();
	fifo2.posortuj();
	fifo2.wydrukuj();
	fifo2.oproznij();
	fifo2.wydrukuj();

    return 0;
}

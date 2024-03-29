#include <iostream>
#include <string>
using namespace std;

class Silnik;
class Samochod{
string marka;
string model;
bool czyPrzykreconeKola;
Silnik* silnik;
friend void fn_zamontuj_silnik_w_samochodzie(Silnik* silnik, Samochod* samochod);
public:
    friend class Mechanik;
    Samochod(string mar = "Ford",string mod = "Mustang",bool czyPrzykreconeKola = false, Silnik* sil = NULL)
    {
        this->marka=mar;
        this->model=mod;
        this->czyPrzykreconeKola=czyPrzykreconeKola;
        this->silnik=sil;
    }
};

class Silnik{
string VIN;
double maxPojemnoscOleju;
double aktPojemnoscOleju;
Samochod* samochod;
friend void fn_zamontuj_silnik_w_samochodzie(Silnik* silnik, Samochod* samochod);
public:
    friend class Mechanik;
    Silnik(string VIN="b.d", double maxPojOleju = 6.2, double aktPojOleju = 2.5, Samochod* sam = NULL)
    {
     this->VIN=VIN;
     this->maxPojemnoscOleju=maxPojOleju;
     this->aktPojemnoscOleju=aktPojOleju;
     this->samochod=sam;
    }
};

class Mechanik{
string imie;
string nazwisko;
public:
    void dolejOlejSilnikowy(Silnik* silnik, double pojemnosc)
    {
        if(silnik->aktPojemnoscOleju+pojemnosc>silnik->maxPojemnoscOleju)
        {
            cout<<"Wlano za duzo oleju do: "<<silnik->VIN<<", nadmiar wylano"<<endl;
            silnik->aktPojemnoscOleju=silnik->maxPojemnoscOleju;
        }
        else
        {
            cout<<"Dolano oleju do: "<<silnik->VIN<<endl;
            silnik->aktPojemnoscOleju=silnik->aktPojemnoscOleju+pojemnosc;
        }
        cout<<"Aktualny poziom oleju w "<<silnik->VIN<<": "<<silnik->aktPojemnoscOleju<<endl<<endl;
    }
    void przykrecKola(Samochod* samochod)
    {
        if(samochod->czyPrzykreconeKola)
        {
            cout<<"Kola sa juz przykrecone do: "<<samochod->marka<<endl;
        }
        else
        {
            cout<<"Przykrecono kola do: "<<samochod->marka<<endl;
            samochod->czyPrzykreconeKola=true;
        }
    }
    Mechanik(string imie, string nazwisko)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
    }
};

void fn_zamontuj_silnik_w_samochodzie(Silnik* silnik, Samochod* samochod)
{
    if (samochod->silnik != NULL)
    {
        cout <<"Samochod "<<samochod->marka<<" juz ma silnik" << endl;
        return;
    }
    if (silnik->samochod != NULL) {
        cout <<"Silnik "<<silnik->VIN<<" juz jest zamontowany" << endl;
        return;
    }

    silnik->samochod = samochod;
    samochod->silnik = silnik;

    cout<<"Zamontowano silnik: "<<silnik->VIN<<" w samochodzie: "<<samochod->marka<<endl;
}
int main()
{
    Samochod ford;
    Samochod yaris("Toyota","Yaris",true,NULL);

    Silnik doForda("42");
    Silnik doYarisa("2137",4.0,0.0,NULL);

    Mechanik Janusz("Janusz","Kowal");

    Janusz.przykrecKola(&ford);
    Janusz.przykrecKola(&yaris);

    fn_zamontuj_silnik_w_samochodzie(&doForda,&ford);
    fn_zamontuj_silnik_w_samochodzie(&doYarisa,&yaris);
    fn_zamontuj_silnik_w_samochodzie(&doForda,&ford);


    Janusz.dolejOlejSilnikowy(&doForda,3.0);
    Janusz.dolejOlejSilnikowy(&doForda,3.0);
    Janusz.dolejOlejSilnikowy(&doYarisa,3.0);
    Janusz.dolejOlejSilnikowy(&doYarisa,3.0);

return 0;
}

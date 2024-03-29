#include <iostream>
#include <string>

using namespace std;

class ProduktPapierniczy{
protected:
     string rodzaj;
     string nazwa;
     double cena;
public:
    virtual string getRodzaj()=0;
    virtual string getNazwa()=0;
    virtual double getCena()=0;
    virtual ~ProduktPapierniczy(){}
};

class SklepPapierniczy{
    ProduktPapierniczy* produktyNaStanie[1500];
    int aktualnaLiczbaProdoktow;

public:
    void dodajNaStaN(ProduktPapierniczy* produkt)
    {
        if (aktualnaLiczbaProdoktow < 1500) {
            produktyNaStanie[aktualnaLiczbaProdoktow++] = produkt;
            cout << "Dodano produkt do stanu." << endl;
        } else {
            cout << "Nie mozna dodac wiecej produktow, osiagnieto limit." << endl;
        }
    }

    void zdejmijZeStanu(ProduktPapierniczy* produkt)
    {
        for (int i = 0; i < aktualnaLiczbaProdoktow; ++i) {
            if (produktyNaStanie[i] == produkt) {
                // Przesuwamy elementy w tablicy, aby zape³niæ lukê po usuniêciu produktu.
                for (int j = i; j < aktualnaLiczbaProdoktow - 1; ++j) {
                    produktyNaStanie[j] = produktyNaStanie[j + 1];
                }
                --aktualnaLiczbaProdoktow;
                cout << "Produkt zostal zdjety ze stanu." << endl;
                return;
            }
        }
        cout << "Produkt nie zostal znaleziony na stanie." << endl;
    }

    ProduktPapierniczy* znajdzProdukt(string rodzaj, string nazwa)
    {
        for (int i = 0; i < aktualnaLiczbaProdoktow; ++i) {
            if (produktyNaStanie[i]->getRodzaj() == rodzaj && produktyNaStanie[i]->getNazwa() == nazwa) {
                return produktyNaStanie[i];
            }
        }
        return nullptr; // Zwracamy nullptr, jeœli produkt nie zosta³ znaleziony.
    }

    void wyswietlProdukty()
    {
        cout << "Produkty na stanie sklepu:" << endl;
        for (int i = 0; i < aktualnaLiczbaProdoktow; ++i) {
            cout << "- " << produktyNaStanie[i]->getRodzaj() << " " << produktyNaStanie[i]->getNazwa() << " Cena: " << produktyNaStanie[i]->getCena() << endl;
        }
    }

    SklepPapierniczy()
    {
        aktualnaLiczbaProdoktow = 0;
    }
};

class Pracownik{
    string imie;
    string nazwisko;
    SklepPapierniczy* sklep;

public:
    string getImie()
    {
        return imie;
    }

    string getNazwisko()
    {
        return nazwisko;
    }

    SklepPapierniczy* getSklep()
    {
        return sklep;
    }

    void setSklep(SklepPapierniczy* sklep)
    {
        this->sklep = sklep;
    }

    Pracownik(string imie, string nazwisko, SklepPapierniczy* sklep = nullptr)
        : imie(imie), nazwisko(nazwisko), sklep(sklep)
    {
    }
};

class Sprzedawca : public Pracownik{
public:
    void sprzedajProdukt(string rodzaj, string nazwa)
    {
        ProduktPapierniczy* produkt = getSklep()->znajdzProdukt(rodzaj, nazwa);
        if (produkt != nullptr) {
            getSklep()->zdejmijZeStanu(produkt);
            cout << "Produkt sprzedany: " << produkt->getRodzaj() << " " << produkt->getNazwa() << " Cena: " << produkt->getCena() << endl;
        } else {
            cout << "Produkt nie jest dostepny w sklepie." << endl;
        }
    }

    Sprzedawca(string imie, string nazwisko, SklepPapierniczy* sklep = nullptr)
        : Pracownik(imie, nazwisko, sklep)
    {
    }
};

class Zaopatrzeniowiec : public Pracownik{
    ProduktPapierniczy* produktNaPace[200];
    int aktualnaLiczbaProduktow;

public:
    void zaladujProduktNaPake(ProduktPapierniczy* produkt)
    {
        if (aktualnaLiczbaProduktow < 200) {
            produktNaPace[aktualnaLiczbaProduktow++] = produkt;
            cout << "Produkt zaladowany na paczke." << endl;
        } else {
            cout << "Nie mozna zaladowac wiecej produktow na paczke, osiagnieto limit." << endl;
        }
    }

    void dostarczWszystkieProdukyNaSklep()
    {
        for (int i = 0; i < aktualnaLiczbaProduktow; ++i) {
            getSklep()->dodajNaStaN(produktNaPace[i]);
        }
        cout << "Wszystkie produkty dostarczone do sklepu." << endl;
        aktualnaLiczbaProduktow = 0; // Zerujemy liczbê produktów na paczce.
    }

    Zaopatrzeniowiec(string imie, string nazwisko, SklepPapierniczy* sklep = nullptr)
        : Pracownik(imie, nazwisko, sklep), aktualnaLiczbaProduktow(0)
    {
    }
};
class Koperta : public ProduktPapierniczy{
string format;

public:
    string getRodzaj() override{
        return rodzaj;
    }
    string getNazwa()override{
        return nazwa;
    }
    double getCena()override{
        return cena;
    }
    string getFormat(){
        return format;
    }
    Koperta(string rodzaj,string nazwa,double cena,string format)
    {
        this->rodzaj=rodzaj;
        this->nazwa=nazwa;
        this->cena=cena;
        this->format=format;
    }
};

class Zeszyt : public ProduktPapierniczy{
    int liczbaStron;
public:
    string getRodzaj() override{
        return rodzaj;
    }
    string getNazwa()override{
        return nazwa;
    }
    double getCena()override{
        return cena;
    }
    int getLiczbaStron(){
        return liczbaStron;
    }
    Zeszyt(string rodzaj,string nazwa, double cena, int liczbaStron)
    {
        this->rodzaj=rodzaj;
        this->nazwa=nazwa;
        this->cena=cena;
        this->liczbaStron=liczbaStron;
    }
};

class Kredki :  public ProduktPapierniczy{
int liczbaSztuk;
bool czyDrewniane;

public:
    string getRodzaj() override{
        return rodzaj;
    }
    string getNazwa()override{
        return nazwa;
    }
    double getCena()override{
        return cena;
    }
    int getLiczbaSztuk(){
        return liczbaSztuk;
    }
    bool getCzyDrewniane(){
        return czyDrewniane;
    }
    Kredki(string rodzaj,string nazwa, double cena, int liczbaSztuk,bool czyDrewniane)
    {
        this->rodzaj=rodzaj;
        this->nazwa=nazwa;
        this->cena=cena;
        this->liczbaSztuk=liczbaSztuk;
        this->czyDrewniane=czyDrewniane;
    }
};
int main()
{
    // Tworzymy sklep papierniczy
    SklepPapierniczy sklep;

    // Tworzymy kilka produktów
    Koperta koperta("Koperta", "KopertaJeden", 2.5, "A4");
    Zeszyt zeszyt("Zeszyt", "ZeszytDwa", 5.0, 100);
    Kredki kredki("Kredki", "KredkiTrzy", 8.0, 12, true);

    // Dodajemy produkty do sklepu
    sklep.dodajNaStaN(&koperta);
    sklep.dodajNaStaN(&zeszyt);
    sklep.dodajNaStaN(&kredki);

    // Wyœwietlamy produkty na stanie sklepu
    sklep.wyswietlProdukty();

    // Tworzymy sprzedawcê i przypisujemy mu sklep
    Sprzedawca sprzedawca("Jan", "Kowalski", &sklep);

    // Sprzedajemy produkt, który jest dostêpny w sklepie
    sprzedawca.sprzedajProdukt("Kredki", "KredkiTrzy");

    // Spróbuj ponownie sprzedaæ ten sam produkt (powinien byæ niedostêpny)
    sprzedawca.sprzedajProdukt("Kredki", "KredkiTrzy");

    // Wyœwietlamy ponownie produkty na stanie sklepu
    sklep.wyswietlProdukty();

    // Tworzymy zaopatrzeniowca i przypisujemy mu sklep
    Zaopatrzeniowiec zaopatrzeniowiec("Anna", "Nowak", &sklep);

    // £adujemy produkt na paczkê
    zaopatrzeniowiec.zaladujProduktNaPake(&koperta);

    // Dostarczamy wszystkie produkty na sklep
    zaopatrzeniowiec.dostarczWszystkieProdukyNaSklep();

    // Wyœwietlamy produkty na stanie sklepu po dostawie
    sklep.wyswietlProdukty();

    sprzedawca.sprzedajProdukt("Koperta", "KopertaJeden");
    sklep.wyswietlProdukty();
    return 0;
}

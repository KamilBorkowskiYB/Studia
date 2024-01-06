#include <iostream>
using namespace std;

class WezelListy {
public:
    string imieStudenta;
    string nazwiskoStudenta;
    double sredniaOcenStudenta;
    char plecStudenta;
    WezelListy* wskNastepny;
    WezelListy* wskPoprzedni;

    WezelListy(string imStudenta, string nzStudenta, double srOcStudenta, char plStudenta) {
        this->imieStudenta = imStudenta;
        this->nazwiskoStudenta = nzStudenta;
        this->sredniaOcenStudenta = srOcStudenta;
        this->plecStudenta = plStudenta;
        wskNastepny = NULL;
        wskPoprzedni = NULL;
    }
};

class ListaStudentow {
public:
    WezelListy* glowa;
    WezelListy* ogon;
    int aktualnaDlugoscListy;

    ListaStudentow() {
        this->glowa = NULL;
        this->ogon = NULL;
        this->aktualnaDlugoscListy = 0;
    }

    void dodajNowegoStudentaNaKoniecListy(string imStudenta, string nzStudenta, double srOcStudenta, char plStudenta) {
        WezelListy* nowyStudent = new WezelListy(imStudenta, nzStudenta, srOcStudenta, plStudenta);
        if (glowa == NULL) {
            glowa = nowyStudent;
            ogon = nowyStudent;
        } else {
            ogon->wskNastepny = nowyStudent;
            nowyStudent->wskPoprzedni = ogon;
            ogon = nowyStudent;
        }
        aktualnaDlugoscListy++;
    }

    void usunZListyStudentaOPodanymNrPozycji(int nrPozycji) {
        if (nrPozycji <= 0 || nrPozycji > aktualnaDlugoscListy) {
            cout << "Bledny numer pozycji do usuniecia." << endl;
            return;
        }

        WezelListy* obecny = glowa;
        for (int i = 1; i < nrPozycji; i++) {
            obecny = obecny->wskNastepny;
        }

        if (obecny->wskPoprzedni != NULL) {
            obecny->wskPoprzedni->wskNastepny = obecny->wskNastepny;
        } else {
            glowa = obecny->wskNastepny;
        }

        if (obecny->wskNastepny != NULL) {
            obecny->wskNastepny->wskPoprzedni = obecny->wskPoprzedni;
        } else {
            ogon = obecny->wskPoprzedni;
        }

        delete obecny;
        aktualnaDlugoscListy--;
    }

    WezelListy* zwrocWezelZLsityStudentowOPodanymImieniuINazwisku(string imieStudenta, string nazwiskoStudenta) {
        WezelListy* obecny = glowa;
        while (obecny != NULL) {
            if (obecny->imieStudenta == imieStudenta && obecny->nazwiskoStudenta == nazwiskoStudenta) {
                return obecny;
            }
            obecny = obecny->wskNastepny;
        }
        return NULL;
    }

    void wyswietlDaneWezlowZListyStudentowOSredniejOcenNizszejOdZadanej(double srednia) {
        WezelListy* obecny = glowa;
        while (obecny != NULL) {
            if (obecny->sredniaOcenStudenta < srednia) {
                cout<<"Imie: "<<obecny->imieStudenta<<", Nazwisko: "<<obecny->nazwiskoStudenta<<", Srednia ocen: "<<obecny->sredniaOcenStudenta<<", Plec: "<<obecny->plecStudenta<<endl;
            }
            obecny = obecny->wskNastepny;
        }
    }

    WezelListy* zwrocWezelZListyStudentowDlaMezczyznyOSredniejOcenNajdalszejZadanej(double srednia) {
        WezelListy* obecny = glowa;
        WezelListy* najdalszyMezczyzna = NULL;
        double najwiekszaRoznica = 0.0;

        while (obecny != NULL) {
            if (obecny->plecStudenta == 'M') {
                double roznica = abs(obecny->sredniaOcenStudenta - srednia);
                if (najdalszyMezczyzna == NULL || roznica > najwiekszaRoznica) {
                    najdalszyMezczyzna = obecny;
                    najwiekszaRoznica = roznica;
                }
            }
            obecny = obecny->wskNastepny;
        }
        return najdalszyMezczyzna;
    }

};

int main() {
    ListaStudentow* listaStudentow = new ListaStudentow();
    cout << "Program do zarzadzania lista studentow" << endl;
    cout << "[0] - wyjscie z programu" << endl;
    cout << "[1] - dodawanie nowego studenta na koniec listy" << endl;
    cout << "[2] - usuwanie z listy studenta na podanej pozycji listy" << endl;
    cout << "[3] - wyswietlanie informacji o studencie o podanym imieniu i nazwisku" << endl;
    cout << "[4] - wyswietlanie informacji o studentach majacych srednia nizsza od podanej" << endl;
    cout << "[5] - wyswietlanie informacji o mezczyznie majacym srednia najdalsza podanej" << endl;
    cout << "=========================================" << endl;


    //listaStudentow->dodajNowegoStudentaNaKoniecListy("Jan", "Kowalski", 4.6, 'M');
    //listaStudentow->dodajNowegoStudentaNaKoniecListy("Jerzy", "Kremowka", 3.0, 'M');
    //listaStudentow->dodajNowegoStudentaNaKoniecListy("Gosia", "Lew", 5.0, 'K');

    int pom = 1, n;
    while (pom) {
        cout << "Wprowadz nr operacji: ";
        cin >> n;
        switch (n) {
        case 0:
            cout << "Wychodzenie..." << endl;
            pom = 0;
            //delete listaStudentow;
            break;
        case 1:
            {
                cout << "Dodawanie..." << endl;
                string imie, nazwisko;
                double srednia;
                char plec;
                cout << "Podaj imie studenta: ";
                cin >> imie;
                cout << "Podaj nazwisko studenta: ";
                cin >> nazwisko;
                cout << "Podaj srednia ocen studenta: ";
                cin >> srednia;
                if(srednia < 2.0 || srednia > 5.0)cout<<"Wprowadzono srednia spoza przedzialu [2.0;5.0] "<<endl;
                else
                {
                cout << "Podaj plec studenta (M/K): ";
                cin >> plec;
                if(plec == 'M' || plec == 'K')
                {
                listaStudentow->dodajNowegoStudentaNaKoniecListy(imie, nazwisko, srednia, plec);
                cout<<endl;
                }
                else cout<<"Plec powinna byc M lub K "<<endl;
                }
                break;
            }
        case 2:
            {
                cout << "Usuwanie studenta o podanej pozycji" << endl;
                int nrPozycji;
                cout << "Podaj numer pozycji do usuniecia: ";
                cin >> nrPozycji;
                listaStudentow->usunZListyStudentaOPodanymNrPozycji(nrPozycji);
                cout<<endl;
                break;
            }
        case 3:
            {
                cout << "Wyswietlanie informacji o studencie o podanym imieniu i nazwisku" << endl;
                string imie, nazwisko;
                cout << "Podaj imie studenta: ";
                cin >> imie;
                cout << "Podaj nazwisko studenta: ";
                cin >> nazwisko;
                WezelListy* wezel = listaStudentow->zwrocWezelZLsityStudentowOPodanymImieniuINazwisku(imie, nazwisko);
                if (wezel != NULL) {
                    cout << "Imie: " << wezel->imieStudenta << ", Nazwisko: " << wezel->nazwiskoStudenta
                         << ", Srednia ocen: " << wezel->sredniaOcenStudenta << ", Plec: " << wezel->plecStudenta << endl;
                } else {
                    cout << "Nie znaleziono studenta o podanym imieniu i nazwisku." << endl;
                }
                cout<<endl;
                break;
            }
        case 4:
            {
                cout << "Wyswietlanie informacji o studentach majacych srednia nizsza od podanej" << endl;
                double srednia;
                cout << "Podaj srednia ocen: ";
                cin >> srednia;
                listaStudentow->wyswietlDaneWezlowZListyStudentowOSredniejOcenNizszejOdZadanej(srednia);
                cout<<endl;
                break;
            }
        case 5:
            {
                cout << "Wyswietlanie informacji o mezczyznie majacym srednia najdalsza podanej" << endl;
                double srednia;
                cout << "Podaj srednia ocen: ";
                cin >> srednia;
                WezelListy* wezel = listaStudentow->zwrocWezelZListyStudentowDlaMezczyznyOSredniejOcenNajdalszejZadanej(srednia);
                if (wezel != NULL) {
                    cout<<"Imie: "<<wezel->imieStudenta<<", Nazwisko: "<<wezel->nazwiskoStudenta<<", Srednia ocen: "<<wezel->sredniaOcenStudenta<<", Plec: "<<wezel->plecStudenta<<endl;
                } else {
                    cout<<"Nie znaleziono mezczyzny"<<endl;
                }
                cout<<endl;
                break;
            }
        default:
            {
                cout<<"Bledny nr operacji"<<endl;
                cout<<endl;
                break;
            }
        }
    }
    delete listaStudentow;
    return 0;
}

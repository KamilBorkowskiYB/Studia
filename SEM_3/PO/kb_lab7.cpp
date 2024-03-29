#include <iostream>
using namespace std;

class Konto{
protected:
string login;
string haslo;
bool czyZalogowany =false;
public:
    string getLogin(){return this->login;}
    string getHaslo(){return this->haslo;}
    void setCzyZalogowany(bool czyZalogowany) { this->czyZalogowany = czyZalogowany; }
};

class Notatka{
string nazwa;
string tresc;
public:
    Notatka(string nazwa,string tresc)
    {
        this->nazwa=nazwa;
        this->tresc=tresc;
    }
    string getNazwa(){return this->nazwa;}
    string getTresc(){return this->tresc;}
    void setTresc(string tresc){this->tresc=tresc;}
    ~Notatka(){}
};

class Folder{
string nazwa;
Notatka* notatki[10];
public:
    string getNazwa(){return this->nazwa;}
    Folder(string nazwa)
    {
        this->nazwa=nazwa;
        for(int i=0;i<10;i++)
        {
            notatki[i]=NULL;
        }
    }
    Notatka* getNotatka(int index) {
        if (index >= 0 && index < 10) {
            return notatki[index];
        }
        return NULL;
    }
    void dodajNotatke(int index, string nazwaNotatki, string tresc) {
        if (index >= 0 && index < 10) {
            notatki[index] = new Notatka(nazwaNotatki, tresc);
        }
    }
    void setNotatka(int index, Notatka* nowaNotatka) {
        if (index >= 0 && index < 10) {
            notatki[index] = nowaNotatka;
        }
    }
    ~Folder(){
        for (int i = 0; i < 10; ++i) {
            if (notatki[i] != NULL) {
                delete notatki[i];
            }
        }
    }
};
class KontoUzytkownika;
class KontoAdministratora : public Konto {
public:
    KontoAdministratora(string login, string haslo);
    void usunFolder(KontoUzytkownika* uzytkownik, string nazwaFolderu);
    void usunNotatke(KontoUzytkownika* uzytkownik, string nazwaFolderu, string nazwaNotatki);
    ~KontoAdministratora();
};

class KontoUzytkownika : public Konto{
friend class KontoAdministratora;
Folder* foldery[10];

public:
    KontoUzytkownika(string login,string haslo)
    {
        this->login=login;
        this->haslo=haslo;
        for(int i=0;i<10;i++)
        {
            foldery[i]=NULL;
        }
    }
    void dodajNotatke(string nazwaFolderu,string nazwaNotatki,string tresc){
        if(!this->czyZalogowany) cout<<"Nie mozna dodac notatki - uzytkownik nie jest zalogowany"<<endl;
        else
        {
            for(int i=0;i<10;i++)
            {
                if(foldery[i]!=NULL && foldery[i]->getNazwa() == nazwaFolderu)
                {
                    //cout<<"Znaleziono folder"<<endl;
                    for (int j = 0; j < 10; j++) {
                        if (foldery[i]->getNotatka(j) == NULL) {
                            foldery[i]->dodajNotatke(j,nazwaNotatki,tresc);
                            cout<<"Dodano notatke "<<nazwaNotatki<<" do folderu "<<nazwaFolderu<<endl;
                            return;
                        }
                    }
                    cout<<"Folder jest pelny - podaj inny"<<endl;
                    return;
                }
            }
            //cout<<"Folder nie istnieje"<<endl;
            for(int i=0;i<10;i++)
            {
                if(foldery[i]==NULL)
                {
                   //cout<<"Stworzono nowy folder"<<endl;
                   foldery[i] = new Folder(nazwaFolderu);
                    for (int j = 0; j < 10; j++) {
                        if (foldery[i]->getNotatka(j) == NULL) {
                            foldery[i]->dodajNotatke(j,nazwaNotatki,tresc);
                            cout<<"Dodano notatke "<<nazwaNotatki<<" do folderu "<<nazwaFolderu<<endl;
                            return;
                        }
                    }
                }
            }
            cout<<"Osiagnieto maksymalna ilosc folderow"<<endl;
            return;
        }
    }
    void edytujNotatke(string nazwaFolderu, string nazwaNotatki, string NowaTresc){
        if (!this->czyZalogowany) {
            cout << "Nie mozna edytowac notatki - uzytkownik nie jest zalogowany" << endl;
        } else {
            for (int i = 0; i < 10; i++) {
                if (foldery[i] != NULL && foldery[i]->getNazwa() == nazwaFolderu) {
                    for (int j = 0; j < 10; j++) {
                        Notatka* notatka = foldery[i]->getNotatka(j);
                        if (notatka != NULL && notatka->getNazwa() == nazwaNotatki) {
                            notatka->setTresc(NowaTresc);
                            cout << "Zaktualizowano tresc notatki " << nazwaNotatki << " w folderze " << nazwaFolderu << endl;
                            return;
                        }
                    }
                    cout << "Nie znaleziono notatki o nazwie " << nazwaNotatki << " w folderze " << nazwaFolderu << endl;
                    return;
                }
            }
            cout << "Nie znaleziono folderu o nazwie " << nazwaFolderu << endl;
        }
    }
    void wyswietlFoldery(){
        if (!this->czyZalogowany) cout << "Nie mozna wyswietlic folderow - uzytkownik nie jest zalogowany" << endl;
            else
            {
            cout<<"Foldery uzytkownika:" << endl;
            for (int i = 0; i < 10; ++i) {
                if(foldery[i]!=NULL)cout<<foldery[i]->getNazwa()<<endl;
            }
        }
    }
    void wyswietlNotatki(string nazwaFolderu){
        if (!this->czyZalogowany) cout << "Nie mozna wyswietlic notatek - uzytkownik nie jest zalogowany" << endl;
        else
        {
            for (int i = 0; i < 10; i++) {
                if (foldery[i] != NULL && foldery[i]->getNazwa() == nazwaFolderu) {
                    cout << "Notatki w folderze " << nazwaFolderu << ":" << endl;
                    for (int j = 0; j < 10; j++) {
                        Notatka* notatka = foldery[i]->getNotatka(j);
                        if (notatka != NULL) {
                            cout << "Nazwa: " << notatka->getNazwa() << ", Tresc: " << notatka->getTresc() << endl;
                        }
                    }
                    return;
                }
            }
            cout << "Nie znaleziono folderu o nazwie " << nazwaFolderu << endl;
        }
    }

    void usunNotatke(KontoAdministratora* admin,string nazwaFolderu, string nazwaNotatki) {
        if (!this->czyZalogowany)  {
            cout << "Nie mozna usunac notatki - uzytkownik nie jest zalogowany" << endl;
        } else {
            // Wywo³aj metodê usunNotatke w klasie KontoAdministratora
            if (admin != NULL) {
                admin->usunNotatke(this, nazwaFolderu, nazwaNotatki);
            } else {
                cout << "Nie mozna usunac notatki - brak dostepu do administratora" << endl;
            }
        }
    }
    void usunFolder(KontoAdministratora* admin ,string nazwaFolderu) {
        if (!this->czyZalogowany)  {
            cout << "Nie mozna usunac folderu - uzytkownik nie jest zalogowany" << endl;
        } else {
            // Wywo³aj metodê usunFolder w klasie KontoAdministratora
            if (admin != NULL) {
                admin->usunFolder(this, nazwaFolderu);
            } else {
                cout << "Nie mozna usunac folderu - brak dostepu do administratora" << endl;
            }
        }
    }
    ~KontoUzytkownika(){
        for (int i = 0; i < 10; ++i) {
            if (foldery[i] != NULL) {
                delete foldery[i];
            }
        }
    }
};
KontoAdministratora::KontoAdministratora(string login, string haslo) {
    this->haslo = haslo;
    this->login = login;
}
void KontoAdministratora::usunFolder(KontoUzytkownika* uzytkownik, string nazwaFolderu) {
        if (!this->czyZalogowany) {
            cout << "Nie mozna usunac folderu - admin nie jest zalogowany" << endl;
        } else {
            for (int i = 0; i < 10; i++) {
                if (uzytkownik->foldery[i] != NULL && uzytkownik->foldery[i]->getNazwa() == nazwaFolderu) {
                    delete uzytkownik->foldery[i];
                    uzytkownik->foldery[i] = NULL;
                    cout << "Usunieto folder: " << nazwaFolderu << " z konta uzytkownika" << endl;
                    return;
                }
            }
            cout << "Nie znaleziono folderu " << nazwaFolderu << " na koncie uzytkownika" << endl;
        }
}
void KontoAdministratora::usunNotatke(KontoUzytkownika* uzytkownik, string nazwaFolderu, string nazwaNotatki) {
        if (!this->czyZalogowany) {
            cout << "Nie mozna usunac notatki - uzytkownik nie jest zalogowany" << endl;
        } else {
            for (int i = 0; i < 10; i++) {
                if (uzytkownik->foldery[i] != NULL && uzytkownik->foldery[i]->getNazwa() == nazwaFolderu) {
                    for (int j = 0; j < 10; j++) {
                        Notatka* notatka = uzytkownik->foldery[i]->getNotatka(j);
                        if (notatka != NULL && notatka->getNazwa() == nazwaNotatki) {
                            delete notatka;
                            uzytkownik->foldery[i]->setNotatka(j, NULL);
                            cout << "Usunieto notatke: " << nazwaNotatki << " z folderu " << nazwaFolderu << " uzytkownika" << endl;
                            return;
                        }
                    }
                    cout << "Nie znaleziono notatki o nazwie " << nazwaNotatki << " w folderze " << nazwaFolderu << " uzytkownika" << endl;
                    return;
                }
            }
            cout << "Nie znaleziono folderu o nazwie " << nazwaFolderu << " uzytkownika" << endl;
        }
}
KontoAdministratora::~KontoAdministratora() {}

class MenagerUzytkownikow{
KontoUzytkownika* uzytkownicy[100];
KontoAdministratora* administratorzy[10];
public:
    MenagerUzytkownikow() {
        for (int i = 0; i < 100; ++i) {
            uzytkownicy[i] = NULL;
        }
        for (int i = 0; i < 10; ++i) {
            administratorzy[i] = NULL;
        }
    }
    Konto* logowanie(string login, string haslo) {
        for (int i = 0; i < 100; ++i) {
            if (uzytkownicy[i] != NULL && uzytkownicy[i]->getLogin() == login && uzytkownicy[i]->getHaslo() == haslo) {
                uzytkownicy[i]->setCzyZalogowany(true);
                cout<<"Uzytkownik "<<login<<" zalogowany" <<endl;
                return uzytkownicy[i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (administratorzy[i] != NULL && administratorzy[i]->getLogin() == login && administratorzy[i]->getHaslo() == haslo) {
                administratorzy[i]->setCzyZalogowany(true);
                cout<<"Administrator "<<login<<" zalogowany" <<endl;
                return administratorzy[i];
            }
        }
        cout<<"Nieudane logowanie - nie znaleziono konta o podanym loginie" << endl;
        return NULL;
    }

    Konto* wylogowanie(string login) {
        for (int i = 0; i < 100; ++i) {
            if (uzytkownicy[i] != NULL && uzytkownicy[i]->getLogin() == login) {
                uzytkownicy[i]->setCzyZalogowany(false);
                cout<<"Uzytkownik "<<login<<" wylogowany" <<endl;
                return uzytkownicy[i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (administratorzy[i] != NULL && administratorzy[i]->getLogin() == login) {
                administratorzy[i]->setCzyZalogowany(false);
                cout<<"Administrator "<<login<<" wylogowany" <<endl;
                return administratorzy[i];
            }
        }
        cout<<"Nieudane wylogowanie. Nie znaleziono konta o podanym loginie." << endl;
        return NULL;
    }
    KontoUzytkownika* przypiszKontoUzytkownika(string login,string haslo)
    {
        for (int i = 0; i < 100; ++i) {
            if (uzytkownicy[i] == NULL) {
                KontoUzytkownika* noweKonto = new KontoUzytkownika(login,haslo);
                uzytkownicy[i] = noweKonto;
                cout <<"Konto uzytkownika przypisano do menagera" << endl;
                return noweKonto;
            }
        }
        cout << "Brak miejsca na nowego uzytkownika" << endl;
    }
    KontoAdministratora* przypiszKontoAdministratora(string login,string haslo) {
        for (int i = 0; i < 10; ++i) {
            if (administratorzy[i] == NULL) {
                KontoAdministratora* noweKonto = new KontoAdministratora(login,haslo);
                administratorzy[i] = noweKonto;
                cout << "Konto administratora przypisano do menegera" << endl;
                return noweKonto;
            }
        }
        cout << "Brak miejsca na nowego administratora" << endl;
    }
    ~MenagerUzytkownikow() {
        for (int i = 0; i < 100; ++i) {
            if (uzytkownicy[i] != NULL) {
                delete uzytkownicy[i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (administratorzy[i] != NULL) {
                delete administratorzy[i];
            }
        }
    }
};
int main()
{
MenagerUzytkownikow menager;
KontoUzytkownika* uzytkownik1 = menager.przypiszKontoUzytkownika("Grzegorz","2003");
KontoAdministratora* admin1 = menager.przypiszKontoAdministratora("Jan","admin123");

uzytkownik1->dodajNotatke("f1","n1","t1");
menager.logowanie("Grzegorz", "2003");
uzytkownik1->wyswietlFoldery();
uzytkownik1->dodajNotatke("f1","n1","t1");
uzytkownik1->dodajNotatke("f1","n2","t2");
uzytkownik1->dodajNotatke("f1","n3","t2");
uzytkownik1->dodajNotatke("f1","n4","t2");
uzytkownik1->dodajNotatke("f1","n5","t2");
uzytkownik1->dodajNotatke("f1","n6","t2");
uzytkownik1->dodajNotatke("f1","n7","t2");
uzytkownik1->dodajNotatke("f1","n8","t2");
uzytkownik1->dodajNotatke("f1","n9","t2");
uzytkownik1->dodajNotatke("f1","n10","t2");
uzytkownik1->dodajNotatke("f1","n11","t11");
uzytkownik1->dodajNotatke("f2","n11","t1");
uzytkownik1->wyswietlNotatki("f1");
uzytkownik1->edytujNotatke("f1","n3","nowa_t");
uzytkownik1->wyswietlNotatki("f1");

uzytkownik1->wyswietlFoldery();
uzytkownik1->usunFolder(admin1,"f1");
uzytkownik1->wyswietlFoldery();

menager.logowanie("Jan", "admin123");
uzytkownik1->usunNotatke(admin1,"f1","n4");
uzytkownik1->dodajNotatke("f1","n12","t21");
uzytkownik1->wyswietlNotatki("f1");

uzytkownik1->usunFolder(admin1,"f1");
uzytkownik1->wyswietlFoldery();
uzytkownik1->wyswietlNotatki("f1");

delete &menager;
return 0;
}

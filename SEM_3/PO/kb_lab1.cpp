#include <iostream>
#include <string>
using namespace std;

class Bankomat
{
private:
    int aktualnyPoziomGotowki;
    bool zablokowanyBankomat;
    bool uwierzytelnionyUzytkownik;
public:
    void wlozKarte(){uwierzytelnionyUzytkownik = true;}
    void wyjmijKarte(){uwierzytelnionyUzytkownik = false;}
    void zrobWyplate(int kwota){
        char pom;
        if(uwierzytelnionyUzytkownik)
        {
            if(zablokowanyBankomat==false)
            {
                if(aktualnyPoziomGotowki-kwota>=0)
                {
                   this->aktualnyPoziomGotowki= aktualnyPoziomGotowki - kwota;
                }
                else
                {
                    cout<<"Mozna wyplacic maksymalnie "<<aktualnyPoziomGotowki<<"zl"<<endl<<"Wyplacic wszystkie mozliwe srodki(T/N)?"<<endl;
                    cin>>pom;
                    if(pom == 'T')
                    {
                        this->aktualnyPoziomGotowki = 0;
                    }
                }
            }
        }
        ;}
    void zrobWplate(int kwota){
        if(zablokowanyBankomat == false)
        {
            if(uwierzytelnionyUzytkownik)
            {
                this->aktualnyPoziomGotowki = aktualnyPoziomGotowki + kwota;
            }
        }
        ;}
    void odblokujBankomat(){
        if(aktualnyPoziomGotowki != 0)
        {
            this->zablokowanyBankomat = false;
        }
        ;}
    int zrobWrzutGotowki(int kwota){
        this->aktualnyPoziomGotowki = aktualnyPoziomGotowki + kwota;
        ;}
    void stanKonta(){
        cout<<aktualnyPoziomGotowki<<endl;
    ;}
    Bankomat(int poziomGotowki,bool zablokowany){
    this->aktualnyPoziomGotowki = poziomGotowki;
    this->zablokowanyBankomat = zablokowany;
    };
    ~Bankomat();
};

int main()
{
    Bankomat* b1 = new Bankomat(100,true);
    b1->stanKonta();
    b1->wlozKarte();
    b1->odblokujBankomat();
    b1->zrobWyplate(101);
    b1->stanKonta();
    b1->zrobWrzutGotowki(251);
    b1->stanKonta();

    return 0;
}

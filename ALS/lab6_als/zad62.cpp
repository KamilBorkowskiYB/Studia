//================================================
//Zadanie 6_02 jezyk C++
//Drzewo kopiec max
//WCY22IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct KOPNode {
    KOPNode* up;
    KOPNode* left;
    KOPNode* right;
    int key;
};

struct KOP {
    KOPNode* root;
};

//MODUL WYSWIETLANIA DRZEWA
string cr, cl, cp;
void printKOP(string sp, string sn, KOPNode* v)
{
    string s;

    if (v)
    {
        s = sp;
        if (sn == cr)
            s[s.length() - 2] = ' ';
        printKOP(s + cp, cr, v->right);

        s = s.substr(0, sp.length() - 2);
        cout << s << sn << v->key << endl;

        s = sp;
        if (sn == cl)
            s[s.length() - 2] = ' ';
        printKOP(s + cp, cl, v->left);
    }
}

//funkcja zmieniajaca klucze dwoch wezlow
void swapNodes(KOPNode* a, KOPNode* b) {
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}

void insert(KOP* kop, int key){
    KOPNode* newNode = (KOPNode*)malloc(sizeof(KOPNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->up = NULL;
    newNode->key = key;

    if (kop->root == NULL) {//sprawdzenie czy kupiec jest pusty
        kop->root = newNode;
        return;
    }

    // Wstawianie wêzla na ostatnie miejsce
    KOPNode* TAB[100];
    int start = -1;
    int end = -1;

    TAB[++end] = kop->root;

    while (start != end) {
        KOPNode* temp = TAB[++start];

        if (temp->left == NULL) {//jesli lewy potomek nie istnieje wstaw tam nowy wezel
            temp->left = newNode;
            newNode->up = temp;
            break;
        } else {
            TAB[++end] = temp->left;
        }

        if (temp->right == NULL) {//jesli prawy potomek nie istnieje wstaw tam nowy wezel
            temp->right = newNode;
            newNode->up = temp;
            break;
        } else {
            TAB[++end] = temp->right;
        }
    }

    // Zamiana miejscami z rodzicem, jeœli nowy wêze³ jest wiêkszy
    KOPNode* current = newNode;
    while (current->up != NULL && current->key > current->up->key) {
        swapNodes(current, current->up);
        current = current->up;
    }
}

//funkcja zwalniajaca pamiec
void freeTree(KOPNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
//funkcja wypisujaca wezly infiksowo
void LVR(KOPNode* root) {
    if (root != NULL) {
        LVR(root->left);
        cout << root->key << " ";
        LVR(root->right);
    }
}
//funkcja wypisujaca wezly prefiksowo
void VLR(KOPNode* root) {
    if (root != NULL) {
        cout << root->key << " ";
        VLR(root->left);
        VLR(root->right);
    }
}
//funkcja wypisujaca wezly postfiksowo
void LRV(KOPNode* root) {
    if (root != NULL) {
        LRV(root->left);
        LRV(root->right);
        cout << root->key << " ";
    }
}

//funkcja poprawiajaca kopeiec po usunieciu klucza maksymalnego
void popraw(KOPNode* root) {
    KOPNode* largest = root;
    KOPNode* left = root->left;
    KOPNode* right = root->right;

    if (left != NULL && left->key > largest->key)//sprawdzenie ktory potomek jest wiekszy
        largest = left;

    if (right != NULL && right->key > largest->key)
        largest = right;

    if (largest != root) {//zamiana miejscami wezlow jesli wezel nie jest najwiekszy
        swapNodes(root, largest);
        popraw(largest);
    }
}
//funkcja usuwajaca wezel o najwiekszym kluczu
void removeRoot(KOP* kop) {
    if (kop->root == NULL) {//sprawdzenie czy kopiec jest pusty
        cout << "Kopiec jest pusty." << endl;
        return;
    }

    KOPNode* lastNode = kop->root;//szukanie ostatniego wezla kopca
    while (lastNode->right != NULL) {
        lastNode = lastNode->right;
    }

    kop->root->key = lastNode->key;//zamiana klucza na klucz ostatniego wezla

    if (lastNode->up != NULL) {//zaktualizowanie wskaznikow ostatniego wezla
        if (lastNode->up->left == lastNode)
            lastNode->up->left = NULL;
        else
            lastNode->up->right = NULL;
    }

    free(lastNode);//zwolnienie pamieci po usunietym wezle

    popraw(kop->root);//poprawienie kopca po usunieciu wezla
}

int main(){
    //deklaracja korzenia drzewa
    KOP* kop = (KOP*)malloc(sizeof(KOP));
    kop->root = NULL;

    //czesc modulu wyswietlenia drzewa
    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;


    int pom=1,n;//pom oblusguje interfejs, n= nr komendy z interfejsu
    cout << "Program do zarzadzania kopcem" << endl;
    cout << "[0] - wyjscie z programu" << endl;
    cout << "[1] - dodawanie nowego wezla do drzewa" << endl;
    cout << "[2] - wyswietlenie drzewa" << endl;
    cout << "[3] - wyswietlanie LVR" << endl;
    cout << "[4] - wyswietlanie VLR" << endl;
    cout << "[5] - wyswietlanie LRV" << endl;
    cout << "[6] - usuwanie wezla o najwiekszym kluczu" << endl;
    cout << "=========================================" << endl;

    while(pom){
        cout << "Wprowadz nr operacji: ";
        cin >> n;
        switch (n){
            case 0:
                {
                cout << "Wychodzenie..." << endl;
                pom = 0;
                cout<<endl;
                break;
                }
            case 1:
                {
                int k=0;//gdy wywola sie ponownie ta komende trzeba zmienic wartosc k z -1
                cout<<"Podaj wezel(liczba,-1 konczy dodawanie wezlow)"<<endl;
                while(k!=-1)
                {
                cin>>k;
                if(k!=-1)
                {
                insert(kop,k);
                }
                }
                break;
                }
            case 2:
                {
                if(kop->root)printKOP("", "", kop->root);//wyswietlenie kopca
                break;
                }
            case 3:
                {
                cout << "Kopiec wyswietlony jako LVR: " << endl;
                LVR(kop->root);
                cout << endl;
                break;
                }
            case 4:
                {
                cout << "Kopiec wyswietlony jako VLR: " << endl;
                VLR(kop->root);
                cout << endl;
                break;
                }
            case 5:
                {
                cout << "Kopiec wyswietlony jako LRV: " << endl;
                LRV(kop->root);
                cout << endl;
                break;
                }
            case 6:
                {
                removeRoot(kop);//usuniecie wezla o maksymalnym kluczu
                break;
                }
        }
    }
    freeTree(kop->root);//zwolnienie pamieci na koniec programu
    return 0;
}

//================================================
//Zadanie 3_01 jezyk C++
//Sito Erastotenesa
//WCY21IY1S1 Borkowski Kamil
//================================================
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int value;
    Node* next;
};

int main()
{
    int n,i=2,j=2,k=1;
    cout<<"Podaj zakres gorny liczb pierwszych: ";
    cin>>n;
    cout<<"Liczby pierwsze w przedziale [2,"<<n<<"] to:"<<endl;
    Node* head = NULL; //pierwszy element listy, poczatkowo pusty
    Node* current = head; //pomocniczy element listy, sluzacy do poruszania sie po liscie

    for(;i<=n;i++)//Poczatkowe uznanie wszystkich liczb z zakresu jako pierwsze i wpisanie ich do lsity
	{
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = i;
        new_node->next = NULL;
        if(head != NULL)//tworzymy kolejne elementy jesli mamy juz element pierwszy
		{
            current->next = new_node;
            current = new_node;
        }
		else//jesli pierwszy element listy jest NULL przypisyjemy pod niego nowo utworzony element
		{
            head = new_node;
            current = new_node;
        }
    }
    for(;j*j<=n;j++)
	{
        current=head;
        Node* prev = NULL;//pomocniczy element listy trzymajacy dane poprzedniego elementu
        while(current != NULL)
		{
            int num = current->value;
            if(num == j)
            {
                prev = current;
                current = current->next;
            }
            else
            {
                if(num % j == 0)//usuwanie liczb podzielnych przez j
                {
                    if(prev != NULL)
                    {
                        prev->next = current->next;
                    }
                    else
                    {
                        head = current->next;
                    }
                    free(current);
                    current = prev->next;
                }
                else
                {
                    prev = current;
                    current = current->next;
                }
            }
		}
    }
    current = head;
    while(current != NULL)
    {
        cout << current->value <<'\t';
        if(k==10)
        {
            cout<<endl;
            k=0;
        }
        Node* pom = current;
        current = current->next;
        free(pom);//zwolniamy pammiec
    }
return 0;
}

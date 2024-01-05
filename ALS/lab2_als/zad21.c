#include<stdio.h>
#include<stdlib.h>

//deklaracja struktury tablicy
typedef struct list{
  int wartosc;
  struct list* next;
}list;

//funkcja wyswietlajaca elementy listy
void wyswietl(list* head)
{
    list* pom = head;
    if(pom == NULL)return;
    while(pom != NULL)
    {
        printf("%d ", pom->wartosc);
        pom = pom->next;
    }
printf("\n");
}

//funkcja uzupelniajaca liste
void dodaj_element(list** head, int wartosc)
{
  list* tail = *head;
  while (tail->next != NULL) {
    tail = tail->next;
  };
  list* new = (list*)malloc(sizeof(list));
  new->wartosc = wartosc;
  new->next = NULL;
  tail->next = new;
}

//funkcja obliczajaca srednia z elementow tablicy
void srednia(list* head)
{
  float j = 0.0;
  float wartosc = 0.0;
  float srednia;
  list* pom = head;
  if(pom == NULL)
    return;
  while(pom != NULL){
    wartosc = wartosc + pom->wartosc;
    j++;
    pom = pom->next;
  }
  srednia = wartosc / j;
  printf("Srednia: %f\n", srednia);
}

//funkcja usuwajaca pierwszy element listy(wartosc nieparzysta)
void usuwanie_pierwszego_elementu(list **head)
{
    list *pom;
    pom = *head;
    if(pom){
        *head = pom->next;
        free(pom);
    }
}
//funkcja usuwajaca element listy
void usun_element(list** head, int wartosc)
{
  list* current = *head;
  list* poprzedni = current;
  current = current->next;
  while(current != NULL){
    if(current->wartosc == wartosc){
      poprzedni->next = current->next;
      free(current);
      return;
    }
    poprzedni = current;
    current = current->next;
  }
}

int main()
{
list* lista = (list*)malloc(sizeof(list));
lista->wartosc=1;
lista->next=NULL;
printf("Wartosci:\n");

//petla dodajaca 99 elementow do listy
int i=2;
for(;i<=100;i++)
    {
    dodaj_element(&lista, i);
    }
wyswietl(lista);
srednia(lista);
usuwanie_pierwszego_elementu(&lista);

//petla usuwajaca nieparzyste elementy (poza pierwszym, juz usunietym)
i=1;
for(;i<=100;i++)
    {
    if(i%2==1)usun_element(&lista, i);
    }
wyswietl(lista);
srednia(lista);
return 0;
}

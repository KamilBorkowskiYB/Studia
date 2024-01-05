#include<stdio.h>
#include<stdlib.h>

typedef struct list{
  char imie[20];
  char nazwisko[20];
  int numer_telefonu;
  struct list* previous;
  struct list* next;
} list;

void dodaj_element(list** head, char* imie, char* nazwisko, int numer_telefonu)
{
  list* nowy_element = (list*)malloc(sizeof(list));
  strncpy(nowy_element->imie, imie, 20);
  strncpy(nowy_element->nazwisko, nazwisko, 20);
  nowy_element->numer_telefonu = numer_telefonu;
  nowy_element->next = NULL;

  if (*head == NULL) {
    // Jeśli lista jest pusta, nowy element staje się głową listy.
    nowy_element->previous = NULL;
    *head = nowy_element;
  } else {
    list* obecny_element = *head;
    list* poprzedni_element = NULL;

    // Szukamy odpowiedniego miejsca na liście alfabetycznie po pierwszej literze nazwiska.
    while (obecny_element != NULL && strcmp(nazwisko, obecny_element->nazwisko) > 0) {
      poprzedni_element = obecny_element;
      obecny_element = obecny_element->next;
    }

    // Jeśli poprzedni_element nie jest NULL, to wstawiamy nowy_element pomiędzy poprzedni_element i obecny_element.
    if (poprzedni_element != NULL) {
      nowy_element->previous = poprzedni_element;
      nowy_element->next = obecny_element;
      poprzedni_element->next = nowy_element;
      if (obecny_element != NULL) {
        obecny_element->previous = nowy_element;
      }
    } else {
      // Jeśli poprzedni_element jest NULL, to nowy_element staje się nową głową listy.
      nowy_element->previous = NULL;
      nowy_element->next = *head;
      (*head)->previous = nowy_element;
      *head = nowy_element;
    }
  }
}

void wyswietl_liste(list* head)
{
  list* current = head;
  while (current != NULL) {
    printf("Imie: %s\n", current->imie);
    printf("Nazwisko: %s\n", current->nazwisko);
    printf("Numer telefonu: %d\n", current->numer_telefonu);
    printf("\n");
    current = current->next;
  }
}

void wyswietl_liste_tyl(list *head)
{
    printf("\n");
    if(head==NULL) printf("List is empty");
    else
    {
        list *current=head;
        while (current->next != NULL){
            current = current->next; //idziemy na koniec listy
        }
        while(current!=NULL){
            printf("Imie: %s\n", current->imie);
            printf("Nazwisko: %s\n", current->nazwisko);
            printf("Numer telefonu: %d\n", current->numer_telefonu);
            printf("\n");
            current = current->previous;
            }
    }
}

void usun(list** head, char* nazwisko_)
{
    list* current = *head;

    // Sprawdzamy czy lista jest pusta.
    if (current == NULL) {
        return; // Lista jest pusta, nie ma nic do usunięcia.
    }

    // Sprawdzamy czy pierwszy element pasuje do nazwiska.
    if (strcmp(current->nazwisko, nazwisko_) == 0) {
        *head = current->next;
        if (current->next != NULL) {
            current->next->previous = NULL;
        }
        free(current);
        return;
    }

    // Przeszukujemy resztę listy.
    while (current->next != NULL) {
        if (strcmp(current->next->nazwisko, nazwisko_) == 0) {
            list* tmp = current->next;
            current->next = tmp->next;
            if (tmp->next != NULL) {
                tmp->next->previous = current;
            }
            free(tmp);
            return;
        }
        current = current->next;
    }
}

// Funkcja wypisująca elementy o podanym nazwisku.
void wypisz_elementy_po_nazwisku(list* head, const char* nazwisko_do_wyswietlenia) {
  list* current = head;
  int znaleziono = 0;

  while (current != NULL) {
    if (strcmp(current->nazwisko, nazwisko_do_wyswietlenia) == 0) {
      // Znaleziono element o pasującym nazwisku.
      printf("Imie: %s\n", current->imie);
      printf("Nazwisko: %s\n", current->nazwisko);
      printf("Numer telefonu: %d\n", current->numer_telefonu);
      printf("\n");

      znaleziono = 1;
    }
    // Przechodź do następnego elementu.
    current = current->next;
  }

  if (!znaleziono) {
    printf("Nie znaleziono osoby o nazwisku: %s\n", nazwisko_do_wyswietlenia);
  }
}

int main()
{
  list* head = NULL;
  // Dodajemy pierwsze elementy do listy
  dodaj_element(&head, "Jan", "Kowalski", 123456789);
  dodaj_element(&head, "Anna", "Nowak", 987654321);
  dodaj_element(&head, "Piotr", "Zielinski", 456123789);

// Petla pozwala nam wykonywac wiele polecen jedno po drugim
while(1)
  {
// Wybieramy komende do przeprowadzenia
char i;
printf("Mozliwe komendy:\n");
printf("d - dodaj wizytowke:\n");
printf("s - szukaj wizytowki\n");
printf("w - wypisz wizytowki(A...Z)\n");
printf("v - wypisz wizytowki(Z...A)\n");
printf("u - usun wizytowke\n");
printf("e - wyjdz\n");

scanf(" %c",&i);

if(i=='d')
{
  char imie[20];
  char nazwisko[20];
  int numer_telefonu;
  // Pobieramy dane nowego elementu
  printf("Podaj imie: ");
  scanf("%s", imie);

  printf("Podaj nazwisko: ");
  scanf("%s", nazwisko);

  printf("Podaj numer telefonu: ");
  scanf("%d", &numer_telefonu);

  //Dodajemy nowy element do listy
  dodaj_element(&head, imie, nazwisko,numer_telefonu);
}
if(i=='s')
{
    printf("Podaj nazwisko osoby, ktora chcesz wyswietlic: \n");
    char nazwisko_do_szukania[20];
    scanf("%s", nazwisko_do_szukania);
    wypisz_elementy_po_nazwisku(head,nazwisko_do_szukania);

}
if(i=='w')
{
    //Wyœwietlamy wszystkie elementy listy
    wyswietl_liste(head);
}
if(i=='v')
{
    //Wyœwietlamy wszystkie elementy listy od tylu
    wyswietl_liste_tyl(head);
}
if(i=='u')
{
    //Podajemy nazwisko osoby do usuniecia i pozbywamy sie jej
    char nazwisko_do_usuniecia[20];
    printf("Wpisz nazwisko osoby, ktorej chcesz usunac:\n");
    scanf("%s", nazwisko_do_usuniecia);
    usun(&head, nazwisko_do_usuniecia);
}
if(i=='e')
{
    //wychodzimy z petli - opuszczamy program
    printf("Wychodzenie...\n");
    break;
}
}
return 0;
}

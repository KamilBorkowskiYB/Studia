#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//funkcja obliczaj�ca szescian liczby
void *szescian(void *arg) {
    int *wynik = (int*)malloc(sizeof(int));
    *wynik = (*(int*)arg) * (*(int*)arg) *(*(int*)arg);
	return wynik;
}

int main() {
  int n;//ilosc liczb i watkow

  printf("Podaj ilosc liczb: ");
  scanf("%d", &n);

  pthread_t threads[n];//tablica watkow
  int liczby[n];//tablica liczb wejsciowych
  int wyniki[n];//tablica szescianow

  //wczytywanie liczb i tworzenie w�tk�w
  for (int i = 0; i < n; i++) {
	   printf("Podaj %d liczbe: ", i+1);
       scanf("%d", &liczby[i]);
       pthread_create(&threads[i], NULL, &szescian, &liczby[i]);
    }
    int* wynik;//zmienna pomocnicza dla wyliczania wynikow

  //oczekiwanie na zako�czenie w�tk�w
  for (int i = 0; i < n; ++i) {
       pthread_join(threads[i], (void**)&wynik);
       wyniki[i]=*wynik;
       printf("W�tek %d, id: %d, liczba: %d, Wynik: %d\n", i + 1, getpid(), liczby[i], wyniki[i]);
    }

    int sum = 0;//suma szescianow
    for (int i = 0; i < n;i++) {
        sum += wyniki[i];
    }

    printf("W�tek g��wny, id: %d, Suma: %d\n", getpid(), sum);//glowny watek

  free(wynik);//zwolnienie pamieci z pomocniczej zmiennej
  return 0;
}

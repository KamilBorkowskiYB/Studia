#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//funkcja obliczaj¹ca szescian liczby
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

  //wczytywanie liczb i tworzenie w¹tków
  for (int i = 0; i < n; i++) {
	   printf("Podaj %d liczbe: ", i+1);
       scanf("%d", &liczby[i]);
       pthread_create(&threads[i], NULL, &szescian, &liczby[i]);
    }
    int* wynik;//zmienna pomocnicza dla wyliczania wynikow

  //oczekiwanie na zakoñczenie w¹tków
  for (int i = 0; i < n; ++i) {
       pthread_join(threads[i], (void**)&wynik);
       wyniki[i]=*wynik;
       printf("W¹tek %d, id: %lu, liczba: %d, Wynik: %d\n", i + 1, threads[i], liczby[i], wyniki[i]);
    }

    int sum = 0;//suma szescianow
    for (int i = 0; i < n;i++) {
        sum += wyniki[i];
    }

    printf("Watek glowny, id: %lu, Suma: %d\n", pthread_self(), sum);//glowny watek

  free(wynik);//zwolnienie pamieci z pomocniczej zmiennej
  return 0;
}

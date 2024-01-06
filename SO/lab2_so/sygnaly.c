#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int pom=1;//zmienna do zakonczenia programu bo program nadpisuje komende ctrl + c i ta nie konczy programu

void handle_signal(int signum)
{
	if(signum == SIGINT)//szukanie sygnalu dla ctrl + c
	{
		printf("\nOtrzymano sygnal %d\n",signum);
		pom=0;//gdy wcisnieto ctrl + c warunek petli while przestaje obowiazywac, wiec konczymy program
	}
	if(signum == SIGTSTP)
	{
		printf("\nOtrzymano sygnal %d\n",signum);//podanie sygnalu dla ctrl + z
	}
	if(signum == SIGQUIT)
	{
		printf("\nOtrzymano sygnal %d\n",signum);//podanie sygnalu dla ctrl +
	}
}

int main()
{
printf("Podaj kombinacje klawiszy\n");
while(pom){
	signal(SIGINT, handle_signal);//szukanie sygnalu dla ctrl + c
	signal(SIGTSTP, handle_signal);//szukanie sygnalu dla ctrl + z
	signal(SIGQUIT, handle_signal);//szukanie sygnalu dla ctrl + '\'
}
  return 0;
}

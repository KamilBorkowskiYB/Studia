#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct message//struktura wiadomosci
{
    long rodzaj;
    int m;
}; 

int main(int argc, char *argv[])
{
	key_t key = 2222;
    int msqid = msgget(key, IPC_CREAT); //tworzenie kolejki z kluczem
	
	
    int n = atoi(argv[1]);//int n jest wprowadzane przy wywolaniu programu
	int i;
	for(i=1;i<=n;i++)
	{
		if(i!=n)
		{
			struct message M_DANA;
			printf("Podaj %d. liczbe: ",i);
			scanf("%d", &M_DANA.m); 
			msgsnd(msqid,&M_DANA,sizeof(M_DANA),0);
			printf("Wyslano: %d\n", M_DANA.m); 
			M_DANA.rodzaj = 1; 
		}
		else
		{
			struct message M_KONIEC;
			printf("Podaj %d. liczbe: ",i);
			scanf("%d", &M_KONIEC.m); 
			msgsnd(msqid,&M_KONIEC,sizeof(M_KONIEC),0);
			printf("Wyslano: %d\n", M_KONIEC.m); 
			M_KONIEC.rodzaj = 2; 
		}
	}
    return 0;
}

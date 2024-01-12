#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message//struktura wiadomosci
{
    long rodzaj;
    int m;
}; 

int main()
{

    key_t key = 2222;
    int msqid = msgget(key, IPC_CREAT); 
	int s=0,pom=1,licz;
	while(pom)
	{
		if(message.rodzaj = 2)
		{
			struct message ode_m;
			pom=0;
			licz = msgrcv(msqit,&ode_m,sizeof(ode_m),1,0);
			printf("Otrzymano: %d\n", licz); 
			s=s+licz;
		}
		if(message.rodzaj = 1)
		{
			struct message ode_m;
			licz = msgrcv(msqit,&ode_m,sizeof(ode_m),1,0);
			printf("Otrzymano: %d\n", licz); 
			s=s+licz;
		}
	}
	struct message M_WYNIK;
	M_WYNIK.m = s;
    M_WYNIK.rodzaj = 3;
  
    printf("Wynik: %d\n",s);
    
    return 0;
}

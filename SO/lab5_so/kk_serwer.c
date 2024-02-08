#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct buffer { 
	long typW; 
	int mesg; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	key = ftok("progfile", 65); //generacja klucza

	msgid = msgget(key, 0666 | IPC_CREAT); //podpiecie sie pod kk
	int pom=1,s=0;
	
	while(pom)
	{
		// msgrcv - odebranie wiadomosci
		msgrcv(msgid, &message, sizeof(message), 0, 0); //przedostatni argument oznacza jakie typy wiadomosci sa czytane, 0 - wszystkie
		
		if(message.typW==1)
		{
			printf("Odczytano komunikat M_DANE o wartosci: %d \n", message.mesg); 
			s = s+message.mesg;			
		}
		if(message.typW==2)
		{
			printf("Odczytano komunikat M_KONIEC o wartosci: %d \n", message.mesg); 
			s = s+message.mesg;	
			pom=0;			
		}
	}
	message.typW = 3;
	message.mesg = s;
	msgsnd(msgid, &message, sizeof(message), 0); //wysylanie wiadomosci	

	printf("Wyslano komunikat M_WYNIK: %d \n", s); 

	msgctl(msgid, IPC_RMID, NULL); //niszczenie kk na koniec programu
	return 0; 
} 

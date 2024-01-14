#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct buffer {
	long typW;
	int mesg;
} message;

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;
	int n = atoi(argv[1]);//int n jest wprowadzane przy wywolaniu programu, ilosc liczb
	int i;

	key = ftok("progfile", 65); //generacja klucza

	msgid = msgget(key, 0666 | IPC_CREAT); //podpiecie sie pod kk
	message.typW = 1; //1 = M_DANE,2 = M_KONIEC, 3 = M_WYNIK

	for(i=1;i<=n;i++)
	{
		if(i!=n)
		{
			printf("Podaj %d liczbe: ",i);
			scanf("%d", &message.mesg);
			msgsnd(msgid, &message, sizeof(message), 0); //wysylanie wiadomosci
		}
		else
		{
			message.typW = 2;
			printf("Podaj %d liczbe: ",i);
			scanf("%d", &message.mesg);
			msgsnd(msgid, &message, sizeof(message), 0); //wysylanie wiadomosci
		}
	}

	msgrcv(msgid, &message, sizeof(message), 0, 0);
	printf("Odczytano komunikat M_WYNIK o wartosci: %d \n", message.mesg);

	msgctl(msgid, IPC_RMID, NULL); //niszczenie kk na koniec programu
	return 0;
}

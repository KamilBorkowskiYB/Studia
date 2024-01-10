#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

sem_t *semafor;
sem_t *semPom;

sem_t *sem1do2;
sem_t *sem2do3;
sem_t *sem3do1;

void fn(void *arg, int process_id)
{
    printf("Konsument %d (%d) odczytalem: %s", process_id, getpid(), (char *)arg);
    sem_post(semPom);//pozwolenie napisania tekstu
}

int main()
{
    char *buffer;
    size_t bufsize = 32;
    pid_t k1, k2, k3;

    int sem_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);//tworzenie pamieci wspoldzielonej
	int semPom_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	int buf_shmid = shmget(IPC_PRIVATE, bufsize * sizeof(char), IPC_CREAT | 0666);

	int sem1do2_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	int sem2do3_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	int sem3do1_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);

    semafor = (sem_t *)shmat(sem_shmid, NULL, 0);//przypisanie semaforow do pamieci
	semPom = (sem_t *)shmat(semPom_shmid, NULL, 0);
	buffer = (char *)shmat(buf_shmid, NULL, 0);//przypisanie buffera do pamieci

	sem1do2 = (sem_t *)shmat(sem1do2_shmid, NULL, 0);//przypisanie semaforow pilnujacych kolejnosci do pamieci
	sem2do3 = (sem_t *)shmat(sem2do3_shmid, NULL, 0);
	sem3do1 = (sem_t *)shmat(sem3do1_shmid, NULL, 0);

    sem_init(semafor, 1, 0);//inicjalizacja semaforow
    sem_init(semPom, 1, 1);

    sem_init(sem1do2, 1, 0);//inicjalizacja semaforow pilnujacych kolejnosci
    sem_init(sem2do3, 1, 0);
    sem_init(sem3do1, 1, 1);//ten ktory ma na ostatni arguemnt jako 1 zacznie odczyt jako pierwszy


    if ((k1 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem3do1);//czekanie az k3 odczyta tekst
			for(int i=0;i<4;i++)
			{
			sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 1);
			}

            sem_post(sem1do2);//pozwolenie k2 na odczytanie tekstu
        }
    }

    if ((k2 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem1do2);//czekanie az k1 odczyta tekst
			for(int i=0;i<2;i++)
			{
			sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 2);
			}

            sem_post(sem2do3);//pozwolenie k3 na odczytanie tekstu
        }
    }

    if ((k3 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem2do3);//czekanie az k2 odczyta tekst
            sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 3);
            sem_post(sem3do1);//pozwolenie k1 na odczytanie tekstu
        }
    }

    while (1)
    {
		sem_wait(semPom);//czekanie na odczytanie tekstu
        printf("Podaj tekst: ");
        getline(&buffer, &bufsize, stdin);
        sem_post(semafor);//pozwolenie odczytu tekstu
    }

    shmdt(semafor);//odlaczanie semaforow i buffera od pamieci wspodzielonej
    shmdt(semPom);
    shmdt(buffer);

	shmdt(sem1do2);//odlaczanie semaforow pilnujacych kolejnosci od pamieci wspodzielonej
	shmdt(sem2do3);
	shmdt(sem3do1);



    shmctl(sem_shmid, IPC_RMID, NULL);//usuwanie pamieci wspodzielonej
    shmctl(semPom_shmid, IPC_RMID, NULL);
    shmctl(buf_shmid, IPC_RMID, NULL);

    shmctl(sem1do2_shmid, IPC_RMID, NULL);
	shmctl(sem2do3_shmid, IPC_RMID, NULL);
	shmctl(sem3do1_shmid, IPC_RMID, NULL);

    return 0;
}

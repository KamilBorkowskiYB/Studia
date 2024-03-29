#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

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

	int semPom_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);//tworzenie pamieci wspoldzielonej
	int buf_shmid = shmget(IPC_PRIVATE, bufsize * sizeof(char), IPC_CREAT | 0666);
	int sem1do2_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	int sem2do3_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);
	int sem3do1_shmid = shmget(IPC_PRIVATE, sizeof(sem_t), IPC_CREAT | 0666);

	semPom = (sem_t *)shmat(semPom_shmid, NULL, 0);//przypisanie semaforow do pamieci
	buffer = (char *)shmat(buf_shmid, NULL, 0);//przypisanie buffera do pamieci
	sem1do2 = (sem_t *)shmat(sem1do2_shmid, NULL, 0);
	sem2do3 = (sem_t *)shmat(sem2do3_shmid, NULL, 0);
	sem3do1 = (sem_t *)shmat(sem3do1_shmid, NULL, 0);

    sem_init(semPom, 1, 3);//inicjalizacja semaforow
    sem_init(sem1do2, 1, 0);
    sem_init(sem2do3, 1, 0);
    sem_init(sem3do1, 1, 0);


    if ((k1 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem3do1);//czekanie na napisanie tekstu
            fn((void *)buffer, 1);
        }
    }

    if ((k2 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem1do2);//czekanie na napisanie tekstu
            fn((void *)buffer, 2);
        }
    }

    if ((k3 = fork()) == 0)
    {
        while(1)
        {
			sem_wait(sem2do3);//czekanie na napisanie tekstu
            fn((void *)buffer, 3);
        }
    }

    while (1)
    {
		sem_wait(semPom);//czekanie na odczytanie tekstu przez kazdy proces potomny
		sem_wait(semPom);
		sem_wait(semPom);
        printf("Podaj tekst: ");
        getline(&buffer, &bufsize, stdin);

        sem_post(sem1do2);//pozwolenie odczytu kazdemu procesowi potomnemu
        sem_post(sem2do3);
        sem_post(sem3do1);
    }

    shmdt(semPom);//odlaczanie semaforow i buffera od pamieci wspodzielonej
    shmdt(buffer);
	shmdt(sem1do2);
	shmdt(sem2do3);
	shmdt(sem3do1);

    shmctl(semPom_shmid, IPC_RMID, NULL);//usuwanie pamieci wspodzielonej
    shmctl(buf_shmid, IPC_RMID, NULL);
    shmctl(sem1do2_shmid, IPC_RMID, NULL);
	shmctl(sem2do3_shmid, IPC_RMID, NULL);
	shmctl(sem3do1_shmid, IPC_RMID, NULL);

    return 0;
}

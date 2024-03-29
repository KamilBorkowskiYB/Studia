#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

sem_t *semafor;
sem_t *semPom;

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

    semafor = (sem_t *)shmat(sem_shmid, NULL, 0);//przypisanie semaforow do pamieci
	semPom = (sem_t *)shmat(semPom_shmid, NULL, 0);
	buffer = (char *)shmat(buf_shmid, NULL, 0);//przypisanie buffera do pamieci

    sem_init(semafor, 1, 0);//inicjalizacja semaforow
    sem_init(semPom, 1, 1);


    if ((k1 = fork()) == 0)
    {
        while(1)
        {
            sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 1);
        }
    }

    if ((k2 = fork()) == 0)
    {
        while(1)
        {
            sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 2);
        }
    }

    if ((k3 = fork()) == 0)
    {
        while(1)
        {
            sem_wait(semafor);//czekanie na napisanie tekstu
            fn((void *)buffer, 3);
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

    shmctl(sem_shmid, IPC_RMID, NULL);//usuwanie pamieci wspodzielonej
    shmctl(semPom_shmid, IPC_RMID, NULL);
    shmctl(buf_shmid, IPC_RMID, NULL);

    return 0;
}

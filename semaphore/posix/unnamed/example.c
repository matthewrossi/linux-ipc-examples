#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex_sem;

int main (int argc, char **argv)
{
    if (sem_init (&mutex_sem, 0, 1) == -1) {
        perror ("sem_init"); exit (1);
    }

    sleep(10);

    if (sem_destroy (&mutex_sem) == -1) {
        perror ("sem_destroy"); exit (1);
    }
    exit (0);
}

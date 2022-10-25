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

#define SEM_MUTEX_NAME "/sem-mutex"

sem_t *mutex_sem;


int main (int argc, char **argv)
{
    if ((mutex_sem = sem_open (SEM_MUTEX_NAME, O_CREAT, 0660, 1)) == SEM_FAILED) {
        perror ("sem_open"); exit (1);
    }
    
    // SLEEP
    sleep(10);

    if (sem_unlink (SEM_MUTEX_NAME) == -1) {
        perror ("sem_unlink"); exit (1);
    }

    exit (0);
}

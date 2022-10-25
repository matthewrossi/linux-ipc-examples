/*
 *
 *       logger.c: Write strings in POSIX shared memory to file
 *                 (Server process)
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_BUFFERS 10
#define SHARED_MEM_NAME "/posix-shared-mem-example"

struct shared_memory {
    char buf [MAX_BUFFERS] [256];
    int buffer_index;
    int buffer_print_index;
};

int main (int argc, char **argv)
{
    struct shared_memory *shared_mem_ptr;
    int fd_shm;
    char mybuf [256];

    if ((fd_shm = shm_open (SHARED_MEM_NAME, O_RDWR | O_CREAT | O_EXCL, 0660)) == -1)
        perror ("shm_open");

    if (ftruncate (fd_shm, sizeof (struct shared_memory)) == -1)
       perror ("ftruncate");

    if ((shared_mem_ptr = mmap (NULL, sizeof (struct shared_memory), PROT_READ | PROT_WRITE, MAP_SHARED,
            fd_shm, 0)) == MAP_FAILED)
       perror ("mmap");

    sleep(10);

    if (shm_unlink (SHARED_MEM_NAME) == -1) {
        perror ("shm_unlink"); exit (1);
    }

    return EXIT_SUCCESS;
}

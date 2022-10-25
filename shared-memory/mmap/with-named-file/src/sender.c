#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <sys/mman.h>

#include "connection.h"

int main() {
#ifdef SHM
    int fd = shm_open(SHARED_MEMORY_NAME,O_RDWR | O_CREAT, 0644);
#else
    int fd = open(SHARED_FILE, O_RDWR | O_CREAT, 0644);
#endif
    ftruncate(fd, SIZE);
    char *shmem = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    strcpy(shmem, "Hello, world!");
    close(fd);
    return EXIT_SUCCESS;
}

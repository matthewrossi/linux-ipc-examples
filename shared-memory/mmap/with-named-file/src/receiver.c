#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/mman.h>

#include "connection.h"

int main() {
#ifdef SHM
    int fd = shm_open(SHARED_MEMORY_NAME, O_RDWR, 0644);
#else
    int fd = open(SHARED_FILE, O_RDWR, 0644);
#endif
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    void *shmem = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("%s\n", (char *) shmem);

    close(fd);
#ifdef SHM
    shm_unlink("/abc");
#else
    unlink("/tmp/abc");
#endif

    return EXIT_SUCCESS;
}

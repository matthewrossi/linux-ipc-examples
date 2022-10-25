#define _GNU_SOURCE

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define N 5

int main() {  
    int fd = open("/tmp", O_TMPFILE | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }
    ftruncate(fd, N * sizeof(int));

    int *ptr = mmap(NULL, N * sizeof(int), PROT_READ | PROT_WRITE,
                    MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < N; i++)
        ptr[i] = i + 1;
    printf("Initial values:");
    for (int i = 0; i < N; i++)
        printf(" %d", ptr[i]);
    printf("\n");

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        close(fd);
        return EXIT_FAILURE;
    }

    if (child_pid == 0) {
        // Child process
        printf("<Child> Updating array values...\n");
        for (int i = 0; i < N; i++)
            ptr[i] = ptr[i] * 10;
    } else {
        // Parent process
        waitpid(child_pid, NULL, 0);

        printf("<Parent> Current array values:");
        for (int i = 0; i < N; i++)
            printf(" %d", ptr[i]);
        printf("\n");
    }

    int err = munmap(ptr, N * sizeof(int));
    if(err != 0) {
        perror("munmap");
        close(fd);
        return EXIT_FAILURE;
    }

    close(fd);
    return EXIT_SUCCESS;
}

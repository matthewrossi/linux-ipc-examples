#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int result;
    if (argc != 2) {
        fprintf(stderr, "Usage %s sockname\n", argv[0]);
        return EXIT_FAILURE;
    }

    result = mknod(argv[1], S_IFSOCK | 0600, 0);
    if (result < 0) {
        perror("mknod");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

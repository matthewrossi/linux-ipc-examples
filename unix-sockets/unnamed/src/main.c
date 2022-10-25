#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define CHILDDATA "Hello parent, from child"
#define PARENTDATA "Hello child, from parent"

/*
 * This program creates a pair of connected sockets, then forks and
 * communicates over them.  This is very similar to communication with pipes;
 * however, socketpairs are two-way communications objects. Therefore,
 * this program can send messages in both directions.
 */

int main()
{
    int rc;
    int sockets[2];
    pid_t pid;
    char buf[256];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
    } else if (!pid) {      /* This is the child */
        close(sockets[0]);  /* Close the parent's socket */

        rc = write(sockets[1], CHILDDATA, sizeof(CHILDDATA));
        if (rc == -1)
            perror("writing stream message");
        
        rc = read(sockets[1], buf, sizeof(buf));
        if (rc == -1)
            perror("reading stream message");
        printf("%s\n", buf);
        close(sockets[1]);
    } else {                /* This is the parent */
        close(sockets[1]);  /* Close the child's socket */

        rc = read(sockets[0], buf, sizeof(buf));
        if (rc == -1)
            perror("reading stream message");
        printf("%s\n", buf);

        rc = write(sockets[0], PARENTDATA, sizeof(PARENTDATA));
        if (rc == -1)
            perror("writing stream message");
        close(sockets[0]);
    }

    exit(EXIT_SUCCESS);
}

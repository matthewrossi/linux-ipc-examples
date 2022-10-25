#include <stdio.h>
#include <stdlib.h>

// Buffer data structures
#define MAX_BUFFERS 10

#define LOGFILE "/tmp/example.log"

#define SEM_MUTEX_NAME "/sem-mutex"
#define SEM_BUFFER_COUNT_NAME "/sem-buffer-count"
#define SEM_SPOOL_SIGNAL_NAME "/sem-spool-signal"
#define SHARED_MEM_NAME "/posix-shared-mem-example"

struct shared_memory {
    char buf [MAX_BUFFERS] [256];
    int buffer_index;
    int buffer_print_index;
};

void error (char *msg);

// Print system error and exit
void error (char *msg)
{
    perror (msg);
    exit (1);
}

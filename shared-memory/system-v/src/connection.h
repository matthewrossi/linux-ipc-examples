#include <stdio.h>
#include <stdlib.h>

// Buffer data structures
#define MAX_BUFFERS 10
#define SHARED_MEMORY_KEY "/tmp/shared_memory_key"
#define SEM_MUTEX_KEY "/tmp/sem-mutex-key"
#define SEM_BUFFER_COUNT_KEY "/tmp/sem-buffer-count-key"
#define SEM_SPOOL_SIGNAL_KEY "/tmp/sem-spool-signal-key"
#define PROJECT_ID 'K'

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

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/syscall.h>

int main(int argc, char* argv[])
{
    syscall(SYS_tkill, atoi(argv[1]), SIGTERM); 
    return 0;
}

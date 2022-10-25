#include <signal.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    syscall(SYS_tgkill, atoi(argv[1]), atoi(argv[2]), SIGTERM);
    return 0;
}

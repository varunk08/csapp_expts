#include "csapp.h"

int main()
{
    pid_t pid;

    if ((pid = Fork()) == 0)
    {
        Pause();
        printf("control should never reach here!\n");
        exit(0);
    }

    printf("killing process group. pid=%d\n", pid);
    Kill(pid, SIGKILL);
    exit(0);
}
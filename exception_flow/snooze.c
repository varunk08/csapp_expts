#include "../csapp_code/include/csapp.h"

unsigned int secs;

void sigint_handler(int sig)
{
    printf("Caught SIGINT\n");
    return;
    
}

unsigned int snooze(unsigned int secs)
{
    unsigned int ret = sleep(secs);

    printf("Slept for %d of %d secs.\n", secs - ret, secs);
    exit(0);
    //printf("Slept for %d of %d secs.\n", secs - ret, secs);


//    return ret;
}


int main(int argc, char* argv[])
{

    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        unix_error("signal error\n");
    }

    secs = atoi(argv[1]);
    printf("secs: %d\n", secs);
    int i = snooze(secs);
    return 0;
}
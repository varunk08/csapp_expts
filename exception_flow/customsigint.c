#include "../csapp_code/include/csapp.h"


void sigint_handler(int sig)
{
    printf("Caught SIGINT!\n");
    exit(0);
}


int main()
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        unix_error("Signal error\n");
    }

    pause();

    return 0;
}
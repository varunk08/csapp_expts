#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int ret = 0;
    ret = sleep(secs);

    printf("Slept for %d secs.\n", ret);


    return ret;
}


int main()
{
    int i = snooze(5);
    exit(0);
}
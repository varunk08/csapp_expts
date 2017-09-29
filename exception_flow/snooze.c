#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs)
{
    unsigned int ret = sleep(secs);

    printf("Slept for %d of %d secs.\n", secs - ret, secs);


    return ret;
}


int main()
{
    int i = snooze(5);
    return 0;
}
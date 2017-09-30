#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "csapp.h"


/* program to print its command line arguments and environment strings */


int main(int argc,
         char* argv[],
         char* envp[])
{
    printf("argc=%d\n",argc);
    
    int i = 0;
    for(i = 0; i < argc; i++)
    {
        printf("argv[%d]=%s\n",i , argv[i]);
    }

    i = 0;
    while ( envp[i] != NULL )
    {
        printf("envp[%d] : %s\n", i, envp[i]);
        i++;
    }

    return 0;
}
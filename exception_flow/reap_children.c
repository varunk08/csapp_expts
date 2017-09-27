#include "../csapp_code/include/csapp.h"
#define N 6
/*
build command: gcc -pthread reap_children.c ../csapp_code/src/csapp.c -I"/home/varun/csapp/csapp_code/include" -o reap

*/

int main()
{
    int status, i;
    pid_t pid;

    /* Parent creates N children */
    for (i = 0; i < N; i++)
    {
        if ((pid = Fork()) == 0) // Fork returns 0 if its a child.
        {
            exit(100 + i);
        }
    }

    /* Parent reap N children in no particular order */
    while ((pid = waitpid(-1, &status, 0)) > 0)
    {
        if (WIFEXITED(status))
        {
            printf("child %d terminated normally with exit status==%d\n", pid, WEXITSTATUS(status));
        }
        else
        {
            printf("child %d terminated abnormally\n", pid);
        }
    }


    /* The only normal termination is if there are no more children */
    if (errno != ECHILD)
    {
        unix_error("waitpid error");
    }

    exit(0);
}
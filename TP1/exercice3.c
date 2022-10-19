#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pidFork;
    pidFork = fork();
    int etat;

    switch (pidFork)
    {
    case -1:
        printf("Creation du fils à échoué \n");
        exit(EXIT_FAILURE);
        break;

    case 0:
        execl("unix","ps", (char *) NULL);
        exit(EXIT_SUCCESS);
        break;       
           
    default:
        wait(&etat);
        printf("Exit code: %d\n", WEXITSTATUS(etat));
        exit(EXIT_SUCCESS);
        break;
    }

    return 0;
}
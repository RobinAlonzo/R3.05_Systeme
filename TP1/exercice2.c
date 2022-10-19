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
        for (int i = 0; i <= 10; i=i+2)
        {
            sleep(1); //c
            printf("La valeur pair %d\n", i);
        }
        exit(EXIT_SUCCESS);
        break;       
           
    default:
        for (int i = 1; i < 10; i=i+2)
        {
            //sleep(1); //b
            printf("La valeur impair %d\n", i);
        }
        
        wait(&etat);
        exit(EXIT_SUCCESS);
        break;
    }

    return 0;
}
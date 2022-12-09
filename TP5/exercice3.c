#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int attente;

void signalPere()
{
    printf("Signal père\n");
    attente = 1;
}

int main(void)
{
    pid_t pidFork;
    pidFork = fork();
    int etat;
    int attente;

    switch (pidFork)
    {
    case -1:
        printf("Creation du fils à échoué \n");
        exit(EXIT_FAILURE);
        break;

    case 0:
        printf("Signal fils\n");
        attente = 0;
        while (attente = 0)
        {
            printf("Dans boucle\n");
        }
        exit(EXIT_SUCCESS);
        break;       
           
    default:
        sleep(5);
        signal(SIGUSR1, signalPere);
        wait(&etat);
        if (WEXITSTATUS(etat) == EXIT_SUCCESS)
        {
            printf("Le processus c'est terminé sans erreur. Exit code: %d\n", WEXITSTATUS(etat));
        }
        else
        {
            printf("Le processus c'est terminé avec une erreur. Exit code: %d\n", WEXITSTATUS(etat));
        }
        exit(EXIT_SUCCESS);
        break;
    }

    return 0;
}
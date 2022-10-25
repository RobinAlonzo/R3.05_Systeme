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
        //execlp("ps","ps", (char *) NULL); //Recherche dans tous le repertoire la commande
        execl("/bin/ps","ps", (char *) NULL); //Recherche dans le repertoire donné
        exit(EXIT_SUCCESS);
        break;       
           
    default:
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
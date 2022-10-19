#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 

#define _XOPEN_SOURCE 600

int main(void)
{
    pid_t pidFork;
    pidFork = fork();
    printf("Je suis le processus numero %d \n", getpid());
    printf("Fork m'a renvoyé la valeur %d \n", pidFork);
    printf("Je suis le processus numero %d et mon père et le numéro %d\n", getpid(), getppid());

    return 0;
}
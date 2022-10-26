#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

pthread_attr_t attr; //Attributs de création
pthread_t thread_id; //Identificateur du thread créé

pthread_attr_t attr2; //Attributs de création
pthread_t thread_id2; //Identificateur du thread crée

void mon_thread()
{
    printf("Coucou je suis le thread 1\n");
    pthread_exit(NULL);
}

void mon_thread2()
{
    printf("Coucou je suis le thread 2\n");
    char c;
    printf("Tapez un caractère : \n");
    c = getchar();
    printf("%d\n",c);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_attr_init(&attr); //Init des attributs à leur valeur par défaut
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread_id, &attr, (void *)mon_thread, NULL); //Création du thread

    pthread_attr_init(&attr2); //Init des attributs à leur valeur par défaut
    pthread_attr_setdetachstate(&attr2, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread_id2, &attr2, (void *)mon_thread2, NULL); //Création du thread  

    printf("Les deux threads sont lancés\n");

    pthread_join(thread_id2, NULL); //Attente de terminaison du thread 2

    printf("On va s'arrêter là \n");
    
    exit(EXIT_SUCCESS);
    return 0;
}

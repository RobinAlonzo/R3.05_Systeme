#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

pthread_attr_t attr; //Attributs de création
pthread_t thread_id; //Identificateur du thread créé

pthread_attr_t attr; //Attributs de création
pthread_t thread_id2; //Identificateur du thread créé

unsigned long compteur = 0;

void monCompteur()
{
    unsigned long tmp; //Initialisation du compteur
    for (int i = 0; i < 10000000; i++)
    {
        tmp = compteur;
        tmp = tmp + 1;
        compteur = tmp;
    }

    pthread_exit(NULL);
}

int main(void)
{

    pthread_attr_init(&attr); //Init des attributs à leur valeur par défaut
    pthread_create(&thread_id, &attr, (void *)monCompteur, NULL); //Création du thread

    pthread_attr_init(&attr); //Init des attributs à leur valeur par défaut
    pthread_create(&thread_id2, &attr, (void *)monCompteur, NULL); //Création du thread

    pthread_join(thread_id, NULL); //Attente de terminaison du thread 1
    pthread_join(thread_id2, NULL); //Attente de terminaison du thread 2

    printf("Le compteur = %lu\n",compteur);
    
    exit(EXIT_SUCCESS);
    return 0;
}
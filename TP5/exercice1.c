#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <signal.h>
#include <time.h>

//Procédure permettant d'indiquer que le signal est reçu
void fin() 
{
    printf("Signal reçu\n");
}

int main(void)
{
    //Variables
    bool etat = true;

    //Boucle infinie
    while (etat)
    {
        //Affichae d'un point
        printf(".\n");

        //Permet d'ignorer la commande CTRL +C
        signal(SIGINT, fin);
        sleep(2);
    }
    
    
    return 0;
}

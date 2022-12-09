#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <signal.h>
#include <time.h>

//Variables
bool etat = true;

//Procédure permattant d'indiquer que le signal est reçu
void loupe()
{
    printf("Loupé\n"); 
    etat = false;
}

int main(void)
{
    //Boucle infinie
    while (true)
    {
        //Affichae d'un point
        printf(".\n");
        sleep(1);

        //Permet d'ignorer la commande CTRL + Z
        if (etat)
        {
            signal(SIGTSTP, loupe);
        }
        else
        {
            signal(SIGTSTP, SIG_DFL);
        }
    }
    
    
    return 0;
}

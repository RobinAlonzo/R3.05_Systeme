#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>

pthread_attr_t attr;
pthread_t thread_id;

pthread_attr_t attr2;
pthread_t thread_id2;

void mon_thread()
{
    while (1)
    {
        printf(".\n");
    }
    
    pthread_exit(NULL);
}

void mon_thread2()
{
    char c;
    printf("Tapez un caractère : \n");
    c = getchar();
    pthread_exit(NULL);
}

int main(void)
{
    pthread_attr_init(&attr);
    pthread_create(&thread_id, &attr, (void *)mon_thread, NULL);

    pthread_attr_init(&attr2);
    pthread_create(&thread_id2, &attr2, (void *)mon_thread2, NULL);    

    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);

    exit(EXIT_SUCCESS);
    return 0;
}

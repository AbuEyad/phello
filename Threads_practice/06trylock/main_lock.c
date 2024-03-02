#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void *routine(void *arg){
    pthread_mutex_lock(&mutex);
    printf("Got lock\n");
    sleep(1);
    pthread_mutex_unlock(&mutex);
    return 0;
}
 
int main(int arg, char *argv[]){
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    for(int i = 0; i < 4; i++){
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0){
            perror("Failed to create thread \n");
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join thread \n");
        }
    }
    return (0);
}
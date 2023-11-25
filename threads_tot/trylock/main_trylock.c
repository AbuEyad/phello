#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutex;

//in "trylock" the thread will not wait for the unlock if it is already locked.

void *routine(void *arg){
    if(pthread_mutex_trylock(&mutex) == 0){ 
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }else{
        printf("Didn't get lock\n");
    }
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
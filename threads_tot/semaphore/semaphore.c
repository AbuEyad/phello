#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *args){
    sem_wait(&semaphore);
    sleep(1);
    printf("hello from routine %d\n", *(int*)args);
    sem_post(&semaphore);
    free(args);
}

int main(int argc, char *argv[]){
    pthread_t th[THREAD_NUM];
    // pthread_init(&th);
    sem_init(&semaphore, 0, 1);
    int *a = malloc(sizeof(int));
    int i;

    for (i = 0; i < THREAD_NUM; i++){
        *a = i;
        if(pthread_create(&th[i], NULL, &routine, a) != 0)
            perror("Failed to create thread");
    }

    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread");
    }
    sem_destroy(&semaphore);
    return (0);
}

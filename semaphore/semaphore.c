#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <semaphore.h>
// #include "pth_barrier.h"

#define THREAD_NUM 4

sem_t semaphore;

void *routine(void *args){
  
}

int main(int argc, char *argv[]){
    pthread_t th[THREAD_NUM];

    int i;
    for (i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
    }

    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread");
    }

    return (0);
}

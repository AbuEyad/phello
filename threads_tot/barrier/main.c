#include "pth_barrier.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_barrier_t barrier;

void *routine() {
    printf("Waiting ad the barrier...\n");
    pthread_barrier_wait(&barrier);
    printf("We passed the barrier\n");
}

int main(int argc, char *argv[]){
    pthread_t th[3];
    pthread_barrier_init(&barrier, NULL, 3);
    for(int i = 0; i < 2; i++){
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0){
            perror("Failed to create thread\n");
        }
    }
    for(int i = 0; i < 2; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join thread\n");
        }
    }
    pthread_barrier_destroy(&barrier);
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
// #include "pth_barrier.h"

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;
pthread_mutex_t mutexWater;
int water = 10;

void *routine(void *args){
    if(rand()% 2 == 0){
        pthread_mutex_lock(&mutexFuel); // the order of the locking is switched and this might lead to a deadlock;
        sleep(1);
        pthread_mutex_lock(&mutexWater); // it is possible to lock water twice now. 
    } else {
        pthread_mutex_lock(&mutexWater);
        pthread_mutex_lock(&mutexFuel);
    }

    fuel += 50;
    water = fuel;
    printf("Incremented Fuel to : %d set water to %d\n", fuel, water);
    pthread_mutex_unlock(&mutexFuel);
    pthread_mutex_unlock(&mutexWater);
    
}

int main(int argc, char *argv[]){
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_mutex_init(&mutexWater, NULL);
    int i;

    for (i = 0; i < THREAD_NUM; i++){
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread");
    }

    for(i = 0; i < THREAD_NUM; i++){
        if(pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread");
    }
    printf("Fuel: %d\n", fuel);
    printf("Water: %d\n", water);
    pthread_mutex_destroy(&mutexFuel);
    pthread_mutex_destroy(&mutexWater);

    return (0);
}

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
//fuel statin being filled and a car waiting to start filling.

pthread_mutex_t mutex_fuel;
pthread_cond_t cond_fuel;
int fuel = 0;

void *fuel_filling(void *arg){
    for(int i = 0; i < 5; i++) { //filling the station 5 times sleep after each fill.
        pthread_mutex_lock(&mutex_fuel);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutex_fuel);
        pthread_cond_signal(&cond_fuel);
        sleep(1);
    }
}

void *car(void *arg){
    pthread_mutex_lock(&mutex_fuel);
    while(fuel < 40){
        printf("No fuel waiting....\n");
        // this call will unlock mutex_fuel and wait for the signal
        pthread_cond_wait(&cond_fuel, &mutex_fuel);
        //Equivalent to :
        // phtread_mutex_unlock(&mutex_fuel);
        // wait for signal on cond_fuel
        // pthread_mutex_lock(&mutex_fuel)
    }
    fuel -= 40;
    printf("Got fuel now left: %d\n", fuel);
    pthread_mutex_unlock(&mutex_fuel);
}

int main(int argc, char *argv[]){
    pthread_t th[2];
    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_cond_init(&cond_fuel, NULL);
    for(int i = 0; i < 2; i++){
        if(i == 1){
            if(pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0){
                perror("Failed to create thread");
            }
        }else{
             if(pthread_create(&th[i], NULL, &car, NULL) != 0){
                perror("Failed to create thread");
            }
        }
    }

    for(int i = 0; i < 2; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutex_fuel);
    pthread_cond_destroy(&cond_fuel);
    return (0);
}
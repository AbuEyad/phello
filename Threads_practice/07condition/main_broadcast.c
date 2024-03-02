#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
//fuel statin being filled and a car waiting to start filling.
//with broadcast signal all threads will be signaled to check for fuel;

pthread_mutex_t mutex_fuel;
pthread_cond_t cond_fuel;
int fuel = 0;

void *fuel_filling(void *arg){
    int *a = (int*)arg;

    for(int i = 0; i < 5; i++) { //filling the station 5 times sleep after each fill.
        pthread_mutex_lock(&mutex_fuel);
        fuel += 30;
        printf("%d: Filled fuel... %d\n",*a, fuel);
        pthread_mutex_unlock(&mutex_fuel);
        pthread_cond_broadcast(&cond_fuel); //will broadcast all threads.
        sleep(1);
    }
}

void *car(void *arg){
    int *a = (int*)arg;
    pthread_mutex_lock(&mutex_fuel);
    while(fuel < 40){
        printf("No fuel waiting....\n");
        // this call will unlock mutex_fuel and wait for the signal
        pthread_cond_wait(&cond_fuel, &mutex_fuel);
        //Equivalent to :
        // phtread_mutex_unlock(&mutex_fuel);
        // wait for signal on cond_fuel
        // pthread_mutex_lock(&mutex_fuel);
    }
    fuel -= 40;
    printf("%d: Got fuel now left: %d\n",*a , fuel);
    pthread_mutex_unlock(&mutex_fuel);
}

int main(int argc, char *argv[]){
    pthread_t th[5];
    pthread_mutex_init(&mutex_fuel, NULL);
    pthread_cond_init(&cond_fuel, NULL);
    int *a = malloc(sizeof(int));
    *a = 0;
    for(int i = 0; i < 6; i++){
        *a = i;
        if(i == 4 || i == 5){
            if(pthread_create(&th[i], NULL, &fuel_filling, a) != 0){
                perror("Failed to create thread");
            }
        }else{
             if(pthread_create(&th[i], NULL, &car, a) != 0){
                perror("Failed to create thread");
            }
        }
    }

    for(int j = 0; j < 6; j++){
        if(pthread_join(th[j], NULL) != 0){
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutex_fuel);
    pthread_cond_destroy(&cond_fuel);
    return (0);
}
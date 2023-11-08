#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void *roll_dice() {
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    sleep(2);
    printf("Thread result: %d\n", value);
    pthread_exit((void *) result);
}

int main(int argc, char *argv[]){
    int *res;
    srand(time(NULL));
    pthread_t th;
    if(pthread_create(&th, NULL, &roll_dice, NULL) != 0){
        return 1;
    }
    // return 0; // will terminate the process and not waiting for the thread to complete
    // exit(0); // will terminate the process and not waiting for the thread to complete
    pthread_exit(0); // will waite for the thread to complete first.
    if(pthread_join(th, (void **) &res) != 0){
        return 2;
    }
    printf("result: %d\n", *res);
    free(res);
    return 0;
}
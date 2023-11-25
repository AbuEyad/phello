#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// the problem: create 10 threads, each taking a unique prime from the primes array
// and print it on the screa.

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(){
    static int i;
    printf("%d ", primes[i]);
    i++;
    return 0;
}
 
int main(int arg, char *argv[]){
    pthread_t th[10];
    int i;
    for(i = 0; i < 10; i++){
        if(pthread_create(th + i, NULL, &routine, NULL) != 0){
            perror("Failed to create thread \n");
        }
    }
    for (i = 0; i < 10; i++)
    {
        if(pthread_join(th[i], NULL) != 0){
            perror("Failed to join thread \n");
        }
    }
    return (0);
}
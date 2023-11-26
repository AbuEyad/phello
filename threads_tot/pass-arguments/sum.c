#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// the problem: two threads each sums half of the array, 
// and the main function sums both halfs.

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *arg){
    int index = *(int*)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++){
        sum += primes[index + i];
    }
    printf("Local sum[%d - %d] = %d\n",*(int*)arg, *(int*)arg + 5, sum);
    *(int*)arg = sum;
    return arg;
}
 
int main(int arg, char *argv[]){
    pthread_t th[2];
    int i;
    for(i = 0; i < 2; i++){
        int *a = malloc(sizeof(int));
        // 0 * 5 = [0] ; 1 * 5 = [5] 
        // --> th1 sums from index 0 to 5, th2 sums from 5 to end.
        *a = i * 5; 
        if(pthread_create(th + i, NULL, &routine, a) != 0){
            perror("Failed to create thread \n");
        }
    }

    int globalSum = 0;
    for (i = 0; i < 2; i++) {
        int *r;
        if(pthread_join(th[i],(void **)&r) != 0){
            perror("Failed to join thread \n");
        }
        globalSum += *r;
        free(r);
    }
    printf("Global Sum = %d\n", globalSum);
    return (0);
}
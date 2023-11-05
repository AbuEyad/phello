
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine(){
    // printf("PID = %d\n", getpid());
    x++;
    sleep(2);
    printf("Value of x: %d\n", x);
    return 0;
}
void *routine2(){
    // printf("PID = %d\n", getpid());
    sleep(2);
    printf("Value of x: %d\n", x);
    return 0;
}

int main(int argc, char *argv[]){
    int x = 1;
    pthread_t t1, t2;
    if(pthread_create(&t1, NULL, &routine, NULL)){
        return 1;
    }
    if(pthread_join(t1, NULL)){
      if(pthread_create(&t2, NULL, &routine2, NULL)){
        return 3;
    }
        return 2;
    }
    if(pthread_join(t2, NULL)){
        return 4;
    }

    return (0);
}

// gcc -g -pthread main.c -o main
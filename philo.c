#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("yer: %ld\n", tv.tv_sec/60/60/24/365);
    
    return 0; 
}
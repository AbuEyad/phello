#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int main()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("yer: %ld\n", tv.tv_sec/60/60/24/365);
    
    return 0; 
}
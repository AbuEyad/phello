#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void *routine() {

    for(int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t th[4];
    
    pthread_mutex_init(&mutex, NULL);
    
    for(int i = 0; i < 4; i++)
    {
        if(pthread_create(&th[i], NULL, &routine, NULL) != 0){printf("Failed to Create trhead");return i;}

        // if you create and join threads in the same loop , they will run sequentially not in parallel
        printf("Thread[%d] started\n", i);
        if(pthread_join(th[i], NULL) != 0){return i;}
        printf("Trhead[%d] finished\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails = %d\n", mails);
}
// output will be: //
/*
Thread[0] started
Trhead[0] finished
Thread[1] started
Trhead[1] finished
Thread[2] started
Trhead[2] finished
Thread[3] started
Trhead[3] finished
Number of mails = 4000000

*/
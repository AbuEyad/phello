//lib
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//struct int & mutex ptrs
typedef struct s_mut
{
    pthread_mutex_t *mutex;
    int *ctr;
} t_mut;

//routine func.
void *f(void *arg)
{
    t_mut *t;

    t = arg;
    for(int i = 0; i < 10000; i++)
    {
        pthread_mutex_lock(t->mutex);
        (*t->ctr)++;
        pthread_mutex_unlock(t->mutex);
    }
    return(NULL);
}

//main func.

int main()
{
    int ctr = 0;
    pthread_t thread1;
    pthread_t thread2;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);

    t_mut t;

    t.ctr = &ctr;
    t.mutex = &mutex;
    pthread_create(&thread1, NULL, &f, &t);
    pthread_create(&thread2, NULL, &f, &t);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    printf("ctr = %d\n", ctr);
    return(0);
}

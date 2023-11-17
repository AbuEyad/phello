#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *print_hello(void *arg);
void *print_world(void *arg);

void exit_on_error(int *num, int exit_code)
{
    free(num);
    exit(exit_code);
}

void *routine(void *arg)
{
    int *num;
    int i;
    
    num = (int*)arg;
    i = 0;
    while(i < 1000000)
    {
        (*num)++;
        i++;
    }
    return(NULL);
}
void example_3()
{
    int *num;
    pthread_t t1;
    pthread_t t2;

    num = malloc(sizeof(int));
    if(num == NULL)
        exit(1);
    *num = 0;
    if(pthread_create(&t1, NULL, routine, num))
        exit_on_error(num, 2);
    if(pthread_create(&t2, NULL, routine, num))
        exit_on_error(num, 2);

    if(pthread_join(t1, NULL))
        exit_on_error(num, 2);
    if(pthread_join(t2, NULL))
        exit_on_error(num, 2);
    printf("Num: %d\n", *num);
}

void example_2()
{
    pthread_t t1;
    pthread_t t2;

    if(pthread_create(&t1, NULL, print_hello, NULL))
        exit(1);
    if(pthread_create(&t2, NULL, print_world, NULL))
        exit(1);

    if(pthread_join(t1, NULL))
        exit(1);
    if(pthread_join(t2, NULL))
        exit(1);
}

void *print_hello(void *arg)
{
    int i;

    i = 0;
    while(i < 100)
    {
        printf("Hello\n");
        i++;
        usleep(10000);
    }
    return(NULL);
}

void *print_world(void *arg)
{
    int i;

    i = 0;
    while(i < 100)
    {
        printf("\t\tWorld\n");
        i++;
        usleep(10000);
    }
    return(NULL);
}

void example_1()
{
    print_hello(NULL);
    print_world(NULL);
}

int main()
{
    // example_1();
    example_2();
    // example_3();


    return(0);
}

#include "philo.h"

void put_char(char c, int fd)
{
    write(fd, &c, 1);
}

void put_string(char *s, int fd)
{
    int i;

    i = 0;
    if(!s)
        return;
    while(s[i])
        put_char(s[i++], fd);
}

int is_digit(char *str)
{
    while(*str)
    {
        if(*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return(1);
}

int is_int(char *str)
{
    int i;
    long int result;

    i = 0;
    result = 0;
    while(str[i])
    {
        if(result > 2147483647 || (result * 10 + str[i] - '0'))
            return(-1);
        result = result * 10 + str[i] - '0';
        i++;
    }
    return(1);
}

int atoi_philo(char *str)
{
    int i;
    long int result;

    i = 0;
    result = 0;
    while(str[i])
        result = result * 10 + str[i++] - '0';
    return(result);
}

long int    get_time_now(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void    new_sleap(int mil_sec)
{
    long int start_time;

    start_time = get_time_now();
    while((get_time_now() -start_time) < mil_sec)
        usleep(100);
}

int wait_threads(t_table *table)
{
    int i;

    i = 0;
    while(i++ < table -> philos_num)
        pthread_join(table -> threads[i], NULL);
    return(1);
    
}
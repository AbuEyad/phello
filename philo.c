#include "philo.h"


int init_threads(t_table *table)
{
    int i;

    i = 0;
    table -> start_time = get_time_now();
    while(i < table -> philos_num)
        pthread_create(&table -> threads[i], NULL,
         &philo_routine, &table -> philos[i]);
    return(1);
}


int philo_alive(t_philo *philo)
{
    if(!philo -> stop)
    {
        return(1);
    }
    return (0);
}

void *philo_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *) arg;
    if(philo -> philo_id % 2 == 0)
        new_sleep(philo -> time_to_eat * 0.9);
    while(philo_alive(philo))
    {
        if(meal(philo) == -1)
            return(NULL);
        if(!philo_alive(philo))
            return(NULL);
        printf_info(philo, "sleeping");
        new_sleap(philo -> time_to_sleep);
        printf_info(philo, "thinking");
    }
}

void init_philo(t_table *table, t_philo *philo)
{
    int i;

    i = -1;
    while(++i < table->philos_num)
    {
        philo[i].philo_id = i + 1;
        philo[i].start_time = &table->start_time;
        philo[i].left_fork = &table->forks[i];
        if(table->philos_num > 1)
            philo[i].right_fork = &table->forks[(i + 1) 
                % table->philos_num]; // last one will take the first
        else
            philo[i].right_fork = NULL;
        philo[i].ate_x_times = 0;
        philo[i].eat_x_times = table->eat_x_times;
        philo[i].last_meal_time = get_time_now();
        philo[i].stop = 0;
        philo[i].time_to_die = table->time_to_die;
        philo[i].time_to_eat = table->time_to_eat;
        philo[i].time_to_sleep = table->time_to_sleep;
        philo[i].already_ate_max = &table->already_ate_max;
        philo[i].main_lock = &table->main_lock;
        philo[i].priv_lock = &table->priv_lock[i];
        philo[i].write_message = &table->write_message;
    }
}

int init_all(t_table *table)
{
    table->philos = malloc(sizeof(t_philo) * table->philos_num);
    table->threads = malloc(sizeof(pthread_t) * table->philos_num);
    table->already_ate_max = 0;
    init_philo(table, table->philos);
}

void    set_arguments(t_table *table, int argc, char **argv)
{
    table->philos_num = atoi_philo(argv[1]);
    table->time_to_die = atoi_philo(argv[2]);
    table->time_to_eat = atoi_philo(argv[3]);
    table->time_to_sleep = atoi_philo(argv[4]);
    if(argc == 6)
    {
        table->eat_x_times = atoi_philo(argv[5]);
        if(table->eat_x_times < 0)
            printf("The number of meals can't be negative\n");
    }
    else
        table->eat_x_times = 0;
}

int main(int argc, char* argv[])
{
    t_table *table;

    table = malloc(sizeof(t_table));
    set_arguments(table, argc, argv);
    if(init_all(table) == -1)
        return(1);
    control(table, table->philos);
    wait_threads(table);
    free_all(table);
    return 0; 
}
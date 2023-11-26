#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
    int				philo_id;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				eat_x_times;
	int				ate_x_times;
	int				*already_ate_max;
	long int		last_meal_time;
	long int		*start_time;
	int				stop;
    pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	*write_message;
}   t_philo;

typedef struct s_table
{
    int             philos_num;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             eat_x_times;
    int             already_ate_max;
	long int		start_time;
    t_philo         *philos;
    pthread_t       *threads;
    pthread_mutex_t	*forks;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	write_message;

}   t_table;

int         init_all(t_table *table);
void        init_philo(t_table *table, t_philo *philo);
int         init_threads(t_table *table);
int			init_mutex(t_table *table);

void        *philo_routine(void *arg);

void        set_arguments(table, argc, argv);

void        put_char(char c, int fd);
void        put_string(char *s, int fd);
int         is_digit(char *str);
int         is_int(char *str);
int         atoi_philo(char *str);


long int    get_time_now(void);
void        new_sleap(int mil_sec);
int         wait_threads(t_table *table);
int         meal_control(t_table *table, t_philo *philo);
void        control(t_table *table, t_philo *philo);



#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:27:25 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 11:57:15 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	one_philo(t_philo *philo)
{
	take_left_fork(philo);
	ft_usleep(philo->data->die_time);
	update_philo_state(philo, DEAD);
	drop_left_fork(philo);
	return (1);
}

bool	nb_meals_option(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_meals_count);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->ph_threads);
	free(data->philos);
	free(data->forks);
}

void	print_msg(t_data *data, int id, char *msg)
{
	unsigned long long int	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (keep_iter(data))
		printf("%llu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

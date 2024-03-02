/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:25:36 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 21:28:45 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	return (get_nb_meals_had(philo) >= data->nb_meals);
}

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if ((get_time() - get_last_eat_time(philo)) > data->die_time
		/* && get_philo_state(philo) != EATING */)
	{
		// set_keep_iterating(data, false);
		// update_philo_state(philo, DEAD);
		print_msg(data, philo->id, DIED);
		result = true;
	}
	return (result);
}

// void	notify_all_philos(t_data *data)
// {
// 	t_philo	*philos;
// 	int		i;
// 	int		nb_philos;

// 	nb_philos = get_nb_philos(data);
// 	philos = data->philos;
// 	i = -1;
// 	while (++i < nb_philos)
// 		update_philo_state(&philos[i], DEAD);
// }

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	i = -1;
	nb_philos = get_nb_philos(data);
	while (++i < nb_philos && keep_iter(data))
	{
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
		usleep(100);
	}
	if (keep_iter(data) == true)
	{
		set_keep_iterating(data, false);
		// notify_all_philos(data);
	}
	return (NULL);
}

void	*life_check(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos && keep_iter(data))
	{
		if (philo_died(&philos[i]) /* && keep_iter(data) */)
		{
			// print_msg(data, philos[i].id, DIED);
			set_keep_iterating(data, false);
			// notify_all_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(100);
	}
	return (NULL);
}

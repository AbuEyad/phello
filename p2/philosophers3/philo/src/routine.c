/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:26:42 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 12:17:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time -10);
	while (keep_iter(philo->data))
	{
		if (ft_eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_think(philo) != 0)
			break ;
		usleep(500);
	}
	return (NULL);
}

void	nb_of_meals(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->mut_print);
	printf("Philo %d ate %d times\n", philo->id, philo->meals_count);
	pthread_mutex_unlock(&data->mut_print);
}

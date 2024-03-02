/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:51:45 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 17:43:32 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(philo->left_f);
}

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_last_eat_time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->mut_last_eat_time);
}

void	update_meals_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_meals_count);
	philo->meals_count++;
	pthread_mutex_unlock(&philo->mut_meals_count);
}

void	time_for_eating(t_philo *philo)
{
	ft_usleep(get_eat_time(philo->data));
}

int	ft_eat(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (1);
	update_last_meal_time(philo);
	update_philo_state(philo, EATING);
	print_msg(philo->data, philo->id, EAT);
	time_for_eating(philo);
	update_meals_count(philo);
	drop_forks(philo);
	return (0);
}

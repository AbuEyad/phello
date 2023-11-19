/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:30:30 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/19 14:30:33 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

long	chrono(t_philo *ph)
{
	return (get_time() - ph->table->start_time);
}

void	print_usage(void)
{
	printf(LIGHT_RED "Usage: ./philo_bonus \
	[number_of_philosophers]\
	[time_to_die]\
	[time_to_eat]\
	[time_to_sleep]\
	[number_of_time_each_philosophers_must_eat]\n" RESET);
	exit(EXIT_FAILURE);
}

void	ft_usleep(int ms)
{
	usleep(ms * 1000);
}

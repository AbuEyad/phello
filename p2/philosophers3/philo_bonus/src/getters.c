/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:07:27 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/10 14:32:49 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

uint64_t	get_last_eat_time(t_data *data)
{
	uint64_t	time;

	sem_wait(data->philo.sem_philo);
	time = data->philo.last_eat_time;
	sem_post(data->philo.sem_philo);
	return (time);
}

t_state	get_philo_state(t_data *data)
{
	t_state	state;

	sem_wait(data->philo.sem_philo);
	state = data->philo.state;
	sem_post(data->philo.sem_philo);
	return (state);
}

uint64_t	get_start_time(t_data *data)
{
	return (data->start_time);
}

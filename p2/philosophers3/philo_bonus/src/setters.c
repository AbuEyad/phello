/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:13:13 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 10:45:30 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	update_philo_state(t_data *data, t_state state)
{
	sem_wait(data->philo.sem_philo);
	data->philo.state = state;
	sem_post(data->philo.sem_philo);
}

void	update_last_meal_time(t_data *data)
{
	sem_wait(data->philo.sem_philo);
	data->philo.last_eat_time = get_time();
	sem_post(data->philo.sem_philo);
}

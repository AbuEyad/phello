/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:29:54 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/19 14:29:57 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	take_forks(t_philo *ph)
{
	sem_wait(ph->table->forks);
	print_forks(ph);
	sem_wait(ph->table->forks);
	print_forks(ph);
}

void	go_to_sleep(t_philo *ph)
{
	ph->eat_count++;
	print_sleeping(ph);
	ft_usleep(ph->table->time_to_sleep);
}

void	leave_forks(t_philo *ph)
{
	sem_post(ph->table->forks);
	sem_post(ph->table->forks);
	go_to_sleep(ph);
}

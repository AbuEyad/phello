/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:30:08 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/19 14:30:11 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"
#include <sys/wait.h>

void	kill_everyone(t_table *table, int sender)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (sender != i)
			kill(table->pid[i], SIGKILL);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:54:02 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/19 13:54:05 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	destroy the mutexes used in the t_table structure. iterate over the number
		of philosophers and call pthread_mutex_destroy to destroy each fork
	mutex and private lock mutex. After that, destroy the main_lock and
							write_message mutexes.
*/
void	destroy(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table -> philos_num)
	{
		pthread_mutex_destroy(&table -> forks[i]);
		pthread_mutex_destroy(&table -> priv_lock[i]);
	}
	pthread_mutex_destroy(&table -> main_lock);
	pthread_mutex_destroy(&table -> write_message);
}

/*
		free allocated memory
*/
void	free_all(t_table *table)
{
	if (table -> threads)
		free(table -> threads);
	if (table -> forks)
		free(table -> forks);
	if (table -> philos)
		free(table -> philos);
	if (table -> priv_lock)
		free(table -> priv_lock);
	if (table)
		free(table);
}

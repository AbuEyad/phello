/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:25:51 by habu-zua          #+#    #+#             */
/*   Updated: 2024/02/25 19:10:24 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_nb_philos(data);
	i = -1;
	data->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->ph_threads[i], NULL,
				&routine, &data->philos[i]) != 0)
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&all_alive_routine, data) != 0)
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data) != 0)
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL) != 0)
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL) != 0)
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->ph_threads[i], NULL) != 0)
			return (1);
	}
	return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	data;

	init_data(&data, argc, argv);
	if (malloc_data(&data) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	create_threads(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

void	leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		print_instruction();
		return (WRONG_INPUT);
	}
	if (philosophers(argc, argv) != 0)
		return (MALLOC_ERROR);
	return (0);
}

// fix printing
// fix philo_died()
// fix routing order MAYBE
// WHAT SHOULD IT DO WHEN NB_MEALS IS <= 0?
// is it possible to print in smaller periods?
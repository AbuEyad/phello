/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:53:48 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/26 15:37:17 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_check_args(t_table *table, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (error_message(ARGS_NUM, 1));
	i = 1;
	while (i < argc)
	{
		if (!digit_check(argv[i]))
			return (error_message(ONLY_DIGIT, 0));
		if (is_int(argv[i]) <= 0)
			return (error_message(SIZE_MATTERS, 0));
		i++;
	}
	set_arguments(table, argc, argv);
	if (error_message_args(table) == EXIT_FAILURE)
		return (free(table), EXIT_FAILURE);
	return (0);
}

/*
	convert the command-line arguments to integers and set the respective fields
		in the t_table structure, including an optional eat_x_times field.
*/
void	set_arguments(t_table *table, int argc, char **argv)
{
	table -> philos_num = atoi_philo(argv[1]);
	table -> time_to_die = atoi_philo(argv[2]);
	table -> time_to_eat = atoi_philo(argv[3]);
	table -> time_to_sleep = atoi_philo(argv[4]);
	if (argc == 6)
	{
		table -> eat_x_times = atoi_philo(argv[5]);
		if (argv[5] && table -> eat_x_times < 0)
			printf("\033[1;91mThe number of meals cannot be negative\033[0m\n");
	}
	else
		table -> eat_x_times = 0;
}

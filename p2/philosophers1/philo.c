/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:54:29 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/26 18:51:05 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (set_check_args(table, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_all(table) == -1)
		return (EXIT_FAILURE);
	control(table, table -> philos);
	join_threads(table);
	destroy(table);
	free_all(table);
}

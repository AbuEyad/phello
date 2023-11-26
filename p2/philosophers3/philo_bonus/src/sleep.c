/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:36:24 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/10 14:32:49 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	sleep_for_eating(t_data *data)
{
	ft_usleep(data->eat_time);
}

int	ft_sleep(t_data *data)
{
	set_philo_state(data, SLEEPING);
	if (print_msg(data, SLEEP))
		return (1);
	ft_usleep(data->sleep_time);
	return (0);
}

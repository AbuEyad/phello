/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:27:07 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 11:34:22 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_think(t_philo *philo)
{
	update_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}

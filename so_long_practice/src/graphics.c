/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:13:13 by habu-zua          #+#    #+#             */
/*   Updated: 2023/11/18 20:10:05 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	images_assignment(t_vars *var)
{
	int	i;
	int	j;
	
	var->player = mlx_xpm_file_to_image(var->mlx,"images/player.xpm", &i, &j);
	
	if (!var->player)
	{
		printf("Error\ncan't open/read images.\n");
		exit_point(var);
	}
}

void	place_player(t_vars *var, int i, int j)
{
	mlx_put_image_to_window(var->mlx,var->win, var->player, j * 32, i * 32);
	var->y_axis = i;
	var->x_axis = j;
}


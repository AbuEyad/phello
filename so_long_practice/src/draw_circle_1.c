#include "../include/so_long.h"

void draw_circle_1(t_vars *vars, t_circle *circle)
{
	int x = circle->x;
	int y = circle->y;
	int radius = circle->radius;

	int x_pos = radius;
	int y_pos = 0;
	int err = 0;

	int color = get_color();
	while (x_pos >= y_pos)
	{
		mlx_pixel_put(vars->mlx, vars->win, x + x_pos, y - y_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x + y_pos, y - x_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x - y_pos, y - x_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x - x_pos, y - y_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x - x_pos, y + y_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x - y_pos, y + x_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x + y_pos, y + x_pos, color);
		mlx_pixel_put(vars->mlx, vars->win, x + x_pos, y + y_pos, color);

		if (err <= 0)
		{
			y_pos += 1;
			err += 2 * y_pos + 1;
		}

		if (err > 0)
		{
			x_pos -= 1;
			err -= 2 * x_pos + 1;
		}
	}
}

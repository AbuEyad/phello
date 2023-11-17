#include "main.h"

void draw_circle_2(t_vars *vars, t_circle *circle)
{
	int x = circle->x;
	int y = circle->y;
	int radius = circle->radius;

	for (int i = 0; i < 360; i++)
	{
		int x_pos = x + radius * cos(i * M_PI / 180);
		int y_pos = y + radius * sin(i * M_PI / 180);

		mlx_pixel_put(vars->mlx, vars->win, x_pos, y_pos, 0xFFFFFF); // 0xFFFFFF is white color in hex
	}
}

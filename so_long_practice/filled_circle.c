#include "main.h"

void draw_filled_circle(t_vars *vars, t_circle *circle)
{
    int x = circle->x;
    int y = circle->y;
    int radius = circle->radius;

    int x_pos = 0;
    int y_pos = radius;
    int p = 3 - 2 * radius;

    while (x_pos <= y_pos)
    {
        for (int i = x - x_pos; i <= x + x_pos; i++)
        {
            mlx_pixel_put(vars->mlx, vars->win, i, y - y_pos, 0xFFFFFF);
            mlx_pixel_put(vars->mlx, vars->win, i, y + y_pos, 0xFFFFFF);
        }

        for (int i = x - y_pos; i <= x + y_pos; i++)
        {
            mlx_pixel_put(vars->mlx, vars->win, i, y - x_pos, 0xFFFFFF);
            mlx_pixel_put(vars->mlx, vars->win, i, y + x_pos, 0xFFFFFF);
        }

        x_pos++;

        if (p < 0)
            p += 4 * x_pos + 6;
        else
        {
            y_pos--;
            p += 4 * (x_pos - y_pos) + 10;
        }
    }
}
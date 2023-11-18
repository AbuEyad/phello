#include "../include/so_long.h"

void draw_square(t_vars *vars, t_circle *dd)
{
    int x = dd->x;
    int y = dd->y;
    int size = dd->radius;
    int i;
    int j;
    int clr;

    clr = get_color();

    // Loop through each pixel in the square and set its color
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            mlx_pixel_put(vars->mlx, vars->win, x + i, y + j, clr);
        }
    }
}
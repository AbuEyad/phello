#include "../include/so_long.h"

void draw_line(t_vars *vars, t_point p1, t_point p2)
{
    int clr = get_color();
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));

    float xIncrement = (float)dx / (float)steps;
    float yIncrement = (float)dy / (float)steps;

    float x = p1.x;
    float y = p1.y;

    for (int i = 0; i <= steps; ++i)
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, clr);
        x += xIncrement;
        y += yIncrement;
    }
}

void draw_triangle(t_vars *vars, t_point p1, t_point p2, t_point p3)
{
    draw_line(vars, p1, p2);
    draw_line(vars, p2, p3);
    draw_line(vars, p3, p1);
}
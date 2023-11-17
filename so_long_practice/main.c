#include "main.h"


int main(void)
{
	t_vars vars;
	t_circle circle1;
	t_circle circle2;
	t_circle circle3;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Circle Example");

	// Set circle parameters
	circle1.x = WIDTH / 2 - 100;
	circle1.y = HEIGHT / 2;
	circle1.radius = 50;

    circle2.x = WIDTH / 2 - 100;
	circle2.y = HEIGHT / 2;
	circle2.radius = 100;

    circle3.x = WIDTH / 2 + 100;
	circle3.y = HEIGHT / 2;
	circle3.radius = 100;

	// Draw the circle
	draw_circle_1(&vars, &circle1);
	draw_circle_2(&vars, &circle2);
    draw_filled_circle(&vars, &circle3);




	mlx_loop(vars.mlx);
	return (0);
}


//cc main.c ./minilibx/libmlx.a -framework OpenGL -framework AppKit 
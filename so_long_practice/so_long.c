#include "../include/so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

int	exit_point(t_vars *vars)
{
	
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit (0);
}

int controls_working_2(int command, t_vars *vars)
{
    // int	move;

	// move = 0;
	// int i = 0;
	// int j = 0;

	// if (command == 125)
	// 	i++;
	// else if(command == 126)
	// 	i--;
	// else if (command == 123)
	// 	j++;
	// else if(command == 124)
	// 	j--;
	// place_player(vars, i*32, j*32);
	if (command == 53)
		exit_point(vars);
    return (0);
}

int main(int argc, char **argv)
{
	t_vars vars;
	(void) argc;
    (void) argv;

	ft_memset(&vars, 0, sizeof(t_vars));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Random Shape");
	// images_assignment(&vars);
	// place_player(&vars, 0, 0);
	mlx_loop_hook(vars.mlx, update_window2, &vars);
	mlx_hook(vars.win, 2, 1L << 0, controls_working_2, &vars);
	mlx_hook(vars.win, 17, 0, exit_point, &vars);
	mlx_loop(vars.mlx);
	return (0);
}


//cc main.c ./minilibx/libmlx.a -framework OpenGL -framework AppKit 

	// t_circle circle1 = {WIDTH / 2 - 100, HEIGHT/2, 50};
	// t_circle circle2 = {WIDTH / 2 - 100, HEIGHT/2, 100};
	// t_circle circle3;
	// circle3.radius = 10;

    // circle3.x = 0;
	// circle3.y = 0;
	// while ((circle3.x + 5) < (WIDTH - 5))
	// {
	// 	circle3.y = 0;
	// 	while((circle3.y - 5) < ( HEIGHT - 5))
	// 	{
    // 		draw_filled_circle(&vars, &circle3);
			
	// 		circle3.y += 30;
	// 	}
	// 	circle3.x += 30;
	// }
	
	// draw_circle_1(&vars, &circle1);
	// draw_circle_2(&vars, &circle2);



// delay counter
// static int counter = 0;
// if (counter < 20)
// {
// 	counter++;
// 	return (0);
// }
// counter = 0;
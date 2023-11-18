#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 800

typedef struct s_point 
{
	int	x;
	int	y;
}	t_point;


typedef struct s_vars 
{
	int 	y_axis;
	int 	x_axis;
	int		player_x;
	int		player_y;
	int		counter;
	void	*player;
	void	*mlx;
	void 	*win;
}				t_vars;

typedef struct s_circle {
	int x;
	int y;
	int radius;
}				t_circle;


void 	draw_circle_1(t_vars *vars, t_circle *circle);
void 	draw_circle_2(t_vars *vars, t_circle *circle);
void 	draw_filled_circle(t_vars *vars, t_circle *circle);
int 	random_color();
int 	get_color();
void 	draw_square(t_vars *vars, t_circle *shape);
int 	rand_num(int max);
int		exit_point(t_vars *vars);
void	*ft_memset(void *b, int c, size_t len);
int 	update_window(t_vars *vars);
int 	update_window2(t_vars *vars);
void	images_assignment(t_vars *var);
void	place_player(t_vars *var, int i, int j);
void 	draw_line(t_vars *vars, t_point p1, t_point p2);
void 	draw_triangle(t_vars *vars, t_point p1, t_point p2, t_point p3);









#endif

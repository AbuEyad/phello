#ifndef MAIN_H
#define MAIN_H

#include "minilibx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>



#define WIDTH 800
#define HEIGHT 600

typedef struct s_vars {
	void *mlx;
	void *win;
}				t_vars;

typedef struct s_circle {
	int x;
	int y;
	int radius;
}				t_circle;

void draw_circle_1(t_vars *vars, t_circle *circle);
void draw_circle_2(t_vars *vars, t_circle *circle);
void draw_filled_circle(t_vars *vars, t_circle *circle);




#endif

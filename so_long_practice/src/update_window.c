#include "../include/so_long.h"

t_circle circle = {20, 20, 10};

int update_window(t_vars *vars)
{
	static int counter = 0;
	
	if(circle.y >= (HEIGHT - 40) && (circle.x >= WIDTH - 20))
		return(0);
	
	if (circle.x  >= (WIDTH -20))
	{
		circle.x = 20;
		circle.y += 20;
	}
	usleep(5000);
	counter++;
	if(counter % 3 == 0)
		draw_filled_circle(vars, &circle);
	else if(counter % 5 == 0)
		draw_circle_1(vars, &circle);
	else
		draw_square(vars, &circle);

	circle.x += 23;

	return (0);
}

int update_window2(t_vars *vars)
{
	static int counter = 0;
	t_circle cc = {rand_num(WIDTH), rand_num(HEIGHT), rand_num(30)};
	
	t_point p1 = {rand_num(WIDTH), rand_num(HEIGHT)};
	t_point p2 = {rand_num(WIDTH), rand_num(HEIGHT)};
	t_point p3 = {rand_num(WIDTH), rand_num(HEIGHT)};

	usleep(50000);
	counter++;
	if(counter % 5 == 0 && counter % 3 == 0)
		draw_triangle(vars, p1, p2, p3);
	else if(counter % 3 == 0)
		draw_filled_circle(vars, &cc);
	else if(counter % 5 == 0)
		draw_circle_1(vars, &cc);
	else
		draw_square(vars, &cc);
	return (0);
}

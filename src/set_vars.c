#include "../inc/fractol.h"

void	ft_set_mandelbrot(t_all *all)
{
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
//	all->x_mid = (fabs(all->x1) + all->x2) / 2;
//	all->y_mid = (fabs(all->y1) + all->y2) / 2;
	all->freq = 0.66;
	all->zoom = 100;
	all->i_max = 25;
}

void	ft_set_julia_one(t_all *all)
{
	all->x1 = -1;
	all->x2 = 1;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->c_r = 0.285;
	all->c_i = 0.01;
	all->freq = 0.33;
	all->zoom = 100;
	all->i_max = 50;
}

void	ft_set_julia_two(t_all *all)
{
	all->x1 = -1;
	all->x2 = 1;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->c_r = 0.3;
	all->c_i = 0.5;
	all->freq = 0.33;
	all->zoom = 100;
	all->i_max = 50;
}

void	ft_set_julia_three(t_all *all)
{
	all->x1 = -1;
	all->x2 = 1;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->c_r = -0.8;
	all->c_i = 0.156;
	all->freq = 0.33;
	all->zoom = 100;
	all->i_max = 50;
}

void	ft_set_dragon(t_all *all)
{
	all->x_dragon = 300;
	all->y_dragon = 400;
	all->freq = 0.33;
	all->zoom = 10;
	all->i_max = 10;
	all->n_color = 0;
}

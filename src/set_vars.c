#include "../inc/fractol.h"

void	ft_set_mandelbrot(t_all *all)
{
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	all->zoom = 100;
	all->i_max = 50;
}

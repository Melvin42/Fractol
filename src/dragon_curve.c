#include "../inc/fractol.h"

/*
** set turtle posistion
*/

static void	ft_turtle(t_all *all, int x, int y)
{
	all->x1 = x;
	all->y1 = y;
}

/*
** Orient turtle in direction in degres
*/

static void ft_cap(t_all *all, double angle_zero)
{
	all->angle = angle_zero;
}

/*
** Go forward in drawing
*/

static void	ft_forward(t_all *all, int d)
{
	//all->x2 = all->x1 + all->i_max * cos(all->angle);
	//all->y2 = all->x1 + all->i_max * sin(all->angle);
	all->x2 = all->x1 + (double)d * cos(all->angle);
	all->y2 = all->y1 + (double)d * sin(all->angle);
	//printf("x1 = %f x2 = %f\ny1 = %f y2 = %f\n\n", all->x1, all->x2, all->y1, all->y2);
	all->put_x = round(all->x1); 
	all->put_y = round(all->y1);
	if (all->put_x < (int)all->x2 && (int)all->x2 < all->rx)
	{
		while (all->put_x <= (int)all->x2 && all->put_x < all->rx)
			img_pix_put(&all->img, all->put_x++, all->put_y, BLUE_PIX);
	}
	else if (all->put_x > (int)all->x2 && (int)all->x2 > 0)
	{
		while (all->put_x >= (int)all->x2 && all->put_x > 0)
			img_pix_put(&all->img, all->put_x--, all->put_y, BLUE_PIX);
	}
	else if (all->put_y > (int)all->y2 && (int)all->y2 > 0)
	{
		while (all->put_y >= (int)all->y2 && all->put_y > 0)
			img_pix_put(&all->img, all->put_x, all->put_y--, BLUE_PIX);
	}
	else if (all->put_y < (int)all->y2 && (int)all->y2 < all->ry)
	{
		while (all->put_y <= (int)all->y2 && all->put_y < all->ry)
			img_pix_put(&all->img, all->put_x, all->put_y++, BLUE_PIX);
	}
	all->x1 = all->x2;
	all->y1 = all->y2;
}

static void	ft_change_angle(t_all *all, int a)
{
	all->angle -= (a * M_PI) / 180;
}

static void	ft_recursive_dragon(t_all *all, int n, int vz)
{
	if (n == 0)
		ft_forward(all, all->zoom);
	else
	{
		ft_recursive_dragon(all, n - 1, 1);
		ft_change_angle(all, vz * 90);
		ft_recursive_dragon(all, n - 1, -1);
	}
}

void	ft_dragon_curve(t_all *all)
{
	ft_turtle(all, all->x_dragon, all->y_dragon);
	ft_cap(all, 0);
	ft_recursive_dragon(all, all->i_max, 1);
}

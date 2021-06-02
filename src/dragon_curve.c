/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_curve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:46:34 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 14:40:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
** set turtle posistion
*/

static void	ft_turtle(t_all *all, int x, int y, int n)
{
	all->x1 = x;
	all->y1 = y;
	all->n_color = n;
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
	all->x2 = round(all->x1 + (double)d * cos(all->angle));
	all->y2 = round(all->y1 + (double)d * sin(all->angle));
	all->put_x = all->x1; 
	all->put_y = all->y1;
	if (all->put_x < (int)all->x2)
	{
		while (all->put_x < (int)all->x2
			&& (all->put_x > 0 && all->put_x < all->rx)
			&& (all->put_y > 0 && all->put_y < all->ry))
			img_pix_put(&all->img, all->put_x++, all->put_y, all->color);
	}
	else if (all->put_x > (int)all->x2)
	{
		while (all->put_x > (int)all->x2
			&& (all->put_x > 0 && all->put_x < all->rx)
			&& (all->put_y > 0 && all->put_y < all->ry))
			img_pix_put(&all->img, all->put_x--, all->put_y, all->color);
	}
	else if (all->put_y > (int)all->y2)
	{
		while (all->put_y > (int)all->y2
			&& (all->put_y > 0 && all->put_y < all->ry)
			&& (all->put_x > 0 && all->put_x < all->rx))
			img_pix_put(&all->img, all->put_x, all->put_y--, all->color);
	}
	else if (all->put_y < (int)all->y2)
	{
		while (all->put_y < (int)all->y2
			&& (all->put_y > 0 && all->put_y < all->ry)
			&& (all->put_x > 0 && all->put_x < all->rx))
			img_pix_put(&all->img, all->put_x, all->put_y++, all->color);
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
	{
		all->n_color++;
		ft_choose_color(all, all->n_color);
		ft_forward(all, all->zoom);
	}
	else
	{
		ft_recursive_dragon(all, n - 1, 1);
		ft_change_angle(all, vz * 90);
		ft_recursive_dragon(all, n - 1, -1);
	}
}

void	ft_dragon_curve(t_all *all)
{
	ft_turtle(all, all->x_dragon, all->y_dragon, 0);
	ft_cap(all, 0);
	ft_recursive_dragon(all, all->i_max, 1);
}

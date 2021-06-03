/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_curve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:46:34 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 12:50:12 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_set_dragon(t_all *all)
{
	all->x_dragon = 200;
	all->y_dragon = 350;
	all->freq = 0.33;
	all->zoom = 8;
	all->i_max = 10;
	all->n_color = 0;
}

int	ft_launch_dragon_curve(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_dragon(all);
	ft_dragon_loop(all);
	return (0);
}

static void	ft_forward(t_all *all, int d)
{
	all->x2 = round(all->x1 + (double)d * cos(all->angle));
	all->y2 = round(all->y1 + (double)d * sin(all->angle));
	if (all->put_x < (int)all->x2)
		while (all->put_x < (int)all->x2
			&& (all->put_x > 0 && all->put_x < all->rx)
			&& (all->put_y > 0 && all->put_y < all->ry))
			img_pix_put(&all->img, all->put_x++, all->put_y, all->color);
	else if (all->put_x > (int)all->x2)
		while (all->put_x > (int)all->x2
			&& (all->put_x > 0 && all->put_x < all->rx)
			&& (all->put_y > 0 && all->put_y < all->ry))
			img_pix_put(&all->img, all->put_x--, all->put_y, all->color);
	else if (all->put_y > (int)all->y2)
		while (all->put_y > (int)all->y2
			&& (all->put_y > 0 && all->put_y < all->ry)
			&& (all->put_x > 0 && all->put_x < all->rx))
			img_pix_put(&all->img, all->put_x, all->put_y--, all->color);
	else if (all->put_y < (int)all->y2)
		while (all->put_y < (int)all->y2
			&& (all->put_y > 0 && all->put_y < all->ry)
			&& (all->put_x > 0 && all->put_x < all->rx))
			img_pix_put(&all->img, all->put_x, all->put_y++, all->color);
	all->x1 = all->x2;
	all->y1 = all->y2;
}

static void	ft_recursive_dragon(t_all *all, int n, int vz)
{
	if (n == 0)
	{
		ft_choose_color(all, all->n_color);
		all->put_x = all->x1;
		all->put_y = all->y2;
		ft_forward(all, all->zoom);
	}
	else
	{
		ft_recursive_dragon(all, n - 1, 1);
		all->angle -= (vz * 90 * M_PI) / 180;
		ft_recursive_dragon(all, n - 1, -1);
		all->n_color++;
	}
}

void	ft_dragon_curve(t_all *all)
{
	all->x1 = all->x_dragon;
	all->y1 = all->y_dragon;
	all->n_color = 0;
	all->angle = 0;
	ft_recursive_dragon(all, all->i_max, 1);
}

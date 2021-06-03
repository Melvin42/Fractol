/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:31:36 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 12:47:19 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_set_julia_one(t_all *all)
{
	all->x1 = -1.38;
	all->y1 = -1.38;
	all->c_r = 0.285;
	all->c_i = 0.01;
	all->freq = 0.33;
	all->zoom = 180;
	all->i_max = 250;
}

void	ft_set_julia_two(t_all *all)
{
	all->x1 = -1.35;
	all->y1 = -1.35;
	all->c_r = 0.3;
	all->c_i = 0.5;
	all->freq = 0.33;
	all->zoom = 190;
	all->i_max = 250;
}

void	ft_set_julia_three(t_all *all)
{
	all->x1 = -1.56;
	all->y1 = -1.56;
	all->c_r = -0.8;
	all->c_i = 0.156;
	all->freq = 0.33;
	all->zoom = 160;
	all->i_max = 250;
}

void	ft_julia(t_all *all, int x, int y, int i)
{
	while (++x < all->rx)
	{
		y = -1;
		while (++y < all->ry)
		{
			all->z_r = (double)x / (double)all->zoom + all->x1;
			all->z_i = (double)y / (double)all->zoom + all->y1;
			i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4
				&& i < all->i_max)
			{
				all->tmp = all->z_r;
				all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
				all->z_i = 2 * all->z_i * all->tmp + all->c_i;
				i++;
			}
			ft_choose_color(all, i);
			if (i != all->i_max)
				img_pix_put(&all->img, x, y, all->color);
		}
	}
}

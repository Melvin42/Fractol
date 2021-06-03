/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:09:08 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 12:40:31 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_set_bship(t_all *all)
{
	all->x1 = -2.06;
	all->y1 = -2.06;
	all->freq = 0.33;
	all->zoom = 150;
	all->i_max = 100;
}

int	ft_launch_bship(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_bship(all);
	ft_bship_loop(all);
	return (0);
}

void	ft_bship(t_all *all, int x, int y, int i)
{
	while (++x < all->rx)
	{
		y = -1;
		while (++y < all->ry)
		{
			all->c_r = (double)x / all->zoom + all->x1;
			all->c_i = (double)y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4
				&& i < all->i_max)
			{
				all->tmp = all->z_r;
				all->z_r = fabs(all->z_r * all->z_r - all->z_i * all->z_i
						+ all->c_r);
				all->z_i = fabs(2 * all->tmp * all->z_i + all->c_i);
				i++;
			}
			ft_choose_color(all, i);
			if (i != all->i_max)
				img_pix_put(&all->img, x, y, all->color);
		}
	}
}

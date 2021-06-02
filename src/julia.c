/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:31:36 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 15:32:31 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

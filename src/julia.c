/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:31:36 by melperri          #+#    #+#             */
/*   Updated: 2021/05/27 12:34:34 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_julia(t_all *all)
{
	int	x;
	int	y;
	int	i;

	all->x1 = -1;
	all->x2 = 2;
	all->y1 = -1.2;
	all->y2 = 1.2;

	all->zoom = all->i_max * 2;
	int	img_x = (int)(all->x2 - all->x1) * all->zoom;
	int	img_y = (int)(all->y2 - all->y1) * all->zoom;
	if (all->img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, img_x, img_y) < 0)
		return (check_error(all, MLX_ERROR));

	x = -1;
	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
			all->c_r = 0.285;
			all->c_i = 0.01;
			all->z_r = (double)x / all->zoom + all->x1;
			all->z_i = (double)y / all->zoom + all->y1;
			i = 0;
			all->tmp = all->z_r;
			all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
			all->z_i = 2 * all->z_i * all->tmp + all->c_i;
			i++;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && i < all->i_max)
			{
				all->tmp = all->z_r;
				all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
				all->z_i = 2 * all->z_i * all->tmp + all->c_i;
				i++;
			}
			if (i == all->i_max)
				img_pix_put(&all->img, x, y, BLUE_PIX);
			else
				img_pix_put(&all->img, x, y, encode_rgb(0, 0, i * 255 / all->i_max));
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, all->put_x, all->put_y);
	return (0);
}

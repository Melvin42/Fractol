/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:46:52 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 23:05:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mandelbrot(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		j;

	j = 0;
	all->x1 = -3.1;
	all->x2 = 4.8;
	all->y1 = -2.2;
	all->y2 = 3.2;
	all->i_max = 50;
	
	int	img_x = (int)((all->x2 - all->x1) * all->zoom);
	int	img_y = (int)((all->y2 - all->y1) * all->zoom);
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
			all->c_r = (double)x / all->zoom + all->x1;
			all->c_i = (double)y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			i = 0;
			all->tmp = all->z_r;
			all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
			all->z_i = 2 * all->tmp * all->z_i + all->c_i;
			i++;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && i < all->i_max)
			{
				all->tmp = all->z_r;
				all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
				all->z_i = 2 * all->tmp * all->z_i + all->c_i;
				i++;
			}
			if (i == all->i_max)
				img_pix_put(&all->img, x, y, BLACK_PIX);
			else
				img_pix_put(&all->img, x, y, encode_rgb(0, 0, i * j++ / all->i_max));
				
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	all->zoom += 1;

	return (0);
}

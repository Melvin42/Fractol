/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:46:52 by melperri          #+#    #+#             */
/*   Updated: 2021/05/30 21:22:37 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mandelbrot(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		color;

	all->img_x = all->rx;
	all->img_y = all->ry;
	if (all->img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->img_x, all->img_y) < 0)
		return (check_error(all, MLX_ERROR));
	ft_background(all);
	x = -1;
	while (++x < all->img_x)
	{
		y = -1;
		while (++y < all->img_y)
		{
			all->c_r = (double)x / all->zoom + all->x1;
			all->c_i = (double)y / all->zoom + all->y1;
			all->z_r = 0;
			all->z_i = 0;
			i = 0;
			while (all->z_r * all->z_r + all->z_i * all->z_i < 4 && i < all->i_max)
			{
				all->tmp = all->z_r;
				all->z_r = all->z_r * all->z_r - all->z_i * all->z_i + all->c_r;
				all->z_i = 2 * all->tmp * all->z_i + all->c_i;
				i++;
			}
			all->r = sin(all->freq * i + 0) * 128 + 127;
			all->g = sin(all->freq * i + 2) * 128 + 127;
			all->b = sin(all->freq * i + 4) * 128 + 127;
			color = encode_rgb(all->r, all->g, all->b);
			if (i == all->i_max)
				img_pix_put(&all->img, x, y, BLACK_PIX);
			else
				img_pix_put(&all->img, x, y, color);
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, all->put_x, all->put_y);
	return (0);
}

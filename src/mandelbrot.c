/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:46:52 by melperri          #+#    #+#             */
/*   Updated: 2021/05/27 12:45:02 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_background(t_all *all)
{
	int x;
	int y;

	y = -1;
	while (++y <= all->img.res_y)
	{
		x = -1;
		while  (++x <= all->img.res_x)
		{
			img_pix_put(&all->img, x, y, BLACK_PIX);
		}
	}
}

int	ft_mandelbrot(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		red;
	int		green;
	int		blue;
	int		color;

	//img_x = (int)((all->x2 - all->x1) * all->zoom);
	//img_y = (int)((all->y2 - all->y1) * all->zoom);
	all->img_x = all->rx;// / (all->x2 - all->x1);
	all->img_y = all->ry;// / (all->y2 - all->y1);
	if (all->img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->img_x, all->img_y) < 0)
		return (check_error(all, MLX_ERROR));
	ft_background(all);
	x = -1;
	color = 0;
	while (++x < all->img_x)
	{
		y = -1;
		color = 0;
		while (++y < all->img_y)
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
			if (i * color / all->i_max < 50)
			{
				red = 255;
				green = 50;
				blue = 100;
			}
			else if (i * color / all->i_max >= 50 && i * color / all->i_max < 100)
			{
				red = 0;
				green = 100;
				blue = 128;
			}
			else if (i * color / all->i_max >= 100 && i * color / all->i_max < 175)
			{
				red = 100;
				green = 100;
				blue = 100;
			}
			else if (i * color / all->i_max >= 175 && i * color / all->i_max < 255)
			{
				red = 200;
				green = 255;
				blue = 58;
			}
			if (i == all->i_max)
				img_pix_put(&all->img, x, y, BLACK_PIX);
			else
			{
				img_pix_put(&all->img, x, y, encode_rgb(i * red / all->i_max, i * green / all->i_max, i * blue / all->i_max));
				color++;
			}
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, all->put_x, all->put_y);
	return (0);
}

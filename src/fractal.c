/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:46:52 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 19:35:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	fractal(t_all *all)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	int		i_max;
	int		x;
	int		y;
	float	tmp;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		i;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 100;
	i_max = 50;
	
	int	img_x = (int)((x2 - x1) * zoom);
	int	img_y = (int)((y2 - y1) * zoom);
	if (ft_new_mlx_img(all, &all->img, img_x, img_y) < 0)
		return (check_error(all, MLX_ERROR));
	x = -1;
	while (++x < img_x)
	{
		y = -1;
		while (++y < img_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * tmp * z_i + c_i;
			i++;
			while (z_r * z_r + z_i * z_i < 4 && i < i_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * tmp * z_i + c_i;
				i++;
			}
			if (i == i_max)
				img_pix_put(&all->img, x, y, BLACK_PIX);
			else
				//img_pix_put(&all->img, x, y, WHITE_PIX);
				img_pix_put(&all->img, x, y, encode_rgb(0, 0, i * 255 / i_max));
				
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);

	return (0);
}

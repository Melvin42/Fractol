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

int	ft_mandelbrot(t_all *all)
{
	int		x;
	int		y;
	int		i;
	int		red;
	int		green;
	int		blue;
	int		h;
	int		mouse_x;
	int		mouse_y;


	(void)h;
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &mouse_x, &mouse_y);
	all->zoom = all->i_max * 2;
	all->x1 = -2.1;
	all->x2 = 0.6;
	all->y1 = -1.2;
	all->y2 = 1.2;
	
	int	img_x = (int)((all->x2 - all->x1) * all->zoom);
	int	img_y = (int)((all->y2 - all->y1) * all->zoom);
	if (all->img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, img_x, img_y) < 0)
		return (check_error(all, MLX_ERROR));
	x = -1;
//	printf("x %d y %d\n", mouse_x, mouse_y);
	while (++x < img_x)
	{
		y = -1;
		red = 0;
		green = 0;
		blue = 0;
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
				img_pix_put(&all->img, x, y, encode_rgb(i * red / all->i_max, i * green++ / all->i_max, i * blue++ / all->i_max));
				
		}
	}
//	int f = 10;
//	all->put_x -= f;
//	all->put_y -= f;
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, all->put_x, all->put_y);

	return (0);
}
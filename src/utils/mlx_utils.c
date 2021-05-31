/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:14:37 by melperri          #+#    #+#             */
/*   Updated: 2021/05/30 21:21:55 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	ft_background(t_all *all)
{
	int x;
	int y;

	y = -1;
	while (++y <= all->img.res_y)
	{
		x = -1;
		while  (++x <= all->img.res_x)
			img_pix_put(&all->img, x, y, BLACK_PIX);
	}
}

int	ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y)
{
	img->mlx_img = mlx_new_image(all->mlx_ptr, res_x, res_y);
	if (img->mlx_img == NULL)
		return (check_error(all, MLX_ERROR));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	if (img->addr == NULL)
		return (check_error(all, MLX_ERROR));
	return (0);
}

int	ft_reload_img(t_all *all)
{
	if (all->img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	return (0);
}

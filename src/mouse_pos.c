/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:46:08 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 19:31:48 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_mouse_coordinate_mandelbrot(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.7) / all->rx - 2.1);
	all->x2 = (double)(((double)all->mouse_x * 2.7) / all->rx + 0.6);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
}

void	ft_mouse_coordinate_julia(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.0) / all->rx - 1.0);
	all->x2 = (double)(((double)all->mouse_x * 2.0) / all->rx + 1.0);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
}

void	ft_mouse_coordinate_dragon(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.0) / all->rx - 1.0);
	all->x2 = (double)(((double)all->mouse_x * 2.0) / all->rx + 1.0);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
}

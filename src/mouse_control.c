/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:20:23 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 21:15:47 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	handle_mouse_mandelbrot(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	ft_mouse_coordinate_mandelbrot(all);
	if (button == Button5)
		all->zoom += 0.24 * all->zoom;
	if (button == Button4)
		all->zoom -= 0.24 * all->zoom;
	if (all->zoom <= 0)
		all->zoom = 1;
	return (0);
}

int	handle_mouse_julia(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	ft_mouse_coordinate_julia(all);
	if (button == Button5)
		all->zoom += 1.5;
	if (button == Button4)
		all->zoom -= 1.5;
	if (all->zoom <= 0)
		all->zoom = 1;
	return (0);
}

int	handle_mouse_dragon(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	ft_mouse_coordinate_dragon(all);
	if (button == Button5)
		all->zoom += 1.5;
	if (button == Button4)
		all->zoom -= 1.5;
	if (all->zoom <= 0)
		all->zoom = 1;
	return (0);
}

int	handle_mouse_bship(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	ft_mouse_coordinate_bship(all);
	if (button == Button5)
		all->zoom += 1.5;
	if (button == Button4)
		all->zoom -= 1.5;
	if (all->zoom <= 0)
		all->zoom = 1;
	return (0);
}

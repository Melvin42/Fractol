/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:20:23 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 11:09:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	handle_mouse_mandelbrot(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == Button5)
		ft_zoom_in(all);
	if (button == Button4 && all->zoom > 50)
		ft_zoom_out(all);
	return (0);
}

int	handle_mouse_julia(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == Button5)
		ft_zoom_in(all);
	if (button == Button4 && all->zoom > 50)
		ft_zoom_out(all);
	return (0);
}

int	handle_mouse_dragon(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == Button5)
		ft_zoom_in(all);
	if (button == Button4 && all->zoom > 50)
		ft_zoom_out(all);
	return (0);
}

int	handle_mouse_bship(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == Button5)
		ft_zoom_in(all);
	if (button == Button4 && all->zoom > 50)
		ft_zoom_out(all);
	return (0);
}

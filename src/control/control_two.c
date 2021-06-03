/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:15:00 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 16:17:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static void	ft_reset(t_all *all)
{
	if (all->fractal == MANDELBROT)
		ft_set_mandelbrot(all);
	else if (all->fractal == JULIA_ONE)
		ft_set_julia_one(all);
	else if (all->fractal == JULIA_TWO)
		ft_set_julia_two(all);
	else if (all->fractal == JULIA_THREE)
		ft_set_julia_three(all);
	else if (all->fractal == BSHIP)
		ft_set_bship(all);
}

void	ft_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_exit(all);
	if (all->key.plus == 1)
		all->i_max += 1;
	if (all->key.minus == 1 && all->i_max > 10)
		all->i_max -= 1;
	if (all->key.up == 1)
		all->y1 -= 40 / all->zoom;
	if (all->key.down == 1)
		all->y1 += 40 / all->zoom;
	if (all->key.left == 1)
		all->x1 -= 40 / all->zoom;
	if (all->key.right == 1)
		all->x1 += 40 / all->zoom;
	if (all->key.zoom_in == 1)
		ft_zoom_in(all);
	if (all->key.zoom_out == 1 && all->zoom > 50)
		ft_zoom_out(all);
	if (all->key.print == 1)
		ft_print_vars(all);
	if (all->key.reset == 1)
		ft_reset(all);
	if (all->key.frequency == 1)
		all->freq += 0.01;
	ft_change_constant(all);
}

void	ft_control_dragon_curve(t_all *all)
{
	if (all->key.escape == 1)
		ft_exit(all);
	if (all->key.plus == 1 && all->i_max < 18)
		all->i_max += 1;
	if (all->key.minus == 1 && all->i_max > 1)
		all->i_max -= 1;
	if (all->key.up == 1)
		all->y_dragon -= ceil(3 * all->zoom / 15);
	if (all->key.down == 1)
		all->y_dragon += ceil(3 * all->zoom / 15);
	if (all->key.left == 1)
		all->x_dragon -= ceil(3 * all->zoom / 15);
	if (all->key.right == 1)
		all->x_dragon += ceil(3 * all->zoom / 15);
	if (all->key.zoom_in == 1)
		all->zoom += 1;
	if (all->key.zoom_out == 1 && all->zoom > 1)
		all->zoom -= 1;
	if (all->key.print == 1)
		ft_print_vars_dragon(all);
	if (all->key.reset == 1)
		ft_set_dragon(all);
}

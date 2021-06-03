/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:33:24 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 15:16:56 by melperri         ###   ########.fr       */
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

static void	ft_change_constant(t_all *all)
{
	if (all->key.c_r_moins == 1)
		all->c_r -= 0.01;
	if (all->key.c_r_plus == 1)
		all->c_r += 0.01;
	if (all->key.c_i_moins == 1)
		all->c_i -= 0.01;
	if (all->key.c_i_plus == 1)
		all->c_i += 0.01;
}

static void	ft_change_constant_press(int keysym, t_all *all)
{
	if (keysym == XK_h)
		all->key.c_r_moins = 1;
	if (keysym == XK_j)
		all->key.c_r_plus = 1;
	if (keysym == XK_k)
		all->key.c_i_moins = 1;
	if (keysym == XK_l)
		all->key.c_i_plus = 1;
}

static void	ft_change_constant_release(int keysym, t_all *all)
{
	if (keysym == XK_h)
		all->key.c_r_moins = 0;
	if (keysym == XK_j)
		all->key.c_r_plus = 0;
	if (keysym == XK_k)
		all->key.c_i_moins = 0;
	if (keysym == XK_l)
		all->key.c_i_plus = 0;
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

int	handle_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		all->key.escape = 1;
	if (keysym == XK_KP_Add)
		all->key.plus = 1;
	if (keysym == XK_KP_Subtract)
		all->key.minus = 1;
	if (keysym == XK_Up)
		all->key.up = 1;
	if (keysym == XK_Down)
		all->key.down = 1;
	if (keysym == XK_Left)
		all->key.left = 1;
	if (keysym == XK_Right)
		all->key.right = 1;
	if (keysym == XK_z)
		all->key.zoom_in = 1;
	if (keysym == XK_x)
		all->key.zoom_out = 1;
	if (keysym == XK_r)
		all->key.reset = 1;
	if (keysym == XK_p)
		all->key.print = 1;
	ft_change_constant_press(keysym, all);
	return (0);
}

int	handle_keyrelease(int keysym, t_all *all)
{
	if (keysym == XK_KP_Add)
		all->key.plus = 0;
	if (keysym == XK_KP_Subtract)
		all->key.minus = 0;
	if (keysym == XK_Up)
		all->key.up = 0;
	if (keysym == XK_Down)
		all->key.down = 0;
	if (keysym == XK_Left)
		all->key.left = 0;
	if (keysym == XK_Right)
		all->key.right = 0;
	if (keysym == XK_z)
		all->key.zoom_in = 0;
	if (keysym == XK_x)
		all->key.zoom_out = 0;
	if (keysym == XK_r)
		all->key.reset = 0;
	if (keysym == XK_p)
		all->key.print = 0;
	if (keysym == XK_c)
		all->freq += 0.01;
	if (keysym == XK_v)
		all->freq -= 0.01;
	ft_change_constant_release(keysym, all);
	return (0);
}

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

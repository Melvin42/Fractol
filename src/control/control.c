/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:33:24 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 16:17:47 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

static void	handle_keypress_part_two(int keysym, t_all *all)
{
	if (keysym == XK_c)
		all->key.frequency = 1;
	ft_change_constant_press(keysym, all);
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
	handle_keypress_part_two(keysym, all);
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
		all->key.frequency = 0;
	ft_change_constant_release(keysym, all);
	return (0);
}

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

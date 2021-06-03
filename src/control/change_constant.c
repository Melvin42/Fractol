/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_constant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:48:20 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 15:49:48 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_change_constant(t_all *all)
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

void	ft_change_constant_press(int keysym, t_all *all)
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

void	ft_change_constant_release(int keysym, t_all *all)
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

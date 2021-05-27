/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:33:24 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 22:41:14 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_exit(all);
}

int	handle_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		all->key.escape = 1;
	return (0);
}

int	handle_mouse(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;
	if (button == Button4)
 		all->i_max += 1;
	if (button == Button5)
		all->i_max -= 1;
	if (all->i_max <= 0)
		all->i_max = 1;
	return (0);
}

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

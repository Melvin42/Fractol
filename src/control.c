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
	double	h;

	h = 1;
	if (button == Button5)
	{
		all->flag_start = 1;
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
		all->x1 = (double)((double)all->mouse_x / 1800.0 - h);
		if (all->x1 < -2.1)
			all->x1 = -2.1;
		all->x2 = (double)((double)all->mouse_x / 1800.0 + h);
		if (all->x2 < 0.6)
				all->x2 = 0.6;
		all->y1 = (double)((double)all->mouse_y / 1000.0 - h);
		if (all->y1 < -1.2)
				all->y1 = -1.2;
		all->y2 = (double)((double)all->mouse_y / 1000.0 + h);
		if (all->y2 > 1.2)
				all->y2 = 1.2;
		all->zoom += 1;
 		all->i_max += 1;
	}
	if (button == Button4)
	{
		all->flag_start = 1;
		mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
		all->x1 = (double)((double)all->mouse_x / 1800.0 - h);
		if (all->x1 < -2.1)
			all->x1 = -2.1;
		all->x2 = (double)((double)all->mouse_x / 1800.0 + h);
		if (all->x2 < 0.6)
				all->x2 = 0.6;
		all->y1 = (double)((double)all->mouse_y / 1000.0 - h);
		if (all->y1 < -1.2)
				all->y1 = -1.2;
		all->y2 = (double)((double)all->mouse_y / 1000.0 + h);
		if (all->y2 > 1.2)
				all->y2 = 1.2;
		all->zoom -= 1;
		all->i_max -= 1;
	}
	if (all->i_max <= 0)
		all->i_max = 1;
	if (all->zoom <= 0)
		all->zoom = 1;
	return (0);
}

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

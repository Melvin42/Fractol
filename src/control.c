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
	if (all->key.plus == 1)
		all->i_max += 1;
	if (all->key.minus == 1)
		all->i_max -= 1;
	if (all->key.up == 1)
		all->y1 += 0.1;
	if (all->key.down == 1)
		all->y1 -= 0.1;
	if (all->key.left == 1)
		all->x1 += 0.1;
	if (all->key.right == 1)
		all->x1 -= 0.1;
	if (all->key.zoom_in == 1)
		all->zoom += 1;
	if (all->key.zoom_out == 1)
		all->zoom -= 1;
	if (all->key.reset == 1)
		ft_set_mandelbrot(all);
	if (all->i_max < 10)
		all->i_max = 10;
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
	return (0);
}

int	handle_mouse(int button, int x, int y, t_all *all)
{
	(void)x;
	(void)y;

	if (button == Button5)
	{
		mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
		all->x1 = (double)(((double)all->mouse_x * 2.7) / all->img_x - 2.1);
	//	if (all->x1 < -2.1)
	//		all->x1 = -2.1;
		all->x2 = (double)(((double)all->mouse_x * 2.7) /  all->img_x + 0.6);
	//	if (all->x2 < 0.6)
	//			all->x2 = 0.6;
		all->y1 = (double)(((double)all->mouse_y * 2.4) / all->img_y - 1.2);
	//	if (all->y1 < -1.2)
	//			all->y1 = -1.2;
		all->y2 = (double)(((double)all->mouse_y * 2.4) / all->img_y + 0.6);
	//	if (all->y2 > 1.2)
	//			all->y2 = 1.2;
		all->zoom += 1.5;
	}

	if (button == Button4)
	{
		mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
		all->x1 = (double)(((double)all->mouse_x * 2.7) /  all->img_x - 2.1);
	//	if (all->x1 < -2.1)
	//		all->x1 = -2.1;
		all->x2 = (double)(((double)all->mouse_x * 2.7) / all->img_x + 0.6);
	//	if (all->x2 < 0.6)
	//			all->x2 = 0.6;
		all->y1 = (double)(((double)all->mouse_y * 2.4) / all->img_y - 1.2);
	//	if (all->y1 < -1.2)
	//			all->y1 = -1.2;
		all->y2 = (double)(((double)all->mouse_y * 2.4) / all->img_y + 0.6);
	//	if (all->y2 > 1.2)
	//			all->y2 = 1.2;
		all->zoom -= 1.5;
	}
	if (all->i_max <= 0)
		all->i_max = 1;
	if (all->zoom <= 0)
		all->zoom = 1;
	printf("zoom = %f, i_max = %d\n", all->zoom, all->i_max);
	return (0);
}

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

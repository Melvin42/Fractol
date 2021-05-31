/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:33:24 by melperri          #+#    #+#             */
/*   Updated: 2021/05/30 22:07:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_print_vars(t_all *all)
{
	printf("           zoom = %f\n", all->zoom);
	printf("          X min = %f\n", all->x1);
	printf("          X max = %f\n", all->x2);
	printf("          Y min = %f\n", all->y1);
	printf("          Y max = %f\n", all->y2);
	printf("         Z real = %f\n", all->z_r);
	printf("    Z imaginary = %f\n", all->z_i);
	printf("         C real = %f\n", all->c_r);
	printf("    C imaginary = %f\n", all->c_i);
	printf("color frequency = %f\n", all->freq);
	printf("  iteration max = %d\n", all->i_max);
}

void	ft_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_exit(all);
	if (all->key.plus == 1)
		all->i_max += 1;
	if (all->key.minus == 1)
		all->i_max -= 1;
	if (all->key.up == 1)
		all->y1 += 0.0008 * all->zoom;
	if (all->key.down == 1)
		all->y1 -= 0.0008 * all->zoom;
	if (all->key.left == 1)
		all->x1 += 0.0008 * all->zoom;
	if (all->key.right == 1)
		all->x1 -= 0.0008 * all->zoom;
	if (all->key.zoom_in == 1)
		all->zoom += 0.24 * all->zoom;
	if (all->key.zoom_out == 1)
		all->zoom -= 0.24 * all->zoom;
	if (all->key.print == 1)
		ft_print_vars(all);
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
	if (keysym == XK_p)
		all->key.print = 1;
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
	return (0);
}

static void	ft_mouse_coordinate_mandelbrot(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.7) / all->rx - 2.1);
	all->x2 = (double)(((double)all->mouse_x * 2.7) /  all->rx + 0.6);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
}

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

static void	ft_mouse_coordinate_julia(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.0) / all->rx - 1.0);
	all->x2 = (double)(((double)all->mouse_x * 2.0) /  all->rx + 1.0);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
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

static void	ft_mouse_coordinate_dragon(t_all *all)
{
	mlx_mouse_get_pos(all->mlx_ptr, all->win_ptr, &all->mouse_x, &all->mouse_y);
	all->x1 = (double)(((double)all->mouse_x * 2.0) / all->rx - 1.0);
	all->x2 = (double)(((double)all->mouse_x * 2.0) /  all->rx + 1.0);
	all->y1 = (double)(((double)all->mouse_y * 2.4) / all->ry - 1.2);
	all->y2 = (double)(((double)all->mouse_y * 2.4) / all->ry + 1.2);
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

int	ft_exit(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
	return (0);
}

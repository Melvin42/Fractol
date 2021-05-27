/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:03:25 by melperri          #+#    #+#             */
/*   Updated: 2021/05/27 12:38:24 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	mandelbrot_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	ft_mandelbrot(all);
	ft_control(all);
	return (0);
}

static int	julia_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	ft_julia(all);
	ft_control(all);
	return (0);
}

static void	ft_mandelbrot_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &mandelbrot_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &mandelbrot_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse, all);
	mlx_loop(all->mlx_ptr);
}

static void	ft_julia_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &julia_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &julia_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse, all);
	mlx_loop(all->mlx_ptr);
}

static int	ft_init_mlx(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->rx, all->ry, "fractol");
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
	{
		ft_help_args();
		return (0);
	}

	ft_memset(&all, 0, sizeof(all));
	all.rx = 1800;
	all.ry = 1000;
	all.i_max = 50;
	all.zoom = 2 * all.i_max;
	ft_init_mlx(&all);
	if (ft_strncmp(av[1], "-Mandelbrot", 11) == 0)
		ft_mandelbrot_loop(&all);
	else if (ft_strncmp(av[1], "-Julia", 6) == 0)
		ft_julia_loop(&all);
	return (0);
}

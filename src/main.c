/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:03:25 by melperri          #+#    #+#             */
/*   Updated: 2021/05/31 20:58:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	mandelbrot_render(t_all *all)
{
//	if (all->win_ptr == NULL)
//		return (check_error(all, MLX_ERROR));
	ft_reload_img(all);
	ft_background(all);
	ft_mandelbrot(all, -1, -1, 0);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_control(all);
	return (0);
}

static int	julia_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	ft_reload_img(all);
	ft_background(all);
	ft_julia(all, -1, -1, 0);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_control(all);
	return (0);
}

static int	dragon_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	ft_reload_img(all);
	ft_background(all);
	ft_dragon_curve(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_control_dragon_curve(all);
	return (0);
}

static void	ft_mandelbrot_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &mandelbrot_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &mandelbrot_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse_mandelbrot, all);
	mlx_loop(all->mlx_ptr);
}

static void	ft_julia_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &julia_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &julia_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse_julia, all);
	mlx_loop(all->mlx_ptr);
}

static void	ft_dragon_loop(t_all *all)
{
//	dragon_render(all);
	mlx_loop_hook(all->mlx_ptr, &dragon_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &dragon_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse_dragon, all);
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

static int	ft_launch(t_all *all)
{
	ft_memset(all, 0, sizeof(*all));
	all->rx = 1600;
	all->ry = 1600;
	if (ft_init_mlx(all) < 0)
		return (-1);
	return (0);
}

static int ft_choose_fractal(t_all *all, char *av)
{
	if (ft_strncmp(av, "-Mandelbrot", 11) == 0)
	{
		if (ft_launch(all) < 0)
			return (-1);
		ft_set_mandelbrot(all);
		ft_mandelbrot_loop(all);
	}
	else if (ft_strncmp(av, "-Julia1", 7) == 0)
	{
		if (ft_launch(all) < 0)
			return (-1);
		ft_set_julia_one(all);
		ft_julia_loop(all);
	}
	else if (ft_strncmp(av, "-Julia2", 7) == 0)
	{
		if (ft_launch(all) < 0)
			return (-1);
		ft_set_julia_two(all);
		ft_julia_loop(all);
	}
	else if (ft_strncmp(av, "-Julia3", 7) == 0)
	{
		if (ft_launch(all) < 0)
			return (-1);
		ft_set_julia_three(all);
		ft_julia_loop(all);
	}
	else if (ft_strncmp(av, "-Dragon_curve", 13) == 0)
	{
		if (ft_launch(all) < 0)
			return (-1);
		ft_set_dragon(all);
		ft_dragon_loop(all);
	}
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
	else 
	{
		if (ft_choose_fractal(&all, av[1]) < 0)
			return (-1);
		else
			ft_help_args();
	}
	return (0);
}

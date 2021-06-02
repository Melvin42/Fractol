/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:03:25 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 21:11:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

int	ft_launch(t_all *all)
{
	ft_memset(all, 0, sizeof(*all));
	all->rx = 500;
	all->ry = 500;
	if (ft_init_mlx(all) < 0)
		return (-1);
	return (0);
}

static int	ft_choose_fractal_part_two(t_all *all, char *av)
{
	if (ft_strncmp(av, "-Dragon_curve", 13) == 0 && ft_strlen(av) == 13)
	{
		if (ft_launch_dragon_curve(all) < 0)
			return (-1);
	}
	if (ft_strncmp(av, "-Burning_ship", 13) == 0 && ft_strlen(av) == 13)
	{
		if (ft_launch_bship(all) < 0)
			return (-1);
	}
	return (0);
}

static int	ft_choose_fractal_part_one(t_all *all, char *av)
{
	if (ft_strncmp(av, "-Mandelbrot", 11) == 0 && ft_strlen(av) == 11)
	{
		if (ft_launch_mandelbrot(all) < 0)
			return (-1);
	}
	else if (ft_strncmp(av, "-Julia1", 7) == 0 && ft_strlen(av) == 7)
	{
		if (ft_launch_julia_one(all) < 0)
			return (-1);
	}
	else if (ft_strncmp(av, "-Julia2", 7) == 0 && ft_strlen(av) == 7)
	{
		if (ft_launch_julia_two(all) < 0)
			return (-1);
	}
	else if (ft_strncmp(av, "-Julia3", 7) == 0 && ft_strlen(av) == 7)
	{
		if (ft_launch_julia_three(all) < 0)
			return (-1);
	}
	if (ft_choose_fractal_part_two(all, av) < 0)
		return (-1);
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
		if (ft_choose_fractal_part_one(&all, av[1]) < 0)
			return (-1);
		else
			ft_help_args();
	}
	return (0);
}

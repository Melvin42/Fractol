/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:51:38 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 21:04:52 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_launch_mandelbrot(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_mandelbrot(all);
	ft_mandelbrot_loop(all);
	return (0);
}

int	ft_launch_julia_one(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_julia_one(all);
	ft_julia_loop(all);
	return (0);
}

int	ft_launch_julia_two(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_julia_two(all);
	ft_julia_loop(all);
	return (0);
}

int	ft_launch_julia_three(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_julia_three(all);
	ft_julia_loop(all);
	return (0);
}

int	ft_launch_dragon_curve(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_dragon(all);
	ft_dragon_loop(all);
	return (0);
}

int	ft_launch_bship(t_all *all)
{
	if (ft_launch(all) < 0)
		return (-1);
	ft_set_bship(all);
	ft_bship_loop(all);
	return (0);
}

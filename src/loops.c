/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:38:04 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 21:07:17 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_mandelbrot_loop(t_all *all)
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

void	ft_julia_loop(t_all *all)
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

void	ft_dragon_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &dragon_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &dragon_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse_dragon, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_bship_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &bship_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &bship_render, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_mouse_hook(all->win_ptr, &handle_mouse_bship, all);
	mlx_loop(all->mlx_ptr);
}

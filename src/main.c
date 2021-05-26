/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:03:25 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 17:35:22 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	return (0);
}
static void	ft_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
		&ft_exit_cross, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render, all);
	//mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	//mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
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
	(void)ac;
	(void)av;
	t_all	all;
	memset(&all, 0, sizeof(all));
	all.rx = 800;
	all.ry = 600;
	ft_init_mlx(&all);
	ft_loop(&all);
	return (0);
}

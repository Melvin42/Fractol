/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:31:08 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 21:43:45 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_free_all(t_all *all)
{
	if (all->mlx_ptr)
	{
		if (all->win_ptr)
		{
			if (all->img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
			mlx_destroy_display(all->mlx_ptr);
		}
		free(all->mlx_ptr);
	}
}

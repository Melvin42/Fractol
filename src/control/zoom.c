/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:20:16 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 10:21:02 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_zoom_in(t_all *all)
{
	all->zoom += 0.5 * all->zoom;
	all->x1 += 50 / all->zoom;
	all->y1 += 50 / all->zoom;
}

void	ft_zoom_out(t_all *all)
{
	all->zoom -= 0.5 * all->zoom;
	all->x1 -= 50 / all->zoom;
	all->y1 -= 50 / all->zoom;
}

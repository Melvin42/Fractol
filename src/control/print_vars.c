/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:25:06 by melperri          #+#    #+#             */
/*   Updated: 2021/06/03 13:01:44 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_print_vars(t_all *all)
{
	printf("        X min    = %f\n", all->x1);
	printf("        Y min    = %f\n", all->y1);
	printf("        Z real   = %f\n", all->z_r);
	printf("        Z img    = %f\n", all->z_i);
	printf("        C real   = %f\n", all->c_r);
	printf("        C img    = %f\n", all->c_i);
	printf("        Zoom     = %f\n", all->zoom);
	printf("        I max    = %d\n", all->i_max);
	printf("        RGB freq = %f\n", all->freq);
}

void	ft_print_vars_dragon(t_all *all)
{
	printf("        X dragon = %d\n", all->x_dragon);
	printf("        Y dragon = %d\n", all->y_dragon);
	printf("        X min    = %f\n", all->x1);
	printf("        Y min    = %f\n", all->y1);
	printf("        Zoom     = %f\n", all->zoom);
	printf("        I max    = %d\n", all->i_max);
	printf("        RGB freq = %f\n", all->freq);
}

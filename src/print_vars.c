/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:25:06 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 15:29:15 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_print_vars(t_all *all)
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

void	ft_print_vars_dragon(t_all *all)
{
	printf("           zoom = %f\n", all->zoom);
	printf("              X = %d\n", all->x_dragon);
	printf("              Y = %d\n", all->y_dragon);
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

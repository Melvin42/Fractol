/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:01:00 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 21:19:38 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

void	ft_help_args(void)
{
	printf("How to use : Fractol program need a single argument\n\n");
	printf("  -Julia%25s\n", "Julia's fractal");
	printf("  -Mandelbrot%25s\n", "Mandelbrot's fractal");
}

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
	printf("How to use :\n\n\tFractol program need a single argument\n\n");
	printf("\t  -Mandelbrot%25s\n\n", "Mandelbrot's fractal");
	printf("\tYou can choose three different Julia's fractal set\n\n");
	printf("\t  -Julia1%18s\n", "first set");
	printf("\t  -Julia2%19s\n", "second set");
	printf("\t  -Julia3%18s\n\n", "third set");
	printf("\tBonus :\n\n");
	printf("\t  -Last%18s\n", "Last's fractal");
}

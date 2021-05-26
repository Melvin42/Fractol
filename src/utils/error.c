/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:10:46 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 17:16:42 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fractol.h"

int	check_error(t_all *all, int error)
{
	(void)all;//ft_free_all(all);
	if (error == -1)
		write(1, STR_MLX_ERROR, ft_strlen(STR_MLX_ERROR));
	return (-1);
}


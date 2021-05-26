/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:16:13 by melperri          #+#    #+#             */
/*   Updated: 2021/05/26 19:31:34 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

#define FRACTOL_H

#include "../libft/inc/libft.h"
#include "../minilibx/mlx.h"
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include <X11/X.h>
#include <math.h>

/*
********************************************************************************
**================================> DEFINE <==================================**
********************************************************************************
*/

#define STR_MLX_ERROR "Error\nmlx error.\n"
#define BLACK_PIX 0x0
#define WHITE_PIX 0x0FFFFFF
#define BLUE_PIX 0x0FFFF

/*
********************************************************************************
**================================> ENUM <====================================**
********************************************************************************
*/

enum	e_error
{
	MLX_ERROR = -1,
	SUCCESS,
};

/*
********************************************************************************
**==============================> STRUCT <====================================**
********************************************************************************
*/

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			res_x;
	int			res_y;
}	t_img;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rx;
	int			ry;
	t_img		img;
}	t_all;

/*
********************************************************************************
**===============================> UTILS <====================================**
********************************************************************************
*/

int				fractal(t_all *all);
void			img_pix_put(t_img *img, int x, int y, int color);
int				ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y);
int				encode_rgb(int red, int green, int blue);

int				check_error(t_all *all, int error);

int				ft_exit_cross(t_all *all);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:16:13 by melperri          #+#    #+#             */
/*   Updated: 2021/06/02 16:01:03 by melperri         ###   ########.fr       */
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
#include <stdint.h>

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

typedef struct s_key
{
	int			escape;
	int			up;
	int			down;
	int			left;
	int			right;
	int			plus;
	int			minus;
	int			zoom_in;
	int			zoom_out;
	int			reset;
	int			print;

}	t_key;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rx;
	int			ry;
	int			r;
	int			g;
	int			b;
	int			color;
	int			mouse_x;
	int			mouse_y;
	int			put_x;
	int			put_y;
	int			img_x;
	int			img_y;
	int			flag_start;
	int			i_max;
	int			x_dragon;
	int			y_dragon;
	int			n_color;
	double		angle;
	double		freq;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		x_mid;
	double		y_mid;
	double		zoom;
	double		tmp;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	t_key		key;
	t_img		img;
}	t_all;

/*
********************************************************************************
**================================> DEFINE <==================================**
********************************************************************************
*/

void			ft_help_args(void);

/*
********************************************************************************
**=================================> SRC <====================================**
********************************************************************************
*/

int				ft_launch(t_all *all);

int				ft_launch_mandelbrot(t_all *all);
int				ft_launch_julia_one(t_all *all);
int				ft_launch_julia_two(t_all *all);
int				ft_launch_julia_three(t_all *all);
int				ft_launch_dragon_curve(t_all *all);

void			ft_set_mandelbrot(t_all *all);
void			ft_set_julia_one(t_all *all);
void			ft_set_julia_two(t_all *all);
void			ft_set_julia_three(t_all *all);
void			ft_set_dragon(t_all *all);

void			ft_mandelbrot(t_all *all, int x, int y, int i);
void			ft_julia(t_all *all, int x, int y, int i);
void			ft_dragon_curve(t_all *all);

void			ft_mandelbrot_loop(t_all *all);
void			ft_julia_loop(t_all *all);
void			ft_dragon_loop(t_all *all);

int				mandelbrot_render(t_all *all);
int				julia_render(t_all *all);
int				dragon_render(t_all *all);

/*
********************************************************************************
**===============================> UTILS <====================================**
********************************************************************************
*/

void			img_pix_put(t_img *img, int x, int y, int color);
void			ft_background(t_all *all);
int				ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y);
int				ft_reload_img(t_all *all);

int				encode_rgb(int red, int green, int blue);
void			ft_choose_color(t_all *all, int i);

int				check_error(t_all *all, int error);
void			ft_free_all(t_all *all);

/*
********************************************************************************
**===============================> CONTROL <==================================**
********************************************************************************
*/

void			ft_control(t_all *all);
void			ft_control_dragon_curve(t_all *all);

void			ft_print_vars(t_all *all);
void			ft_print_vars_dragon(t_all *all);

int				handle_keypress(int keysym, t_all *all);
int				handle_keyrelease(int keysym, t_all *all);

int				handle_mouse_mandelbrot(int button, int x, int y, t_all *all);
int				handle_mouse_julia(int button, int x, int y, t_all *all);
int				handle_mouse_dragon(int button, int x, int y, t_all *all);

void			ft_mouse_coordinate_mandelbrot(t_all *all);
void			ft_mouse_coordinate_julia(t_all *all);
void			ft_mouse_coordinate_dragon(t_all *all);

int				ft_exit(t_all *all);

#endif

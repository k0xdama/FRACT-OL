/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:28:00 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 22:47:48 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"

//ERROR
# define MLX_ERROR -1
# define ARGS_ERROR -2
// WINDOWS
# define WIDTH 1000
# define HEIGHT 1000
//FRACTALS
# define JULIA 1
# define MANDELBROT 2
# define MANDELBOX 3
//COLOR SET
# define DEFAULT 0
# define DEFAULT_BIS 1
# define WINTER 2
# define SUNSET 3
# define NATURE 4
# define PURPLE_GRAD 5
// KEYBORD
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ZERO 65438
# define ONE 65436
# define TWO 65433
# define THREE 65435
# define FOUR 65430
# define FIVE 65437
// MOUSE
# define MUP	4
# define MDOWN	5

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;

typedef struct s_data
{
	void		*mlxptr;
	void		*winptr;
	void		*img;
	char		*imgbuf;
	int			img_bpp;
	int			img_len;
	int			img_endian;
	int			choice;
	int			max_it;
	int			color_set;
	int			color;
	double		esc_value;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	t_complex	julia_const;
	double		mb_f;
	double		mb_r;
	double		mb_s;
}	t_data;

// INIT
void		init_data(t_data *data);
int			init_img(t_data *data);
// UTILS AND MATHS
double		handle_decimals(char *str);
double		atodbl(char *str);
double		scale(double unscaled, double new_min,
				double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z, t_complex c);
// ERROR, HELP AND EXIT
void		bad_args(t_data *data);
void		fractol_man(void);
int			prog_exit(t_data *data, int status);
// FRACTALS FUNCTIONS
int			mandelbrot(t_data *data, t_complex c);
int			julia(t_data *data, t_complex z);
int			mandelbox(t_data *data, t_complex c);
// RENDER
int			fractal_render(t_data *data);
// EVENTS
int			handle_keypress(int keysm, t_data *data);
int			handle_mouse(int keysm, int x, int y, t_data *data);
// COLOR
void		color_path(t_data *data, int set, int it);
void		default_set(t_data *data, int it);
void		purple_set(t_data *data, int it);
void		winter_set(t_data *data, int it);
void		sunset_set(t_data *data, int it);
void		nature_set(t_data *data, int it);

#endif
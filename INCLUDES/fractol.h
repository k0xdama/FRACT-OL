/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:28:00 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 05:03:21 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"

#define MLX_ERROR -1
#define ARGS_ERROR -2

# define WIDTH 1000
# define HEIGHT 1000
# define ITER_MAX 200
// # define JULIA 1
# define MANDELBROT 2
// # define MANDELBOX 3

typedef struct s_data
{
	void	*mlxptr;
	void	*winptr;
	void	*img;
	int		*imgbuf;
	int		img_bpp;
	int		img_len;
	int		img_endian;
	int		choice;
	int		max_it;
	// t_complex	julia_default;
	double	esc_value;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	// double	a;
	// double	b;
	
	
}	t_data;

typedef	struct	s_complex
{
	double	real;
	double	i;
}	t_complex;


void	init_data(t_data *data);
int		init_img(t_data *data);
void	check_args(char argv[], int argc, t_data *data);
double	handle_decimals(char *str);
double	atodbl(char *str);
double	scale(double unscaled, double new_min, double new_max, double old_max);
void	square_complex(t_complex z);
void	sum_complex(t_complex z, t_complex c);
void	my_pixel_put(t_data *data, int color, int x, int y);
int		fractal_render(t_data *data);
void	bad_args();
void	fractol_man();





#endif
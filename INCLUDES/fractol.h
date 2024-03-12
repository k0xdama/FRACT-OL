/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:28:00 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/08 18:37:13 by pmateo           ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ITER_MAX 200
# define JULIA 1
# define MANDELBROT 2
# define MANDELBOX 3

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
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	x;
	double	y;
	
}	t_data;





#endif
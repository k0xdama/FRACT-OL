/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:10:27 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 05:10:40 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	my_pixel_put(t_data *data, int color, int x, int y)
{
	int	pixel;

	pixel = (y * data->img_len) + (x * 4);
	if (data->img_endian == 0)
	{
		data->imgbuf[pixel] = (color) & 0xFF;
		data->imgbuf[pixel + 1] = (color >> 8) & 0xFF;
		data->imgbuf[pixel + 2] = (color >> 16) & 0xFF;
		data->imgbuf[pixel + 3] = (color >> 24) & 0xFF;
	}
	else if (data->img_endian == 1)
	{
		data->imgbuf[pixel] = (color >> 24);
		data->imgbuf[pixel + 1] = (color >> 16) & 0xFF;
		data->imgbuf[pixel + 2] = (color >> 8) & 0xFF;
		data->imgbuf[pixel + 3] = (color) & 0xFF;
	}
}

int	mandelbrot(t_data *data)
{
	t_complex	z;
	t_complex	c;
	
	z.real = 0.0;
	z.i = 0.0;
	c.real = scale()
}

int	fractal_render(t_data *data)
{
	
}
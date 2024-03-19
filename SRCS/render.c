/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:10:27 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 04:28:34 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

static void	my_pixel_put(t_data *data, int color, int x, int y)
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

static int	pixel_path(int x, int y, t_data *data)
{
	int	it;
	t_complex c;

	it = 0;
	c.real = scale(x, data->xmin, data->xmax, WIDTH);
	c.i = scale(y, data->ymax, data->ymin, HEIGHT);
	if (data->choice == MANDELBROT)
		it = mandelbrot(data, c);
	if (data->choice == JULIA)
		it = julia(data, c);
	if (data->choice == MANDELBOX)
		it = mandelbox(data, c);
	if (it == data->max_it)
		data->color = 0x000000;
	return (it);
}

int	fractal_render(t_data *data)
{
	int	it;
	int	x;
	int	y;

	it = 0;
	y = 0;
	mlx_clear_window(data->mlxptr, data->winptr);
	while (y < HEIGHT)
	{
		y++;
		x = 0;
		while (x < WIDTH)
		{
			data->color = 0xD8E2DC;
			it = pixel_path(x, y, data);
			my_pixel_put(data, (data->color * it), x, y);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlxptr, data->winptr, data->img, 0, 0);
	return (0);
}
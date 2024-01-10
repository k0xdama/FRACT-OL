/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpixelput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:37:14 by pmateo            #+#    #+#             */
/*   Updated: 2024/01/10 16:10:24 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 360

#define MLX_ERROR 1

#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0x0000FF00
#define	WHITE_PIXEL 0x00FFFFFF

int	main(void)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
	int color;
	char *buffer;
	int	pixel;
	int		x;
	int		y;

	pixel_bits = 0;
	line_bytes = 0;
	endian = 0;
	color = RED_PIXEL;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 360, "BipBop");
	void *image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	x = 0;
	y = 0;
	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx, color);
	while (y < 360 && x < 640)
	{
		++y;
		++x;
		pixel = (y * line_bytes) + (x * 4);
		if (endian == 1)
		{
			buffer[pixel] = (color >> 24);
			buffer[pixel + 1] = (color >> 16) & 0xFF;
			buffer[pixel + 2] = (color >> 8) & 0xFF;
			buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (endian == 0)
		{
			buffer[pixel] = (color) & 0xFF;
			buffer[pixel + 1] = (color >> 8) & 0xFF;
			buffer[pixel + 2] = (color >> 16) & 0xFF;
			buffer[pixel + 3] = (color >> 24);
		}
	}
	mlx_put_image_to_window(mlx, win, image, 0, 0);
	mlx_loop(mlx);
}
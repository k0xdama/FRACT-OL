/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:10:27 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/08 18:10:29 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	render(t_data *data)
{
	// int	pixel;
	int		x;
	int		y;
	int		color;
	int		byteperline;
	
	x = 0;
	y = 0;
	byteperline = data->img_linelen / 4;
	color = RED_PIXEL;
	// if (data->img_bpp != 32)
	// 	color = mlx_get_color_value(data->mlx_ptr, color);
	// while (y < 300)
	// {
	// 	++y;
	// 	while (x < 600)
	// 	{
	// 		++x;
	// 		pixel = (y * data->img_linelen) + (x * 4);
	// 		data->img_buf[pixel] = (color) & 0xFF;
	// 		data->img_buf[pixel + 1] = (color >> 8) & 0xFF;
	// 		data->img_buf[pixel + 2] = (color >> 16) & 0xFF;
	// 		data->img_buf[pixel + 3] = (color >> 24);
	// 	}
	// 	x = 0;
	// }
	while (y < (WINDOW_HEIGHT / 2) - 1)
	{
		++y;
		while (x < WINDOW_WIDTH - 1)
		{
			++x;
			data->img_buf[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	color = WHITE_PIXEL;
	while (y < WINDOW_HEIGHT)
	{
		++y;
		while (x < WINDOW_WIDTH - 1)
		{
			++x;
			data->img_buf[(y * byteperline) + x] = color;
		}
		x = 0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
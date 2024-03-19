/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testminilib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:53:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 18:03:14 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define MLX_ERROR -1

#define GREEN_PIXEL 0x0000FF00
#define BLUE_PIXEL 0xFF000000
#define RED_PIXEL 0x00FF0000
#define	WHITE_PIXEL 0x00FFFFFF

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		*img_buf;
	int		img_bpp;
	int		img_linelen;
	int		img_endian;
}	t_data;


int	handle_keypress(int keysm, t_data *data)
{
	if (keysm == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("%d\n", keysm);
	return (0);
}

// void	img_pix_put(t_data *data, int x, int y, int color)
// {
// 	char pixel;
// }


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

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "ntm");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img_buf = (int *)mlx_get_data_addr(data.img, &data.img_bpp, &data.img_linelen, &data.img_endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
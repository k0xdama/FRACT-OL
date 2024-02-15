/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:26:53 by pmateo            #+#    #+#             */
/*   Updated: 2024/02/15 19:58:30 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"
// #include <stdlib.h>
// #include <stdio.h>

// #include <X11/X.h>
// #include <X11/keysym.h>
// #include "mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0x0000FF00
#define	WHITE_PIXEL 0x00FFFFFF

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int	handle_keypress(int keysm, t_data *data)
{
	if (keysm == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	img_pix_put(t_data *data, int x, int y, int color)
{
	char	pixel;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (data->img.bpp != 32)
		color = mlx_get_color_value(data->mlx_ptr, color);
	while (y < 360 && x < 640)
	{
		++y;
		++x;
		pixel = (y * data->img.line_len) + (x * 4);
		if (data->img.endian == 1)
		{
			data->img.addr[pixel] = (color >> 24);
			data->img.addr[pixel + 1] = (color >> 16) & 0xFF;
			data->img.addr[pixel + 2] = (color >> 8) & 0xFF;
			data->img.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (data->img.endian == 0)
		{
			data->img.addr[pixel] = (color) & 0xFF;
			data->img.addr[pixel + 1] = (color >> 8) & 0xFF;
			data->img.addr[pixel + 2] = (color >> 16) & 0xFF;
			data->img.addr[pixel + 3] = (color >> 24);
		}
	}
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(data, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "test");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}


// Le programme se lance et affiche les choix de formes géométriques disponibles, il attend une entrée de 
// l'utilisateur. Si un mauvais choix est fait un message d'aide s'affiche.
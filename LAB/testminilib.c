/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testminilib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:53:51 by pmateo            #+#    #+#             */
/*   Updated: 2023/11/29 20:52:44 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	main()
{
	void	*mlx;
	void	*win;
	t_data	img;
	int	x = 0;
	int y = 0;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "mlx 42");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
																 &img.endian);
	printf("BITS PER PIXEL = %d\n", img.bits_per_pixel);
	printf("LINE LENGTH = %d\n", img.line_length);
	my_mlx_pixel_put(&img, 960, 540, 0x00FF0000);
	printf("BITS PER PIXEL = %d\n", img.bits_per_pixel);
	printf("LINE LENGTH = %d\n", img.line_length);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
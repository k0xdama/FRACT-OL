/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:26:53 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 04:04:54 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define MLX_ERROR 1

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
	return (0);
}

int	check_args(char argv[], t_data *data)
{
	// if (argv[1] == JULIA)
	// 	data->choice = JULIA;
	if (argv[1] == MANDELBROT)
		data->choice = MANDELBROT;
	// if (argv[1] == MANDELBOX)
	// 	data->choice = MANDELBOX;
}

int main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2 || argc > 4)
	{
		init_data(&data);
		bad_args();
	}
	if (ft_strncmp(argv[2], "help", 4) == 0)
	{
		init_data(&data);
		fractol_man();
		prog_exit();
	}
	init_data(&data);
	check_args(argv, argc, &data);
	
}
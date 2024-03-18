/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:31 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/18 05:24:31 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

// void	prog_exit(int status, t_data *data)
// {
	
// }

static int	is_dbl(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (str[i + 1] < '0' && str[i + 1] > '9'))
			return (0);
		if ((str[i] < '0' && str[i] > '9') && (str[i] != '-') && (str[i] != '.'))
			return (0);
		if (str[i] == '.' && (ft_strchr(str+i+1, '.')))
			return (0);
		i++;
	}
	return (1);
}

static void	check_args(int argc, char *argv[], t_data *data)
{
	int state;
	
	state = 1;
	if (argv[1][0] < '1' && argv[1][0] > '3')
		bad_args();
	data->choice = ft_atoi(argv[1]);
	if (argc == 4 && data->choice == JULIA)
	{
		state = is_dbl(argv[2]);
		state = is_dbl(argv[3]);
		if (!state)
			bad_args();
		data->julia_const.real = atodbl(argv[2]);
		data->julia_const.i = atodbl(argv[3]);
	}
}

int	handle_keypress(int keysm, t_data *data)
{
	if (keysm == XK_Escape)
	{
		mlx_destroy_window(data->mlxptr, data->winptr);
		data->winptr = NULL;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	if (argc < 2 || argc > 4 || argc == 3)
		bad_args();
	if (ft_strncmp(argv[1], "help", 4) == 0)
	{
		fractol_man();
		//prog_exit
		return (1);
	}
	check_args(argc, argv, &data);
	if (init_img(&data) == MLX_ERROR)
	{
		ft_printf("Error occured with the library < minilibx-linux > !\n");
		// prog_exit();
		return (1);
	}
	mlx_loop_hook(data.mlxptr,  &fractal_render, &data);
	mlx_hook(data.winptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlxptr);
	
	mlx_destroy_display(data.mlxptr);
	free(data.mlxptr);
	return (0);
}
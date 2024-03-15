/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:58:31 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 04:59:23 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"



















int	main(int argc, char *agrv[])
{
	t_data	data;

	init_data(&data);
	if (argc < 2 || argc > 4)
		bad_args();
	if (ft_strncmp(agrv[1], "help", 4) == 0)
	{
		fractol_man();
		// prog_exit();
		return (1);
	}
	if (init_img(&data) == MLX_ERROR)
	{
		ft_printf("Error occured with the library < minilibx-linux > !\n");
		// prog_exit();
		return (1);
	}
	
}
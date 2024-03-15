/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:31:38 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 04:51:13 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	init_data(t_data *data)
{
	data->mlxptr = NULL;
	data->winptr = NULL;
	data->img = NULL;
	data->imgbuf = NULL;
	data->img_bpp = 0;
	data->img_len = 0;
	data->img_endian = 0;
	data->choice = 0;
	data->max_it = 200;
	// data->julia_default.real = -1.74856;
	// data->julia_default.i = 0.00075;
	data->esc_value = 4.0;
	data->xmax = 2.0;
	data->xmin = -2.0;
	data->ymax = 2.0;
	data->ymin = -2.0;
// 	data->a = 0;
// 	data->b = 0;
// }

int	init_img(t_data *data)
{
	data->mlxptr = mlx_init();
	if (data->mlxptr == NULL)
		return (MLX_ERROR);
	data->winptr = mlx_new_window(data->mlxptr, WIDTH, HEIGHT, "fractol");
	if (data->winptr == NULL)
		return (MLX_ERROR);
	data->img = mlx_new_image(data->mlxptr, WIDTH, HEIGHT);
	if (data->img == NULL)
		return (MLX_ERROR);
	data->imgbuf = (int *)mlx_get_data_addr(data->img, &data->img_bpp, 
											&data->img_len, &data->img_endian);
	if (data->imgbuf == NULL)
		return (MLX_ERROR);
	return (0);
	
	
}
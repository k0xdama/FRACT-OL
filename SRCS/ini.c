/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:31:38 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/08 18:24:53 by pmateo           ###   ########.fr       */
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
	data->xmax = 1.25;
	data->xmin = -1.25;
	data->ymax = 1.25;
	data->ymin = -1.25;
	data->x = 0;
	data->y = 0;
	
}
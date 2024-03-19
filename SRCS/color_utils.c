/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:50:11 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 22:38:11 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	color_path(t_data *data, int set, int it)
{
	if (it == data->max_it)
		data->color = 0x000000;
	else
	{
		if (set == DEFAULT || set == DEFAULT_BIS)
			default_set(data, it);
		else if (set == PURPLE_GRAD)
			purple_set(data, it);
		else if (set == WINTER)
			winter_set(data, it);
		else if (set == SUNSET)
			sunset_set(data, it);
		else if (set == NATURE)
			nature_set(data, it);
	}
}

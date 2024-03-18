/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:06:00 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/18 02:51:10 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

int	julia(t_data *data, t_complex z)
{
	int	it;
	t_complex c;

	it = 0;
	c.real = data->julia_const.real;
	c.i = data->julia_const.i;
	while (it < data->max_it)
	{
		if (((z.real * z.real) + (z.i *z.i) > data->esc_value))
			break;
		z = sum_complex(square_complex(z), c);
		it ++;
	}
	return (it);
}
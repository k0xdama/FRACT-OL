/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:05:56 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/18 02:48:01 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

int	mandelbrot(t_data *data, t_complex c)
{
	t_complex	z;
	int		it;
	
	z.real = 0.0;
	z.i = 0.0;
	it = 0;
	while (it < data->max_it)
	{
		if (((z.real * z.real) + (z.i * z.i)) > data->esc_value)
			break;
		z = sum_complex(square_complex(z), c);
		it++;
	}
	return (it);
}

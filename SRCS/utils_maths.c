/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:52:11 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 22:37:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;
	double		tmp_real;

	tmp_real = 0.0;
	tmp_real = (z.real * z.real) - (z.i * z.i);
	res.i = 2 * z.real * z.i;
	res.real = tmp_real;
	return (res);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.real = z.real + c.real;
	res.i = z.i + c.i;
	return (res);
}

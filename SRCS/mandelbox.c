/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:15:55 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 04:27:42 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

static double	ballfold(double m, double r)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}

static double boxfold(double v)
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}

int	mandelbox(t_data *data, t_complex c)
{
	int	it;
	double magnitude;
	t_complex	v;
	
	it = 0;
	magnitude = 0;
	v.real = c.real;
	v.i = c.i;
	while (it < data->max_it)
	{
		v.real = data->mb_f * boxfold(v.real);
		v.i = data->mb_f * boxfold(v.i);
		magnitude = sqrt(v.real * v.real + v.i * v.i);
		v.real = v.real * data->mb_s * ballfold(magnitude, data->mb_r) + c.real;
		v.i = v.i * data->mb_s * ballfold(magnitude, data->mb_r) + c.i;
		if (sqrt(magnitude) > 2)
			break;
		it++;
	}
	return (it);
	
}
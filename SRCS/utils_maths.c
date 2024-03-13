/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:52:11 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/13 16:57:58 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

double	scale(double unscaled, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unscaled - 0) / (old_max - 0) + new_min;
}

void	square_complex(t_complex *z)
{
	double tmp_real;
	
	tmp_real = 0.0;
	tmp_real = (z->real * z->real) - (z->i * z->i);
	z->i = 2 * z->real * z->i;
	z->real = tmp_real;
}

void	sum_complex(t_complex z, t_complex c)
{
	
}
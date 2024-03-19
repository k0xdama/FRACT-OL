/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:13:08 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 23:04:08 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	purple_set(t_data *data, int it)
{
	if (it >= 0 && it <= 1)
		data->color = 0x10002B;
	else if (it > 1 && it <= 2)
		data->color = 0x240046;
	else if (it > 2 && it <= 5)
		data->color = 0x3C096C;
	else if (it > 5 && it <= 10)
		data->color = 0x4B1183;
	else if (it > 10 && it <= 20)
		data->color = 0x5A189A;
	else if (it > 20 && it <= 40)
		data->color = 0x7B2CBF;
	else if (it > 40 && it <= 80)
		data->color = 0x9D4EDD;
	else if (it > 80 && it <= 120)
		data->color = 0x240046;
	else if (it > 120 && it <= 130)
		data->color = 0xB266EE;
	else if (it > 130 && it <= 150)
		data->color = 0x10002B;
	else if (it > 150 && it <= 175)
		data->color = 0xC77DFF;
	else if (it > 175 && it < 200)
		data->color = 0xE0AAFF;
}

void	winter_set(t_data *data, int it)
{
	if (it >= 0 && it <= 1)
		data->color = 0x7400B8;
	else if (it > 1 && it <= 2)
		data->color = 0x6930C3;
	else if (it > 2 && it <= 5)
		data->color = 0x5E60CE;
	else if (it > 5 && it <= 10)
		data->color = 0x5390D9;
	else if (it > 10 && it <= 20)
		data->color = 0x4EA8DE;
	else if (it > 20 && it <= 40)
		data->color = 0x48BFE3;
	else if (it > 40 && it <= 80)
		data->color = 0x56CFE1;
	else if (it > 80 && it <= 120)
		data->color = 0x7400B8;
	else if (it > 120 && it <= 130)
		data->color = 0x6930C3;
	else if (it > 130 && it <= 150)
		data->color = 0x72EFDD;
	else if (it > 150 && it <= 175)
		data->color = 0x7400B8;
	else if (it > 175 && it < 200)
		data->color = 0x80FFDB;
}

void	sunset_set(t_data *data, int it)
{
	if (it >= 0 && it <= 1)
		data->color = 0x370617;
	else if (it > 1 && it <= 2)
		data->color = 0x510513;
	else if (it > 2 && it <= 5)
		data->color = 0x6A040F;
	else if (it > 5 && it <= 10)
		data->color = 0x9D0208;
	else if (it > 10 && it <= 20)
		data->color = 0xD00000;
	else if (it > 20 && it <= 40)
		data->color = 0xDC2F02;
	else if (it > 40 && it <= 80)
		data->color = 0xE85E04;
	else if (it > 80 && it <= 120)
		data->color = 0xF48C06;
	else if (it > 120 && it <= 130)
		data->color = 0x6A040F;
	else if (it > 130 && it <= 150)
		data->color = 0xFAA307;
	else if (it > 150 && it <= 175)
		data->color = 0xD00000;
	else if (it > 175 && it < 200)
		data->color = 0xFFBA08;
}

void	nature_set(t_data *data, int it)
{
	if (it >= 0 && it <= 1)
		data->color = 0x10451D;
	else if (it > 1 && it <= 2)
		data->color = 0x155D27;
	else if (it > 2 && it <= 5)
		data->color = 0x1A7431;
	else if (it > 5 && it <= 10)
		data->color = 0x208B3A;
	else if (it > 10 && it <= 20)
		data->color = 0x25A244;
	else if (it > 20 && it <= 40)
		data->color = 0x10451D;
	else if (it > 40 && it <= 80)
		data->color = 0x2DC653;
	else if (it > 80 && it <= 120)
		data->color = 0x4AD66D;
	else if (it > 120 && it <= 130)
		data->color = 0x155D27;
	else if (it > 130 && it <= 150)
		data->color = 0x6EDE8A;
	else if (it > 150 && it <= 175)
		data->color = 0x208B3A;
	else if (it > 175 && it < 200)
		data->color = 0xB7EFC5;
}

void	default_set(t_data *data, int it)
{
	if (data->color_set == DEFAULT)
		data->color = (0xFCBE11 * it);
	else if (data->color_set == DEFAULT_BIS)
		data->color = (0xFCBE11 * it % 128);
}

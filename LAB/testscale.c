/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:30:31 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/13 14:33:20 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double	scale(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i < 41)
	{
		printf("%d = %f\n", i, scale(i, -2.0, 2.0, 0, 40));
		i++;
	}

	// i = 5;
	// printf("%d = %f\n", i, scale((double)i, -2.0, 2.0, 0, 199));
}
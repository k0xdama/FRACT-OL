/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsquarecomplex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 04:07:33 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/13 04:18:15 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;


void	square_complex(t_complex *z)
{
	double tmp_real;
	
	tmp_real = 0.0;
	tmp_real = (z->real * z->real) - (z->i * z->i);
	z->i = 2 * z->real * z->i;
	z->real = tmp_real;
}

int	main(void)
{
	t_complex	result;

	result.real = 5.0;
	result.i = 2.0;
	square_complex(&result);
	printf("real = %f imaginary = %f\n", result.real, result.i);
}
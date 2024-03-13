/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcomplex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:56:08 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/13 03:35:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_complex
{
	double real;
	double i;
}		t_complex;

double handle_decimals(char *str)
{
	double	decimals;
	
	decimals = 0;
	while ((*str >= '0' && *str <= '9') && (*str))
	{
		decimals = decimals / 10 + (*str - '0');
		str++;
	}
	return (decimals);
}

double	atodbl(char	*str)
{
	double	result;
	double decimals;
	double	sign;
	int	i;
	
	result = 0.0;
	decimals = 0.0;
	sign = 1.0;
	i = 0;

	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			sign *= -1;
		while (str[i] <= '0' && str[i] >= '9')
			i++;
		while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '.'))
		{
			result = result * 10 + (*str - '0');
			i++;
		}
		if (str[i] == '.')
			decimals = handle_decimals(str+i+1);
	}
	return ((result + decimals) * sign);
}

int	main(int argc, char *argv[])
{
	t_complex z;
	t_complex c;
	double	tmp_real;
	int i;
	i = 0;
	if (argc < 3)
		return (1);
	z.real = 0;
	z.i	= 0;

	c.real = atodbl(argv[1]);
	c.i = atodbl(argv[2]);

	while (i < 42)
	{
		tmp_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_real;
		z.real += c.real;
		z.i += c.i;
		printf("iteration %d = real %f imaginary %f\n", i, z.real, z.i);
		i++;
	}
}

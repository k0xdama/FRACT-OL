/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcomplex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:56:08 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/18 03:45:58 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

double handle_decimals(char *str)
{
	double	decimals;
	double	divisor;
	
	decimals = 0;
	divisor = 1;
	while ((*str >= '0' && *str <= '9') && (*str))
	{
		divisor /= 10;
		decimals = decimals + (*str - '0') * divisor;
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
		{
			sign *= -1;
			i++;
		}
		while (str[i] <= '0' && str[i] >= '9')
			i++;
		while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '.'))
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		if (str[i] == '.')
			decimals = handle_decimals(str+i+1);
	}
	return ((result + decimals) * sign);
}

int	main(int argc, char *argv[])
{
	char *str = "-1.767";
	printf("%f\n", atodbl(str));
}

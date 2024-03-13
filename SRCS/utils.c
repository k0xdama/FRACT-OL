/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:23:36 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/13 04:30:26 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

int	prog_exit()
{
	
}

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
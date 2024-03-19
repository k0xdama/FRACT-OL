/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:23:36 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 04:11:18 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

int	prog_exit(t_data *data, int status)
{
	if (data->img)
		mlx_destroy_image(data->mlxptr, data->img);
	if (data->winptr)
		mlx_destroy_window(data->mlxptr, data->winptr);
	if (data->mlxptr)
	{
		mlx_loop_end(data->mlxptr);
		mlx_destroy_display(data->mlxptr);
		free(data->mlxptr);
		data->mlxptr = NULL;
	}
	exit(status);
}

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
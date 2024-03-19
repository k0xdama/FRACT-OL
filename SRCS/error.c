/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:11:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 22:32:17 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	bad_args(t_data *data)
{
	ft_printf("\033[1;5;31mWARNING\n\033[0m");
	ft_printf("\033[31mThere is a problem with given arguments, ");
	ft_printf("their number is incorrect or ");
	ft_printf("they're not as expected.\n\n\033[0m");
	ft_printf("\033[1;31mREMINDER :\n\n\033[0m");
	fractol_man();
	ft_printf("\033[1;5;31mExiting program...\n\033[0m");
	prog_exit(data, EXIT_FAILURE);
}

void	fractol_man(void)
{
	ft_printf("\033[1;35m#############################FRACTOL");
	ft_printf("###############################################\n\033[0m");
	ft_printf("\033[35mFor use this program u need to choose ");
	ft_printf("the number of the fractal u want to generate.\n\033[0m");
	ft_printf("\n");
	ft_printf("\033[1;35mAVAILABLE FRACTALS :\033[0m");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\033[35m- ENSEMBLE DE JULIA  \033[0m\033[5;35m(1)\n\033[0m");
	ft_printf("\033[35m- MANDELBROT  \033[0m\033[5;35m(2)\n\033[0m");
	ft_printf("\033[35m- MANDELBOX  \033[0m\033[5;35m(3)\n\033[0m");
	ft_printf("\n");
	ft_printf("\033[35mFor the Julia's set u can specify two ");
	ft_printf("values in the arguments that represents\n\033[0m");
	ft_printf("\033[35mthe real and imaginary values ");
	ft_printf("of the Julia formula.\n\033[0m");
	ft_printf("\033[35mThese are two decimal values written with a point, ");
	ft_printf("not a comma, and must fit between 2.0 and -2.0.\n\033[0m");
	ft_printf("\033[4;35mExample : ./fractol 1 x.xx y.yy\n\033[0m");
	ft_printf("\033[1;35m##########################################");
	ft_printf("#########################################\n\033[0m");
}

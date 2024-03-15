/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:11:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/15 00:51:17 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"

void	bad_args()
{
	ft_printf("WARNING :\n");
	ft_printf("There is a problem with given arguments, their number is incorrect or they're not as expected.\n");
	ft_printf("REMINDER :\n");
	fractol_man();
	ft_printf("Exiting progam...\n");
	prog_exit();
}

void	fractol_man()
{
	ft_printf("################FRACTOL################\n");
	ft_printf("Pour utiliser ce programme vous devez specifier un numero selon la fractal que vous souhaitez generer.\n");
	ft_printf("Voici les fractales disponibles :\n");
	ft_printf("- ENSEMBLE DE JULIA (1)\n");
	ft_printf("- MANDELBROT(2)\n");
	ft_printf("- MANDELBOX(3)\n");
	ft_printf(" Pour l'ensemble de julia vous pouvez si vous le souhaitez specifier juste apres les valeurs de departs,\n");
	ft_printf("ce sont deux valeurs decimales ecrites avec un point et non une virgule et qui doivent se trouver entre 2.0 et -2.0.\n");
	ft_printf("Exemple : ./fractol 1 x.xx x.xx\n");
}
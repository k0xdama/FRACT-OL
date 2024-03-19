/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:29:38 by pmateo            #+#    #+#             */
/*   Updated: 2024/03/19 03:38:36 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fractol.h"


static void	move_udlr(int orientation, double distance, t_data *data)
{
	t_complex c;

	c.real = data->xmax - data->xmin;
	c.i = data->ymax - data->ymin;
	if (orientation == UP)
	{
		data->ymax = data->ymax + (c.i * distance);
		data->ymin = data->ymin + (c.i * distance);
	}
	else if (orientation == DOWN)
	{
		data->ymax = data->ymax - (c.i * distance);
		data->ymin = data->ymin - (c.i * distance);
	}
	else if (orientation == LEFT)
	{
		data->xmax = data->xmax - (c.real * distance);
		data->xmin = data->xmin - (c.real * distance);
	}
	else if (orientation == RIGHT)
	{
		data->xmax = data->xmax + (c.real * distance);
		data->xmin = data->xmin + (c.real * distance);
	}
}

static void	mouse_zoom(double m, t_data *data)
{
	t_complex c;

	c.real = data->xmin - data->xmax;
	c.i = data->ymax - data->ymin;
	data->xmax = data->xmax + (c.real - m * c.real) / 2;
	data->xmin = data->xmax + m * c.real;
	data->ymin = data->ymin + (c.i - m * c.i) / 2;
	data->ymax = data->ymin + m * c.i;
}

int	handle_keypress(int keysm, t_data *data)
{
	if (keysm == XK_Escape)
		prog_exit(data, EXIT_SUCCESS);
	else if (keysm == UP)
		move_udlr(UP, 0.1, data);
	else if (keysm == DOWN)
		move_udlr(DOWN, 0.1, data);
	else if (keysm == LEFT)
		move_udlr(LEFT, 0.1, data);
	else if (keysm == RIGHT)
		move_udlr(RIGHT, 0.1, data);
	fractal_render(data);
	return (0);
}

int	handle_mouse(int keysm, int x, int y, t_data *data)
{
	if (keysm == Mdown)
		mouse_zoom(2, data);
	else if (keysm == Mup)
	{
		mouse_zoom(0.5, data);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move_udlr(LEFT, (double)x * -1 / WIDTH, data);
		else if (x > 0)
			move_udlr(RIGHT, (double)x / WIDTH, data);
		if (y < 0)
			move_udlr(UP, (double)y * -1 / HEIGHT, data);
		else if (y > 0)
			move_udlr(DOWN, (double)y / HEIGHT, data);
	}
	else
		return (0);
	fractal_render(data);
	return (0);
}
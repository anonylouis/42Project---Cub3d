/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_border.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:37:21 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/30 18:14:59 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	find_next_border_90(double *x, double *y, double angle)
{
	double	x_border;
	double	y_border;
	double	temp;

	y_border = ceil(*y - 1);
	x_border = floor(*x + 1);
	temp = tan((-1) * rad(angle)) * (x_border - *x) + *y;
	if (temp >= y_border)
	{
		*x = x_border;
		*y = temp;
		return (3);
	}
	*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
	*y = y_border;
	return (0);
}

static int	find_next_border_180(double *x, double *y, double angle)
{
	double	x_border;
	double	y_border;
	double	temp;

	y_border = ceil(*y - 1);
	x_border = ceil(*x - 1);
	temp = tan((-1) * rad(angle)) * (x_border - *x) + *y;
	if (temp >= y_border)
	{
		*x = x_border;
		*y = temp;
		return (1);
	}
	*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
	*y = y_border;
	return (0);
}

static int	find_next_border_270(double *x, double *y, double angle)
{
	double	x_border;
	double	y_border;
	double	temp;

	y_border = floor(*y + 1);
	x_border = ceil(*x - 1);
	temp = tan((-1) * rad(angle)) * (x_border - *x) + *y;
	if (temp <= y_border)
	{
		*x = x_border;
		*y = temp;
		return (1);
	}
	*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
	*y = y_border;
	return (2);
}

static int	find_next_border_360(double *x, double *y, double angle)
{
	double	x_border;
	double	y_border;
	double	temp;

	y_border = floor(*y + 1);
	x_border = floor(*x + 1);
	temp = tan((-1) * rad(angle)) * (x_border - *x) + *y;
	if (temp <= y_border)
	{
		*x = x_border;
		*y = temp;
		return (3);
	}
	*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
	*y = y_border;
	return (2);
}

int	find_next_border(double *x, double *y, double angle)
{
	if (angle == 90 || angle == 270)
	{
		if (angle == 90)
		{
			*y = ceil(*y - 1);
			return (0);
		}
		*y = floor(*y + 1);
		return (2);
	}
	else if (angle <= 90)
		return (find_next_border_90(x, y, angle));
	else if (angle <= 180)
		return (find_next_border_180(x, y, angle));
	else if (angle <= 270)
		return (find_next_border_270(x, y, angle));
	else
		return (find_next_border_360(x, y, angle));
}

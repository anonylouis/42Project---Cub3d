/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:23:31 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/03 14:29:52 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double rad(double angle)
{
	return (angle * M_PI / 180);
}

int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

double dmin(double a, double b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

void	correct_angle(double *angle)
{
	while(*angle < 0)
		*angle += 360.0;
	while(*angle >= 360.0)
		*angle -= 360;
}

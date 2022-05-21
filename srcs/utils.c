/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:23:31 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/18 15:35:39 by lcalvie          ###   ########.fr       */
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

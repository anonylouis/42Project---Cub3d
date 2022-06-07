/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:43:59 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 12:52:28 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_orientation(char c)
{
	return (c == 'W' || c == 'N' || c == 'E' || c == 'S');
}

int	has_orientation(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (is_orientation(s[i]))
			return (i);
		i++;
	}
	return (-1);
}

void	set_angle_vision(t_game *game)
{
	if (game->orientation == 'E')
		game->angle_vision = 0;
	else if (game->orientation == 'N')
		game->angle_vision = 90;
	else if (game->orientation == 'W')
		game->angle_vision = 180;
	else
		game->angle_vision = 270;
}

t_check_result	check_orientation(char **s, int start)
{
	int	i;
	int	j;
	int	orientation;

	i = start;
	j = 0;
	orientation = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (is_orientation(s[i][j]))
				orientation++;
			j++;
		}
		i++;
	}
	if (orientation == 0)
		return (error("Error : map must have one orientation"));
	if (orientation > 1)
		return (error("Error : map must have only one orientation"));
	return (success());
}

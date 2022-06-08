/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:16:54 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/08 11:26:59 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color	empty_color(void)
{
	t_color	t;

	t.blue = -1;
	t.green = -1;
	t.red = -1;
	return (t);
}

void	set_orientation(char *line, int index, t_game *game)
{
	int	orientation_index;

	orientation_index = 0;
	orientation_index = has_orientation(line);
	if (orientation_index != -1)
	{
		game->orientation = line[orientation_index];
		set_angle_vision(game);
		game->player_x = orientation_index + 0.5;
		game->player_y = index + 0.5;
	}
}

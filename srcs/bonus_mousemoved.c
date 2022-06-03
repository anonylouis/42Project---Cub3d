/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mousemoved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:14:55 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/03 15:19:12 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mousemoved(t_graph *graph)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(graph->mlx_ptr, graph->win_ptr, &x, &y);
	if (x < MOVED_LEFT)
		graph->game.angle_vision = graph->game.angle_vision
			- ((double) x / (WIDTH - 1) - MOUSE_MOVED_LEFT) * SPEED_ANGLE;
	else if (x > MOVED_RIGHT)
		graph->game.angle_vision = graph->game.angle_vision
			- ((double) x / (WIDTH - 1) - MOUSE_MOVED_RIGHT) * SPEED_ANGLE;
	else
		return (0);
	if (graph->game.angle_vision >= 360)
		graph->game.angle_vision -= 360;
	else if (graph->game.angle_vision < 0)
		graph->game.angle_vision += 360;
	print_game(graph);
	return (0);
}

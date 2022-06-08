/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_boost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:22:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 15:05:17 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_textures_boost(t_graph *graph)
{
	if (init_texture(graph, &(graph->boost1), FRAME1))
		return (1);
	if (init_texture(graph, &(graph->boost2), FRAME2))
		return (1);
	if (init_texture(graph, &(graph->boost3), FRAME3))
		return (1);
	if (init_texture(graph, &(graph->boost4), FRAME4))
		return (1);
	return (0);
}

void	update_boost(t_graph *graph)
{
	t_special_block	*temp;

	if (graph->is_boost > 1.0)
	{
		graph->is_boost -= 0.01;
		if (graph->is_boost < 1.0)
			graph->is_boost = 1.0;
	}
	temp = graph->game.boost;
	while(temp != NULL)
	{
		if (temp->percent != 1.0)
		{
			temp->percent += SPEED_CHARGE_BOOST;
			if (temp->percent >= 1.0)
				temp->percent = 1.0;
		}
		temp = temp->next;
	}
}

int	take_boost(t_graph *graph)
{
	t_special_block	*temp;

	temp = graph->game.boost;
	while(temp != NULL)
	{
		if (temp->percent == 1.0)
		{
			if (graph->game.player_x > (double) temp->x - TRIGGER_BOOST
			&& graph->game.player_x < (double) temp->x + 1.0 + TRIGGER_BOOST
			&& graph->game.player_y > (double) temp->y - TRIGGER_BOOST
			&& graph->game.player_y < (double) temp->y + 1.0 + TRIGGER_BOOST)
			{
				temp->percent = 0.0;
				graph->is_boost = 2.5;
				print_game(graph);
				return (0);
			}
		}
		temp = temp->next;
	}
	return (0);
}

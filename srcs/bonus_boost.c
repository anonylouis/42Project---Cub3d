/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_boost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:22:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 16:14:52 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

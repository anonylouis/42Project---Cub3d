/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:58:13 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 20:17:56 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	update_door(t_graph *graph)
{
	t_special_block *temp;

	temp = graph->door;
	while (temp != NULL)
	{
		if (temp->open_close == 1 && temp->percent != 1.0)
		{
			temp->percent += SPEED_DOOR_OPENING;
			if (temp->percent > 1.0)
				temp->percent = 1.0;
		}
		else if (temp->open_close == -1 && temp->percent != 0.01)
		{
			temp->percent -= SPEED_DOOR_OPENING;
			if (temp->percent < 0.01)
				temp->percent = 0.01;
		}
		temp = temp->next;
	}
	print_game(graph);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:24 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 14:07:00 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_color_door(t_graph *graph)
{
	graph->game.door.red = (DOOR_COLOR / 65536) % 256;
	graph->game.door.green = (DOOR_COLOR / 256) % 256;
	graph->game.door.blue = DOOR_COLOR % 256;
}


void	draw_doors(t_graph *graph, int column)
{
	double d;
	double h;
	t_special_block *temp;
	t_special_block *lst_max;
	int		start;
	int		end;
	int		j;

	temp = graph->door;
	lst_max = temp;
	while (temp)
	{
		if (temp != graph->door && temp->percent > lst_max->percent)
			lst_max = temp;
		temp = temp->next;
	}
	d = distance(graph->game.player_x, graph->game.player_y, lst_max->x, lst_max->y);
	h = (HEIGHT / (2.0 *(d + H_MAX))) * lst_max->percent;
	start = max(0, (int)(HEIGHT / 2 - h / 2));
	end = min(HEIGHT, (int)(HEIGHT / 2 + h / 2));
	j = start;
	while (j < end)
	{
		add_pixel_img(graph->img, column, j, graph->game.door);
		j++;
	}
}

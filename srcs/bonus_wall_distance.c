/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wall_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:25:58 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 15:05:25 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_boost(t_graph *graph, int i, int j)
{
	t_special_block	*boost;

	if (graph->game.map[i][j] != '1')
		return (0);
	boost = find_boost(graph, i, j);
	if (boost == NULL)
		return (1);
	else if (boost->percent == 1.0)
		graph->hit_boost = 4;
	else if (boost->percent <= 0.33)
		graph->hit_boost = 1;
	else if (boost->percent <= 0.66)
		graph->hit_boost = 2;
	else
		graph->hit_boost = 3;
	return (1);
}

static int	is_a_wall(t_graph *graph, double x, double y, double angle)
{
	int	i;
	int	j;

	if (angle <= 90)
	{
		i = ceil(y - 1);
		j = floor(x);
	}
	else if (angle <= 180)
	{
		i = ceil(y - 1);
		j = ceil(x - 1);
	}
	else if (angle <= 270)
	{
		i = floor(y);
		j = ceil(x - 1);
	}
	else
	{
		i = floor(y);
		j = floor(x);
	}
	return (check_boost(graph, i, j));
}

static void	add_door_and_distance(t_graph *graph, double x,
			double y, t_special_block *door_found)
{
	if (door_found == NULL )
		return ;
	door_found->next = NULL;
	door_found->intersection_x = x;
	door_found->intersection_y = y;
	door_found->distance = distance(graph->game.player_x,
			graph->game.player_y, x, y);
	door_found->face = graph->face;
	special_block_add_back(&(graph->hit_door), door_found);
	graph->last_hit_door = 1 - graph->last_hit_door;
}

static void	add_doors(t_graph *g, double x, double y, double angle)
{
	int	i;
	int	j;

	if (angle <= 90)
	{
		i = ceil(y - 1);
		j = floor(x);
	}
	else if (angle <= 180)
	{
		i = ceil(y - 1);
		j = ceil(x - 1);
	}
	else if (angle <= 270)
	{
		i = floor(y);
		j = ceil(x - 1);
	}
	else
	{
		i = floor(y);
		j = floor(x);
	}
	if (g->last_hit_door == 1 || g->game.map[i][j] == 'D')
		add_door_and_distance(g, x, y, copy_special_block(find_door(g, i, j)));
}

double	wall_distance(t_graph *graph, double angle)
{
	double	x;
	double	y;
	double	d;

	x = graph->game.player_x;
	y = graph->game.player_y;
	graph->face = -1;
	special_block_clear(&(graph->hit_door));
	graph->last_hit_door = 0;
	graph->hit_boost = 0;
	while (graph->face == -1 || !is_a_wall(graph, x, y, angle))
	{
		graph->face = find_next_border(&x, &y, angle);
		add_doors(graph, x, y, angle);
	}
	d = distance(graph->game.player_x, graph->game.player_y, x, y);
	if (graph->face == 0)
		graph->percent_face = x;
	else if (graph->face == 1)
		graph->percent_face = 1 - y;
	else if (graph->face == 2)
		graph->percent_face = 1 - x;
	else
		graph->percent_face = y;
	return (d);
}

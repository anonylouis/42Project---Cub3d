/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_special_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:35:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 15:15:22 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_special_block	*new_special_block(int pt_y, int pt_x, double pc)
{
	t_special_block	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->x = pt_x;
	new->y = pt_y;
	new->percent = pc;
	new->distance = 0.0;
	new->next = 0;
	new->open_close = 1;
	return (new);
}

t_special_block	*copy_special_block(t_special_block *copy)
{
	t_special_block	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->x = copy->x;
	new->y = copy->y;
	new->percent = copy->percent;
	new->distance = copy->distance;
	new->next = 0;
	return (new);
}

int	special_block_add_back(t_special_block **begin_list, t_special_block *new)
{
	t_special_block	*tt;

	if (new == NULL)
		return (0);
	if (!*begin_list)
	{
		*begin_list = new;
		return (1);
	}
	tt = *begin_list;
	while (tt->next)
		tt = tt->next;
	tt->next = new;
	return (1);
}

int	init_special_blocks(t_graph *graph)
{
	int	i;
	int	j;

	i = -1;
	while (graph->game.map[++i] != NULL)
	{
		j = -1;
		while (graph->game.map[i][++j])
		{
			if (graph->game.map[i][j] == 'D')
			{
				if (!special_block_add_back(&(graph->door),
					new_special_block(i, j, 1.0)))
						return (0);
			}
		}
	}
	return (1);
}

t_special_block	*find_door(t_graph *graph, int i, int j)
{
	t_special_block	*temp;

	if (graph->last_hit_door == 1)
	{
		temp = graph->hit_door;
		while (temp->next != NULL)
			temp = temp->next;
		return (temp);
	}
	temp = graph->door;
	while (temp != NULL)
	{
		if (temp->x == j && temp->y == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_special_block	*find_boost(t_graph *graph, int i, int j)
{
	t_special_block	*temp;

	temp = graph->game.boost;
	while (temp != NULL)
	{
		if (temp->x == j && temp->y == i)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

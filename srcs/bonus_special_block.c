/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_special_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:35:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 14:05:44 by lcalvie          ###   ########.fr       */
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
			/*if (graph->game.map[i][j] == 'B')
			{
				if (!specal_block_add_back(&(graph->boost), new_special_block(i, j, 0.0)))
					return (0);
				printf("boost en [%d][%d]\n",i, j);
			}*/
			if (graph->game.map[i][j] == 'D')
			{
				if (!special_block_add_back(&(graph->door),
					new_special_block(i, j, 100.0)))
						return (0);
				printf("porte en [%d][%d]\n", i, j);
			}
		}
	}
	return (1);
}

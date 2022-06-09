/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_special_block2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:54:12 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 14:59:15 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	special_block_clear(t_special_block **begin_list)
{
	t_special_block	*t;
	t_special_block	*lst;

	lst = *begin_list;
	while (lst)
	{
		t = lst->next;
		free(lst);
		lst = t;
	}
	*begin_list = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_lst_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:14:30 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 19:43:27 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/*
static int	size_special_block(t_special_block *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
*/
static void	ft_int_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_double_swap(double *a, double *b)
{
	double	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	swap_special_block(t_special_block *a, t_special_block *b)
{
	ft_int_swap(&(a->x), &(b->x));
	ft_int_swap(&(a->y), &(b->y));
	ft_int_swap(&(a->face), &(b->face));
	ft_double_swap(&(a->intersection_x), &(b->intersection_x));
	ft_double_swap(&(a->intersection_y), &(b->intersection_y));
	ft_double_swap(&(a->percent), &(b->percent));
	ft_double_swap(&(a->distance), &(b->distance));
}

void	sort_special_block(t_special_block *lst)
{
	t_special_block *temp1;
	t_special_block *temp2;

	temp1 = lst;
	while(temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->distance < temp2->distance)
				swap_special_block(temp1, temp2);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

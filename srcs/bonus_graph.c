/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:05:15 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 14:58:51 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_graph	*new_graph(void)
{
	t_graph	*graph;

	graph = malloc(sizeof(t_graph));
	if (graph == NULL)
		return (NULL);
	graph->mlx_ptr = mlx_init();
	if (graph->mlx_ptr == NULL)
	{
		free(graph);
		return (NULL);
	}
	graph->win_ptr = mlx_new_window(graph->mlx_ptr, WIDTH, HEIGHT, "CUB'3D");
	init_img_addr(graph, &(graph->img), WIDTH, HEIGHT);
	graph->door = NULL;
	graph->is_boost = 1.0;
	mlx_set_font(graph->mlx_ptr, graph->win_ptr,"-sony-*-*-*-*-*-24-230-*-*-*-*-*-1");
	return (graph);
}

void	free_graph(t_graph *graph)
{
	if (graph)
	{
		mlx_destroy_image(graph->mlx_ptr, graph->wall_NO.img_ptr);
		mlx_destroy_image(graph->mlx_ptr, graph->wall_EA.img_ptr);
		mlx_destroy_image(graph->mlx_ptr, graph->wall_SO.img_ptr);
		mlx_destroy_image(graph->mlx_ptr, graph->wall_WE.img_ptr);
		mlx_destroy_image(graph->mlx_ptr, graph->img.img_ptr);
		mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_display(graph->mlx_ptr);
		free(graph->mlx_ptr);
		free(graph);
	}
}
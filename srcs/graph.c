/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:23:41 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/12 15:35:31 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_graph *new_graph()
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
	init_img_addr(graph, &(graph->img), WIDTH);
	ft_bzero(graph->img.img_addr, WIDTH * HEIGHT * 4);
	return (graph);
}

void	free_graph(t_graph *graph)
{
	if (graph)
	{
		//mlx_destroy_image(graph->mlx_ptr, graph->img_ptr);
		mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_display(graph->mlx_ptr);
		free(graph->mlx_ptr);
		free(graph);
	}
}
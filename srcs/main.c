/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/31 23:04:30 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int main(int argc, char **argv)
{

	t_graph *graph;
	t_game *game;

	graph = new_graph();
	if (!graph)
		return (1);

	if (argc != 2)
	{
		printf("Usage : ./cube3D <path_to_map>\n");
		return (1);
	}
	game = parse(argv[1]);
	if (game == NULL)
		return (1);
	if(!validate_game(game))
		return (1);
	
	graph->game = *game;

	if (init_textures(graph))
	{
		free_graph(graph);
		return (1);
	}
	play(graph);

	free_graph(graph);
	return (0);
}
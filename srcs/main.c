/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/05 23:10:36 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int exit_game(t_graph *graph, t_game *game, int ret)
{
	free_graph(graph);
	free_game(game);
	return (ret);
}

int main(int argc, char **argv)
{
	t_graph *graph;
	t_game *game;

	if (argc != 2)
		return print_error("Usage : ./cube3D <path_to_map>\n", 1);
	game = parse(argv[1]);
	if (game == NULL)
		return exit_game(NULL, game, 1);
	if (!validate_game(game))
		return exit_game(NULL, game, 1);
	graph = new_graph();
	if (!graph)
		return (1);
	graph->game = *game;
	if (init_textures(graph))
		return exit_game(graph, game, 1);
	play(graph);
	return exit_game(graph, game, 0);
}
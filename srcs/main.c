/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/30 23:52:06 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

// DELETE THIS BEFORE PUSH
void print(t_game *game)
{
	int i = 0;

	printf("EA : %s\n", game->path_wall_EA);
	printf("NO : %s\n", game->path_wall_NO);
	printf("SO : %s\n", game->path_wall_SO);
	printf("WE : %s\n", game->path_wall_WE);
	printf("F : %d %d %d\n", game->floor.red, game->floor.green, game->floor.blue);
	printf("C : %d %d %d\n", game->ceiling.red, game->ceiling.green, game->ceiling.blue);
	printf("Orienatation : %c\n", game->orientation);
	printf("Angle vision : %f\n", game->angle_vision);

	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i++]);
	}
}

int file_exists(char *path)
{
	int fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int validate_game(t_game *game)
{
	if (is_empty_color(game->ceiling))
		return print_error("missing ceiling color\n", 0);
	if (is_empty_color(game->floor))
		return print_error("missing floor color\n", 0);
	if (!file_exists(game->path_wall_EA))
		return print_error("east wall path not found\n", 0);
	if (!file_exists(game->path_wall_SO))
		return print_error("south wall path not found\n", 0);
	if (!file_exists(game->path_wall_WE))
		return print_error("west wall path not found\n", 0);
	if (!file_exists(game->path_wall_NO))
		return print_error("north wall path not found\n", 0);
	if (count(game->map) <= 0)
		return print_error("missing map\n", 0);
	return (1);
}

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
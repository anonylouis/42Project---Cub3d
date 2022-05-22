/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/22 23:26:39 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

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

// DELETE THIS AFTER PARSING PART DONE

// CHECKER LES VALEURS DES DEFINES AU DEBUT DU MAIN
void main_test(t_graph *graph)
{
	char **map = malloc(sizeof(char *) * 7);
	for (int i = 0; i < 6; i++)
		map[i] = malloc(sizeof(char) * 7);
	map[0][0] = '1';
	map[0][1] = '1';
	map[0][2] = '1';
	map[0][3] = '1';
	map[0][4] = '1';
	map[0][5] = '1';
	map[0][6] = 0;
	map[1][0] = '1';
	map[1][1] = '0';
	map[1][2] = '0';
	map[1][3] = '0';
	map[1][4] = '0';
	map[1][5] = '1';
	map[1][6] = 0;
	map[2][0] = '1';
	map[2][1] = '0';
	map[2][2] = '0';
	map[2][3] = 'N';
	map[2][4] = '0';
	map[2][5] = '1';
	map[2][6] = 0;
	map[3][0] = '1';
	map[3][1] = '1';
	map[3][2] = '0';
	map[3][3] = '0';
	map[3][4] = '0';
	map[3][5] = '1';
	map[3][6] = 0;
	map[4][0] = ' ';
	map[4][1] = '1';
	map[4][2] = '0';
	map[4][3] = '0';
	map[4][4] = '0';
	map[4][5] = '1';
	map[4][6] = 0;
	map[5][0] = ' ';
	map[5][1] = '1';
	map[5][2] = '1';
	map[5][3] = '1';
	map[5][4] = '1';
	map[5][5] = '1';
	map[5][6] = 0;
	map[6] = NULL;

	//graph->game = *parse("./file.cub");

	graph->game.map = map;
	if (graph->game.map[2][3] == 'E') // si le perso est un N au depart
		graph->game.angle_vision = 0;
	else if (graph->game.map[2][3] == 'N')
		graph->game.angle_vision = 90;
	else if (graph->game.map[2][3] == 'W')
		graph->game.angle_vision = 180;
	else if (graph->game.map[2][3] == 'S')
		graph->game.angle_vision = 270;

	graph->game.player_x = 3.5; // milieu de la case;
	graph->game.player_y = 2.5; // milieu de la case;

	graph->game.path_wall_NO = ft_strdup("./xpm/wall_N.xpm");

	graph->game.floor.red = 255;
	graph->game.floor.green = 128;
	graph->game.floor.blue = 0;

	graph->game.ceiling.red = 0;
	graph->game.ceiling.green = 255;
	graph->game.ceiling.blue = 0;
}

int main()
{


	t_graph *graph;

	graph = new_graph();
	if (!graph)
		return (1);

	// parsing part here
	// remplir graph->game

	// delete main test after parsing part finished
	main_test(graph);

	if (init_textures(graph))
	{
		free_graph(graph);
		return (1);
	}

	// raycasting part

	play(graph);

	// free
	free_graph(graph);
	return (0);
}
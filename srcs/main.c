/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/13 16:50:35 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//DELETE THIS AFTER PARSING PART DONE

// CHECKER LES VALEURS DES DEFINES AU DEBUT DU MAIN
void    main_test(t_graph *graph)
{
        char **map = malloc(sizeof(char *) * 7);
        for(int i = 0; i < 6; i++)
                map[i] = malloc (sizeof(char) * 7);
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
        map[2][3] = 'W';
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

        graph->game.map = map;
        if (map[2][3] == 'E') // si le perso est un N au depart
                graph->game.angle_vision = 0;
        else if (map[2][3] == 'N')
                graph->game.angle_vision = 90;
        else if (map[2][3] == 'W')
                graph->game.angle_vision = 180;
        else if (map[2][3] == 'S')
                graph->game.angle_vision = 270;

        graph->game.player_x = 3.5; // milieu de la case;
        graph->game.player_y = 2.5; //milieu de la case;
}

int main()
{
        t_graph *graph;

        // parsing part here

        // ray casting part

        graph = new_graph();
        main_test(graph);
        if (graph)
                play(graph);
        free_graph(graph);
        return (0);
}

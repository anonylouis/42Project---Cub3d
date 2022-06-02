/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:47 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/02 13:29:50 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    init_color_minimap(t_graph *graph)
{
        graph->game.minimap_contour.red = (MINIMAP_COLOR_CONTOUR / 65536) % 256;
        graph->game.minimap_contour.green = (MINIMAP_COLOR_CONTOUR / 256) % 256;
        graph->game.minimap_contour.blue = MINIMAP_COLOR_CONTOUR % 256;

        graph->game.minimap_wall.red = (MINIMAP_COLOR_WALL / 65536) % 256;
        graph->game.minimap_wall.green = (MINIMAP_COLOR_WALL / 256) % 256;
        graph->game.minimap_wall.blue = MINIMAP_COLOR_WALL % 256;

	graph->game.minimap_floor.red = (MINIMAP_COLOR_FLOOR / 65536) % 256;
        graph->game.minimap_floor.green = (MINIMAP_COLOR_FLOOR / 256) % 256;
        graph->game.minimap_floor.blue = MINIMAP_COLOR_FLOOR % 256;

	graph->game.minimap_player.red = (MINIMAP_COLOR_PLAYER / 65536) % 256;
        graph->game.minimap_player.green = (MINIMAP_COLOR_PLAYER / 256) % 256;
        graph->game.minimap_player.blue = MINIMAP_COLOR_PLAYER % 256;
}

void    print_minimap(t_graph *graph)
{
        int     i;
        int     j;
        int     x_minimap;
        int     y_minimap;

        i = -1;
        while (++i < MINIMAP_SIZE)
        {
                j = -1;
                while (++j < MINIMAP_SIZE)
                {
                        if (i < MINIMAP_CONTOUR || i >= MINIMAP_SIZE - MINIMAP_CONTOUR || j < MINIMAP_CONTOUR || j >= MINIMAP_SIZE - MINIMAP_CONTOUR)
                        {
                                add_pixel_img(graph->img, MINIMAP_X + i, MINIMAP_Y + j, graph->game.minimap_contour);
                        }
			else if (i >= MINIMAP_SIZE /2 - 2 && i <= MINIMAP_SIZE/2 + 2 && j >= MINIMAP_SIZE /2 - 2 && j <= MINIMAP_SIZE/2 + 2)
				add_pixel_img(graph->img, MINIMAP_X + i, MINIMAP_Y + j, graph->game.minimap_player);
                        else
                        {
                                x_minimap = floor(((double) i / (MINIMAP_SIZE - 1) - 0.5) * MINIMAP_N_CASE + graph->game.player_x);
                                y_minimap = floor(((double) j / (MINIMAP_SIZE - 1) - 0.5) * MINIMAP_N_CASE + graph->game.player_y);
                                if (y_minimap < 0 || y_minimap >= graph->game.nb_line_map || graph->game.map[y_minimap][x_minimap] != '1')
					add_pixel_img(graph->img, MINIMAP_X + i, MINIMAP_Y + j, graph->game.minimap_floor);
				else
					add_pixel_img(graph->img, MINIMAP_X + i, MINIMAP_Y + j, graph->game.minimap_wall);
                        }
                }
        }
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:47:47 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/01 16:52:13 by lcalvie          ###   ########.fr       */
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
}

void    print_minimap(t_graph *graph)
{
        int     i;
        int     j;
        double  x_minimap;
        double  y_minimap;

        i = -1;
        while (++i < MINIMAP_SIZE)
        {
                j = -1;
                while (++j < MINIMAP_SIZE)
                {
                        if (i < MINIMAP_CONTOUR || i >= MINIMAP_SIZE - MINIMAP_CONTOUR || j < MINIMAP_CONTOUR || j >= MINIMAP_SIZE - MINIMAP_CONTOUR)
                        {
                                add_pixel_img(graph->img, MINIMAP_SIZE + i, MINIMAP_SIZE + j, graph->game.minimap_contour);
                        }
                        else
                        {
                                x_minimap = ((double) i / (MINIMAP_SIZE - 1) - 0.5) * MINIMAP_N_CASE;
                                y_minimap = graph->game.player_y + x_minimap;
                                x_minimap += graph->game.player_x;
                                if ()
                        }
                }
                
        }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/12 16:27:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include <stdio.h>

void   draw_map(t_graph *graph)
{
        for (int i = 0; i < WIDTH; i++)
        {
                for(int j = 0; j < HEIGHT; j++)
                {
                        add_pixel_img(graph->img, i, j, 0xFF0000);
                }
        }
        mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->img.img_ptr,0, 0);
}

void    play(t_graph *graph)
{
        mlx_hook(graph->win_ptr, 33, 1L << 17, close_loop, graph);
        mlx_key_hook(graph->win_ptr, keycatch, graph);
        draw_map(graph);
	mlx_loop(graph->mlx_ptr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/12 18:15:58 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include <stdio.h>

void   print_game(t_graph *graph)
{
        int     i;
        int     j;

        //wall_distance(graph);
        i = -1;
        while (++i < WIDTH)
        {
                j = -1;
                while (++j < HEIGHT)
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
        print_game(graph);
	mlx_loop(graph->mlx_ptr);
}
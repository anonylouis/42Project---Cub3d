/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/18 03:06:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void   print_game(t_graph *graph)
{
        int     i;
        double  angle;
        double  fish_eye_correction;
        double  d;
        double x_wall;

        i = -1;
        printf("angle de base = %f\n", graph->game.angle_vision);
        while (++i < WIDTH)
        {
                angle = graph->game.angle_vision + ((double) i / (WIDTH - 1) - 0.5) * FOV;
                if (angle < 0)
                        angle +=360;
                else if (angle > 360)
                        angle -= 360;
                printf("----------------- check angle %f  -----------------------\n", angle);
                fish_eye_correction = ((double) i / (WIDTH - 1) - 0.5) * FOV;
                //A VERIFIER avec un FOV > 90 !! 
                while(fish_eye_correction >= 90)
                        fish_eye_correction -= 90;
				while(fish_eye_correction <= -90)
                        fish_eye_correction += 90;
				printf("correction : %f\n", fish_eye_correction);
                d = wall_distance(graph, angle, &x_wall);
                printf("DISTANCE TO WALL = %f\n", d);
                d = d * cos(rad(fish_eye_correction));
                printf("DISTANCE TO WALL = %f\n", d);
				printf("x_wall = %f\n", x_wall);
                draw_pixel_column(graph, WIDTH - 1 - i, d, x_wall);
        }
        /*
        i = -1;
        while (++i < WIDTH)
        {
                j = -1;
                while (++j < HEIGHT)
                {
                        add_pixel_img(graph->img, i, j, 0xFF0000);
                }
        }
        */
        mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->img.img_ptr,0, 0);
}

void    play(t_graph *graph)
{
        mlx_hook(graph->win_ptr, 33, 1L << 17, close_loop, graph);
        mlx_key_hook(graph->win_ptr, keycatch, graph);
        print_game(graph);
	mlx_loop(graph->mlx_ptr);
}
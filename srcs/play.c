/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/23 20:27:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void	print_game(t_graph *graph)
{
	int	i;
	double	angle;
	double	fish_eye_correction;
	double	d;
	double	x_wall;

	i = -1;
	//printf("angle de base = %f\n", graph->game.angle_vision);
	while (++i < WIDTH)
	{
		angle = graph->game.angle_vision + atan(((double)i / (WIDTH - 1) - 0.5)) * FOV / (2 * atan(0.5));
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		//printf("----------------- check angle %f  -----------------------\n", angle);
		fish_eye_correction = atan(((double)i / (WIDTH - 1) - 0.5)) * FOV / (2 * atan(0.5));
		//printf("correction : %f\n", fish_eye_correction);
		d = wall_distance(graph, angle, &x_wall);
		//printf("DISTANCE TO WALL = %f\n", d);
		d = d * cos(rad(fish_eye_correction));
		//printf("DISTANCE TO WALL = %f\n", d);
		//printf("x_wall = %f\n", x_wall);
		draw_pixel_column(graph, WIDTH - 1 - i, d, x_wall);
	}
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr, graph->img.img_ptr, 0, 0);
}

void	play(t_graph *graph)
{
	mlx_hook(graph->win_ptr, 33, 1L << 17, close_loop, graph);
	mlx_hook(graph->win_ptr, 2, 1L << 0, keycatch, graph);
	print_game(graph);
	mlx_loop(graph->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:22:59 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/30 18:26:59 by lcalvie          ###   ########.fr       */
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

	i = -1;
	while (++i < WIDTH)
	{
		angle = graph->game.angle_vision + atan(((double)i / (WIDTH - 1) - 0.5)) * FOV / (2 * atan(0.5));
		if (angle < 0)
			angle += 360;
		else if (angle > 360)
			angle -= 360;
		fish_eye_correction = atan((double)i / (WIDTH - 1) - 0.5) * FOV / (2 * atan(0.5));
		d = wall_distance(graph, angle);
		d = fabs(d * cos(rad(fish_eye_correction)));
		draw_pixel_column(graph, WIDTH - 1 - i, d);
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

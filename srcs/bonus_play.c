/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:31:45 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 15:11:07 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void	print_text(t_graph *graph)
{
	t_special_block	*temp;

	if (graph->is_boost > 1.0)
		mlx_string_put(graph->mlx_ptr, graph->win_ptr, 50, 50 , 0xFFFFFF, "boost activated");
	temp = graph->door;
	while (temp != NULL)
	{
		if (graph->game.player_x > (double) temp->x - TRIGGER_DOOR
			&& graph->game.player_x < (double) temp->x + 1.0 + TRIGGER_DOOR
			&& graph->game.player_y > (double) temp->y - TRIGGER_DOOR
			&& graph->game.player_y < (double) temp->y + 1.0 + TRIGGER_DOOR)
		{
			mlx_string_put(graph->mlx_ptr, graph->win_ptr, WIDTH/2 - 144, HEIGHT - 100 , 0xFFFFFF, "PRESS E TO OPEN / CLOSE THE DOOR !");
			return ;
		}
		temp = temp->next;
	}
	temp = graph->game.boost;
	while (temp != NULL)
	{
		if (graph->game.player_x > (double) temp->x - TRIGGER_BOOST
			&& graph->game.player_x < (double) temp->x + 1.0 + TRIGGER_BOOST
			&& graph->game.player_y > (double) temp->y - TRIGGER_BOOST
			&& graph->game.player_y < (double) temp->y + 1.0 + TRIGGER_BOOST)
		{
			mlx_string_put(graph->mlx_ptr, graph->win_ptr, WIDTH/2 - 144, HEIGHT - 100 , 0xFFFFFF, "PRESS R TO TAKE BOOST !");
			return ;
		}
		temp = temp->next;
	}
}


void	print_game(t_graph *graph)
{
	int		i;
	double	angle;
	double	fish_eye_correction;
	double	d;

	i = -1;
	while (++i < WIDTH)
	{
		angle = graph->game.angle_vision
			+ atan(((double)i / (WIDTH - 1) - 0.5)) * FOV / (2 * atan(0.5));
		correct_angle(&angle);
		fish_eye_correction
			= atan((double)i / (WIDTH - 1) - 0.5) * FOV / (2 * atan(0.5));
		d = wall_distance(graph, angle);
		d = fabs(d * cos(rad(fish_eye_correction)));
		draw_pixel_column(graph, WIDTH - 1 - i, d);
		draw_doors(graph, WIDTH - 1 - i, fish_eye_correction);
	}
	print_minimap(graph);
	mlx_put_image_to_window
		(graph->mlx_ptr, graph->win_ptr, graph->img.img_ptr, 0, 0);
	print_text(graph);
}

void	play(t_graph *graph)
{
	init_color_minimap(graph);
	
	mlx_hook(graph->win_ptr, 33, 1L << 17, close_loop, graph);
	mlx_hook(graph->win_ptr, 2, 1L << 0, keycatch, graph);
	mlx_loop_hook(graph->mlx_ptr, mousemoved, graph);
	print_game(graph);
	mlx_loop(graph->mlx_ptr);
}

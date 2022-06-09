/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:31:45 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 14:49:17 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

static void	print_key_message(t_graph *graph, char *msg)
{
	mlx_string_put(graph->mlx_ptr, graph->win_ptr,
		WIDTH / 2 - 144, HEIGHT - 100, 0xFFFFFF, msg);
	return ;
}

static int	near_special_block(t_graph *graph, t_special_block *temp,
			double marge)
{
	return (graph->game.player_x > (double) temp->x - marge
		&& graph->game.player_x < (double) temp->x + 1.0 + marge
		&& graph->game.player_y > (double) temp->y - marge
		&& graph->game.player_y < (double) temp->y + 1.0 + marge);
}

static void	print_text(t_graph *graph)
{
	t_special_block	*temp;

	if (graph->is_boost > 1.0)
		mlx_string_put(graph->mlx_ptr, graph->win_ptr, 50, 50,
			0xFFFFFF, "boost activated");
	temp = graph->door;
	while (temp != NULL)
	{
		if (near_special_block(graph, temp, TRIGGER_DOOR))
			return (print_key_message(graph,
					"PRESS E TO OPEN / CLOSE THE DOOR !"));
		temp = temp->next;
	}
	temp = graph->game.boost;
	while (temp != NULL)
	{
		if (near_special_block(graph, temp, TRIGGER_BOOST))
			return (print_key_message(graph,
					"PRESS R TO TAKE BOOST !"));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:42:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/30 20:25:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	keycatch(int keycode, t_graph *graph)
{
	if (keycode == KEY_ESC)
		return (close_loop(graph));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (keycatch_angle(keycode, graph));
	else if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S || keycode == KEY_D)
		return (keycatch_step(keycode, graph));
	return (0);
}

int	close_loop(t_graph *graph)
{
	mlx_loop_end(graph->mlx_ptr);
	return (0);
}

int	keycatch_angle(int keycode, t_graph *graph)
{
	if (keycode == KEY_RIGHT)
		graph->game.angle_vision -= DELTA_ANGLE;
	else
		graph->game.angle_vision += DELTA_ANGLE;
	if (graph->game.angle_vision >= 360)
		graph->game.angle_vision -= 360;
	else if (graph->game.angle_vision < 0)
		graph->game.angle_vision += 360;
	print_game(graph);
	return (0);
}
/*
int	in_a_wall(t_graph *graph)
{
	int x;
	int y;

	y = floor(graph->game.player_y);
	x = ceil(graph->game.player_x - 1 - IN_WALL);
	if (graph->game.map[y][x] == '1')
		return (1);
	x = floor(graph->game.player_x + IN_WALL);
	if (graph->game.map[y][x] == '1')
		return (1);
	x = floor(graph->game.player_x);
	y = ceil(graph->game.player_y - IN_WALL - 1);
	if (graph->game.map[y][x] == '1')
		return (1);
	y = floor(graph->game.player_y + IN_WALL);
	if (graph->game.map[y][x] == '1')
		return (1);
	return (0);
}
*/
int	keycatch_step(int keycode, t_graph *graph)
{
	//double	save_x;
	//double	save_y;
	double	S;
	double	d_wall;

	//save_x = graph->game.player_x;
	//save_y = graph->game.player_y;
	if (keycode == KEY_W)
		d_wall = wall_distance(graph, graph->game.angle_vision);
	else if (keycode == KEY_A)
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 90, 360.0));
	else if (keycode == KEY_S)
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 180, 360.0));
	else
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 270, 360.0));
	if (d_wall <= IN_WALL)
		return (0);
	S = dmin(STEP, d_wall - IN_WALL);
	if (keycode == KEY_W)
	{
		graph->game.player_x += S * cos(rad(graph->game.angle_vision));
		graph->game.player_y -= S * sin(rad(graph->game.angle_vision));
	}
	else if (keycode == KEY_A)
	{
		graph->game.player_x -= S * sin(rad(graph->game.angle_vision));
		graph->game.player_y -= S * cos(rad(graph->game.angle_vision));
	}
	else if (keycode == KEY_S)
	{
		graph->game.player_x -= S * cos(rad(graph->game.angle_vision));
		graph->game.player_y += S * sin(rad(graph->game.angle_vision));
	}
	else
	{
		graph->game.player_x += S * sin(rad(graph->game.angle_vision));
		graph->game.player_y += S * cos(rad(graph->game.angle_vision));
	}
	/*if (in_a_wall(graph))
	{
		graph->game.player_x = save_x;
		graph->game.player_y = save_y;
	}
	else*/
	print_game(graph);
	return (0);
}

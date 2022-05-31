/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:42:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/31 17:33:14 by lcalvie          ###   ########.fr       */
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

int	wall_collison_w(t_graph *graph)
{
	double	S;
	double	d_wall;
	int	save_face;

	save_face = graph->face;
	if (save_face == 0 || save_face == 2)
	{
		if (graph->game.angle_vision >= 90 && graph->game.angle_vision <= 270)
			d_wall = wall_distance(graph, 180.0);
		else
			d_wall = wall_distance(graph, 0.0);
	}
	else
	{
		if (graph->game.angle_vision <= 180)
			d_wall = wall_distance(graph, 90.0);
		else
			d_wall = wall_distance(graph, 270.0);
	}
	if (d_wall <= IN_WALL)
		return (0);
	S = dmin(STEP, d_wall - IN_WALL);
	if (save_face == 0 || save_face == 2)
		graph->game.player_x += S * cos(rad(graph->game.angle_vision));
	else
		graph->game.player_y -= S * sin(rad(graph->game.angle_vision));
	print_game(graph);
	return (0);
}

int	keycatch_step(int keycode, t_graph *graph)
{
	double	S;
	double	d_wall;

	if (keycode == KEY_W)
		d_wall = wall_distance(graph, graph->game.angle_vision);
	else if (keycode == KEY_A)
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 90, 360.0));
	else if (keycode == KEY_S)
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 180, 360.0));
	else
		d_wall = wall_distance(graph, fmod(graph->game.angle_vision + 270, 360.0));
	if (d_wall - IN_WALL <= 0.001)
		return (keycode == KEY_W && wall_collison_w(graph));
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
	print_game(graph);
	return (0);
}

int	mousemoved(t_graph *graph)
{
	int	x;
	int	y;

	//printf("on recolte position mouse en %d et struct = %p\n", x, graph);
	mlx_mouse_get_pos(graph->mlx_ptr, graph->win_ptr, &x, &y);
	if (x < MOVED_LEFT)
		graph->game.angle_vision = graph->game.angle_vision - ((double) x / (WIDTH - 1) - MOUSE_MOVED_LEFT) * SPEED_ANGLE;
	else if (x > MOVED_RIGHT)
		graph->game.angle_vision = graph->game.angle_vision - ((double) x / (WIDTH - 1) - MOUSE_MOVED_RIGHT) * SPEED_ANGLE;
	else
		return (0);
	if (graph->game.angle_vision >= 360)
		graph->game.angle_vision -= 360;
	else if (graph->game.angle_vision < 0)
		graph->game.angle_vision += 360;
	print_game(graph);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:42:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/03 15:16:07 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	keycatch(int keycode, t_graph *graph)
{
	if (keycode == KEY_ESC)
		return (close_loop(graph));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (keycatch_angle(keycode, graph));
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
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
	correct_angle(&(graph->game.angle_vision));
	print_game(graph);
	return (0);
}

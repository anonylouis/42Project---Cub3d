/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:47:22 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 19:55:08 by lcalvie          ###   ########.fr       */
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
	else if (keycode == KEY_E)
		return (change_door_status(graph));
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

int	change_door_status(t_graph *graph)
{
	t_special_block *temp;

	temp = graph->door;
	while (temp != NULL)
	{
		temp->percent -= 0.01;
		if (temp->percent <= 0.0)
			temp->percent = 0.01;
		temp = temp->next;
	}
	print_game(graph);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:19:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/30 17:51:55 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void	put_pixel_from_texture(t_graph *graph, int pos_img, double relative_h)
{
	int		x_texture;
	int		y_texture;
	int		pos_texture;
	t_img	wall;

	if (graph->face == 0)
		wall = graph->wall_NO;
	else if (graph->face == 1)
		wall = graph->wall_WE;
	else if (graph->face == 2)
		wall = graph->wall_SO;
	else
		wall = graph->wall_EA;
	x_texture = (graph->percent_face - floor(graph->percent_face))
		* wall.size_line;
	y_texture = relative_h * wall.number_line;
	pos_texture = y_texture * 4 * wall.size_line + 4 * x_texture;
	graph->img.img_addr[pos_img] = wall.img_addr[pos_texture];
	graph->img.img_addr[pos_img + 1] = wall.img_addr[pos_texture + 1];
	graph->img.img_addr[pos_img + 2] = wall.img_addr[pos_texture + 2];
	graph->img.img_addr[pos_img + 3] = '\0';
}

void	draw_pixel_column(t_graph *graph, int column, double d)
{
	double	h;
	int		start;
	int		end;
	int		j;
	int		pos_img;

	h = HEIGHT / (2.0 *(d + H_MAX));
	start = max(0, (int)(HEIGHT / 2 - h / 2));
	end = min(HEIGHT, (int)(HEIGHT / 2 + h / 2));
	j = -1;
	while (++j < start)
		add_pixel_img(graph->img, column, j, graph->game.ceiling);
	while (j < end)
	{
		pos_img = j * graph->img.size_line * 4 + column * 4;
		put_pixel_from_texture(graph, pos_img,
			((double)j - (int)(HEIGHT / 2 - h / 2)) / h);
		j++;
	}
	while (j < HEIGHT)
	{
		add_pixel_img(graph->img, column, j, graph->game.floor);
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:08:53 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 15:36:05 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_img	set_texture(t_graph *graph)
{
	if (graph->hit_boost == 0)
	{
		if (graph->face == 0)
			return (graph->wall_no);
		else if (graph->face == 1)
			return (graph->wall_we);
		else if (graph->face == 2)
			return (graph->wall_so);
		else
			return (graph->wall_ea);
	}
	else
	{
		if (graph->hit_boost == 4)
			return (graph->boost4);
		else if (graph->hit_boost == 1)
			return (graph->boost1);
		else if (graph->hit_boost == 2)
			return (graph->boost2);
		else
			return (graph->boost3);
	}
}

void	put_pixel_from_texture(t_graph *graph, int pos_img, double relative_h)
{
	int		x_texture;
	int		y_texture;
	int		pos_texture;
	t_img	wall;

	wall = set_texture(graph);
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

	h = HEIGHT / (2.0 *(d + (HEIGHT / H_MAX)));
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

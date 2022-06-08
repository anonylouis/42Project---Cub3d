/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:12:55 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/08 16:15:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

int	init_texture(t_graph *graph, t_img *img, char *path)
{
	int	bits_per_pixel;
	int	width;
	int	endian;

	bits_per_pixel = 4 * (sizeof(char) * 8);
	img->img_ptr = mlx_xpm_file_to_image(graph->mlx_ptr, path,
			&(img->size_line), &(img->number_line));
	if (img->img_ptr == NULL)
	{
		printf("Error\nCan't open texture %s\n", path);
		return (1);
	}
	width = img->size_line;
	endian = 0;
	img->img_addr = mlx_get_data_addr(img->img_ptr, &bits_per_pixel,
			&width, &endian);
	if (img->img_addr == NULL)
		return (1);
	return (0);
}

int	init_textures(t_graph *graph)
{
	if (init_texture(graph, &(graph->wall_NO), graph->game.path_wall_NO))
		return (1);
	if (init_texture(graph, &(graph->wall_SO), graph->game.path_wall_SO))
		return (1);
	if (init_texture(graph, &(graph->wall_WE), graph->game.path_wall_WE))
		return (1);
	if (init_texture(graph, &(graph->wall_EA), graph->game.path_wall_EA))
		return (1);
	if (init_texture(graph, &(graph->texture_door), TEXTURE_DOOR_PATH))
		return (1);
	if (init_texture(graph, &(graph->boost1), FRAME1))
		return (1);
	if (init_texture(graph, &(graph->boost2), FRAME2))
		return (1);
	if (init_texture(graph, &(graph->boost3), FRAME3))
		return (1);
	if (init_texture(graph, &(graph->boost4), FRAME4))
		return (1);
	return (0);
}


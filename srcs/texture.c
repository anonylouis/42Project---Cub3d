/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:52:21 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 15:36:05 by lcalvie          ###   ########.fr       */
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
	if (init_texture(graph, &(graph->wall_no), graph->game.path_wall_no))
		return (1);
	if (init_texture(graph, &(graph->wall_so), graph->game.path_wall_so))
		return (1);
	if (init_texture(graph, &(graph->wall_we), graph->game.path_wall_we))
		return (1);
	if (init_texture(graph, &(graph->wall_ea), graph->game.path_wall_ea))
		return (1);
	return (0);
}

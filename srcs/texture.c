/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:52:21 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/28 15:36:42 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

static int	init_texture(t_graph *graph, t_img *img, char *path)
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
	/*printf("x * y  = %i x %i\n",img->number_line, img->size_line);

	for(int i = 0; i < img->number_line; i++)
	{
		for (int j = 0; j < img->size_line; j++)
		{
			printf("char[%i][%i] = %i; %i; %i; %i\n", i, j, (unsigned char) img->img_addr[i * img->size_line*4 + j * 4], (unsigned char) img->img_addr[i * img->size_line*4 + j * 4 + 1], (unsigned char) img->img_addr[i * img->size_line*4 + j * 4 + 2], (unsigned char) img->img_addr[i * img->size_line*4 + j * 4 + 3]);
		}
	}*/
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
	return (0);
}

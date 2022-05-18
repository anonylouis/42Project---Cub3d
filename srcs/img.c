/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:00:27 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/18 15:48:49 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void	init_img_addr(t_graph *graph, t_img *img, int w, int h)
{
	int bits_per_pixel;
	int endian;

	img->size_line = w;
	img->number_line = h;
	img->img_ptr = mlx_new_image(graph->mlx_ptr, img->size_line, h);
	bits_per_pixel = 4 * (sizeof(char) * 8);
	// 4 pour 4 char (3 couleurs + \0 )
	// sizeof(char) pour la taille d un char, * 8 pour bpasser de octer a bit
	endian = 0;
	// endian = sens de lectures des bits ! (gauche a droite = normal = endian = 0), (droite a gauche, endian = 1)
	img->img_addr = mlx_get_data_addr(img->img_ptr, &bits_per_pixel, &(img->size_line), &endian);
	img->size_line = w;
	ft_bzero(img->img_addr, w * h * 4);
}

void	add_pixel_img(t_img img, int x, int y, t_color color)
{
	int pos;

	pos = y * img.size_line * 4 + x * 4;
	img.img_addr[pos] = color.blue;
	img.img_addr[pos + 1] = color.green;
	img.img_addr[pos + 2] = color.red;
	img.img_addr[pos + 3] = '\0';
}

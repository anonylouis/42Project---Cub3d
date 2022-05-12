/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:00:27 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/12 15:32:21 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void    init_img_addr(t_graph *graph, t_img *img, int n)
{
	int	bits_per_pixel;
	int	endian;
        
        img->size_line = n;
        img->img_ptr = mlx_new_image(graph->mlx_ptr, img->size_line, HEIGHT);
	bits_per_pixel = 4 * (sizeof(char) * 8);
	// 4 pour 4 char (3 couleurs + \0 )
	// sizeof(char) pour la taille d un char, * 8 pour bpasser de octer a bit
	endian = 0;
	// endian = sens de lectures des bits ! (gauche a droite = normal = endian = 0), (droite a gauche, endian = 1)
	img->img_addr = mlx_get_data_addr(img->img_ptr, &bits_per_pixel, &(img->size_line), &endian);
}

void    add_pixel_img(t_img img, int x, int y, unsigned int color)
{
        int     red;
        int     green;
        int     blue;
        int     pos;

        red = (color >> 16) % 256;
        green = (color >> 8) % 256;
        blue = color % 256;
        pos = y * img.size_line + x * 4;
        img.img_addr[pos] = blue;
        img.img_addr[pos + 1] = green;
        img.img_addr[pos + 2] = red;
        img.img_addr[pos + 3] = '\0';
}

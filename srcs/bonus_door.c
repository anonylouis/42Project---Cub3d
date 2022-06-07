/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:24 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 20:02:42 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_texture_door(t_graph *graph)
{
	int bits_per_pixel;
	int width;
	int endian;
	t_img *img;

	img = &(graph->texture_door);
	bits_per_pixel = 4 * (sizeof(char) * 8);
	img->img_ptr = mlx_xpm_file_to_image(graph->mlx_ptr, TEXTURE_DOOR_PATH, &(img->size_line), &(img->number_line));
	if (img->img_ptr == NULL)
	{
		printf("Error\nCan't open texture %s\n", TEXTURE_DOOR_PATH);
		return (1);
	}
	width = img->size_line;
	endian = 0;
	img->img_addr = mlx_get_data_addr(img->img_ptr, &bits_per_pixel, &width, &endian);
	if (img->img_addr == NULL)
		return (1);
	return (0);
}

static void	put_pixel_from_texture_door(t_graph *graph, int pos_img, double relative_h, double relative_x)
{
	int		x_texture;
	int		y_texture;
	int		pos_texture;
	t_img	texture_door;

	if (relative_h < 0.0 || relative_h > 1.0)
		return ;
	texture_door = graph->texture_door;
	x_texture = relative_x * texture_door.size_line;
	y_texture = relative_h * texture_door.number_line;
	pos_texture = y_texture * 4 * texture_door.size_line + 4 * x_texture;
	if (texture_door.img_addr[pos_texture] == 0 && texture_door.img_addr[pos_texture + 1] == 0 && texture_door.img_addr[pos_texture + 2] == -1)
		return ;
	graph->img.img_addr[pos_img] = texture_door.img_addr[pos_texture];
	//printf("%d %d %d\n", texture_door.img_addr[pos_texture], texture_door.img_addr[pos_texture + 1], texture_door.img_addr[pos_texture + 2]);
	graph->img.img_addr[pos_img + 1] = texture_door.img_addr[pos_texture + 1];
	graph->img.img_addr[pos_img + 2] = texture_door.img_addr[pos_texture + 2];
	graph->img.img_addr[pos_img + 3] = '\0';
}

static double relative_x_door(t_special_block *lst_max)
{
	double relative_x;

	if (lst_max->face == 0)
		relative_x = lst_max->intersection_x;
	else if (lst_max->face == 1)
		relative_x = 1.0 - lst_max->intersection_y;
	else if (lst_max->face == 2)
		relative_x = 1.0 - lst_max->intersection_x;
	else
		relative_x = lst_max->intersection_y;
	return (relative_x - floor(relative_x));
}

void	draw_doors(t_graph *graph, int column, double fish_eye_correction)
{
	double d;
	double h;
	t_special_block *temp;
	int		start;
	int		end;
	int		j;
	int		pos_img;
	double	relative_x;
	int		percent_end;

	if (graph->hit_door == NULL)
		return ;
	temp = graph->hit_door;
	sort_special_block(temp);
	while (temp)
	{
		if (temp->percent == 0.0)
			return ;
		d = temp->distance;
		d = fabs(d * cos(rad(fish_eye_correction)));
		h = (HEIGHT / (2.0 *(d + H_MAX)));
		start = max(0, (int)(HEIGHT / 2 - h / 2));
		end = min(HEIGHT, (int)(HEIGHT / 2 + h / 2));
		j = end;
		percent_end = start + (end - start) * (1.0 - temp->percent);
		while (--j >= percent_end)
		{
			relative_x = relative_x_door(temp);
			//printf("relative_x = %f\n", relative_x);
			pos_img = j * graph->img.size_line * 4 + column * 4;
			put_pixel_from_texture_door(graph, pos_img,
				2.0 - temp->percent - ((double)j - (int)(HEIGHT / 2 - h / 2)) / h, relative_x);
		}
		temp = temp->next;
	}
}

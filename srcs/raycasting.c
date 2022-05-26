/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:19:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/26 14:04:25 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

// return 1 = bordure en x = constante
// return 2 = bordure en y = constante
int find_next_border(double *x, double *y, double angle)
{
	double temp;
	double x_border;
	double y_border;

	if (angle == 90 || angle == 270)
	{
		if (angle == 90)
			*y = ceil(*y - 1);
		else
			*y = floor(*y + 1);
		return (2);
	}
	else if (angle <= 90)
	{
		//printf("<90 x=%f et y=%f\n", *x, *y);
		y_border = ceil(*y - 1);
		x_border = floor(*x + 1);
		//printf("border x=%f et y=%f\n", x_border, y_border);
	}
	else if (angle <= 180)
	{
		y_border = ceil(*y - 1);
		x_border = ceil(*x - 1);
	}
	else if (angle <= 270)
	{
		y_border = floor(*y + 1);
		x_border = ceil(*x - 1);
	}
	else
	{
		y_border = floor(*y + 1);
		x_border = floor(*x + 1);
	}
	temp = tan((-1) * rad(angle)) * (x_border - *x) + *y;
	//printf(" temp = %f\n", temp);
	if (angle <= 180)
	{
		if (temp >= y_border)
		{
			*x = x_border;
			*y = temp;
			return (1);
		}
		else
		{
			*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
			*y = y_border;
			return (2);
		}
	}
	else
	{
		if (temp <= y_border)
		{
			*x = x_border;
			*y = temp;
			return (1);
		}
		else
		{
			*x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
			*y = y_border;
			return (2);
		}
	}
}

int is_a_wall(t_graph *graph, double x, double y, double angle)
{
	int i;
	int j;

	if (angle >= 0 && angle <= 90)
	{
		i = ceil(y - 1);
		j = floor(x);
	}
	else if (angle > 90 && angle <= 180)
	{
		// printf("iciiii %f %f \n", x, y);
		i = ceil(y - 1);
		j = ceil(x - 1);
		// printf("laaaaaaaaaaaaa %i %i \n", i, j);
	}
	else if (angle > 180 && angle <= 270)
	{
		i = floor(y);
		j = ceil(x - 1);
	}
	else
	{
		i = floor(y);
		j = floor(x);
	}
	//printf("check case i = %d , j = %d\n", i, j);
	return (graph->game.map[i][j] == '1');
}

//graph->face == 0 <=> NORTH
//graph->face == 1 <=> WEST
//graph->face == 2 <=> SOUTH
//graph->face == 3 <=> EAST
double wall_distance(t_graph *graph, double angle, double *x_wall)
{
	double x;
	double y;
	double d;
	int next;
	int r;

	next = 1;
	x = graph->game.player_x;
	y = graph->game.player_y;
	while (next || !is_a_wall(graph, x, y, angle))
	{
		r = find_next_border(&x, &y, angle);
		//printf("bordure en x = %f , y = %f\n", x, y);
		if (next)
			next = 0;
	}
	d = sqrt((graph->game.player_x - x) * (graph->game.player_x - x) + (graph->game.player_y - y) * (graph->game.player_y - y));
	if (r == 1 && angle >= 90 && angle <= 270)
	{
		*x_wall = 1 - y;
		graph->face = 1;
	}
	else if (r == 1)
	{
		*x_wall = y;
		graph->face = 3;
	}
	else if (r == 2 && angle >= 0 && angle <= 180)
	{
		*x_wall = x;
		graph->face = 0;
	}
	else
	{
		*x_wall = 1 - x;
		graph->face = 2;
	}
	return d;
}

void	put_pixel_from_texture(t_graph *graph, int pos_img, double relative_h, double x_wall)
{
	int	x_texture;
	int	y_texture;
	int	pos_texture;
	t_img	wall;

	//printf("relative h = %f\n", relative_h);
	//printf("angle drawing = %f\n", graph->angle_drawing);
	if (graph->face == 0)
		wall = graph->wall_NO;
	else if (graph->face == 1)
		wall = graph->wall_WE;
	else if (graph->face == 2)
		wall = graph->wall_SO;
	else
		wall = graph->wall_EA;
	x_texture = (x_wall - floor(x_wall)) * wall.size_line;
	y_texture = relative_h * wall.number_line;
	pos_texture = y_texture * 4 * wall.size_line + 4 * x_texture;
	//printf("pixel texture : %i %i \n", x_texture, y_texture);
	graph->img.img_addr[pos_img] = wall.img_addr[pos_texture];
	graph->img.img_addr[pos_img + 1] = wall.img_addr[pos_texture + 1];
	graph->img.img_addr[pos_img + 2] = wall.img_addr[pos_texture + 2];
	graph->img.img_addr[pos_img + 3] = '\0';
	//printf("fin section\n");
}


void draw_pixel_column(t_graph *graph, int column, double d, double x_wall)
{
	double h;
	int start;
	int end;
	int j;
	int pos_img;
	
	h = HEIGHT / ( 2.0 *(d + H_MAX));
	//printf(" hauteur = %f\n", h);
	start = max(0, (int)(HEIGHT / 2 - h / 2));
	end = min(HEIGHT, (int)(HEIGHT / 2 + h / 2));
	j = 0;
	//printf("debut = %i, fin = %i \n,", start, end);
	//printf("vrai debut = %f , vraie fin = %f\n", (HEIGHT / 2 - h / 2), (HEIGHT / 2 + h / 2));
	while (j < start)
	{
		add_pixel_img(graph->img, column, j, graph->game.ceiling);
		j++;
	}
	while (j < end)
	{
		pos_img = j * graph->img.size_line * 4 + column * 4;
		//printf("on ecrit au pixel : %i %i \n", j, column);
		put_pixel_from_texture(graph, pos_img, ((double)j - (int)(HEIGHT / 2 - h / 2)) / h, x_wall);
		j++;
	}
	while (j < HEIGHT)
	{
		add_pixel_img(graph->img, column, j, graph->game.floor);
		j++;
	}
}

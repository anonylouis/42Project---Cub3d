/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:19:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/18 03:11:43 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include <stdio.h>

void    find_next_border(double *x, double *y, double angle)
{
        double  temp;
        double  x_border;
        double  y_border;

        if (angle == 90 || angle == 270)
        {
                if (angle == 90)
                        *y = ceil(*y - 1);
                else
                        *y = floor(*y + 1);
                return ;
        }
        else if (angle <= 90)
        {
                printf("<90 x=%f et y=%f\n", *x, *y);
                y_border = ceil(*y - 1);
                x_border = floor(*x + 1);
                printf("border x=%f et y=%f\n", x_border, y_border);
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
        temp = tan((-1) *rad(angle)) * (x_border - *x) + *y;
        printf(" temp = %f\n", temp);
        if (angle <= 180)
        {
                if (temp >= y_border)
                {
                        *x = x_border;
                        *y = temp;
                }
                else
                {
                        *x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
                        *y = y_border;
                }
        }
        else
        {
                if (temp <= y_border)
                {
                        *x = x_border;
                        *y = temp;
                }
                else
                {
                        *x = (y_border - *y) / (tan((-1) * rad(angle))) + *x;
                        *y = y_border;
                }
        }
}

int     is_a_wall(t_graph *graph, double x, double y, double angle)
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
                //printf("iciiii %f %f \n", x, y);
                i = ceil(y - 1);
                j = ceil(x - 1);
                //printf("laaaaaaaaaaaaa %i %i \n", i, j);
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
        printf("check case i = %d , j = %d\n", i, j);
        return (graph->game.map[i][j] == '1');
}

double  wall_distance(t_graph *graph, double angle, double *x_wall)
{
        double  x;
        double  y;
        double  d;
        int     next;

        next = 1;
        x =  graph->game.player_x;
        y = graph->game.player_y;
        while (next || !is_a_wall(graph, x, y, angle))
        {
                find_next_border(&x, &y, angle);
                printf("bordure en x = %f , y = %f\n", x, y);
                if (next)
                        next = 0;
        }
        d = sqrt((graph->game.player_x - x)*(graph->game.player_x - x)
                        + (graph->game.player_y - y) * (graph->game.player_y - y));
		if ((angle >= 45 && angle <= 135))
        	*x_wall = x;
		else if (angle >= 135 && angle <= 225)
			*x_wall = 1 - y;
		else if (angle > 225 && angle <= 315)
			*x_wall = 1 - x;
		else
			*x_wall = y;
        return d;
}


void    draw_pixel_column(t_graph *graph, int column, double d, double x_wall)
{
        double  h;
        int     start;
        int     end;
        int     j;
        int     pos_img;
        int     pos_texture;
        int     y_texture;
        int     x_texture;

        x_texture = (x_wall - floor(x_wall)) *  graph->wall_NO.size_line;
        h = HEIGHT / d;
		printf(" hauteur = %f\n",h);
        start = max(0, (int) (HEIGHT / 2 - h / 2));
        end = min(HEIGHT, (int) (HEIGHT / 2 + h / 2));
        j = start;
        printf("debut = %i, fin = %i \n,", start, end);
        printf("vrai debut = %f , vraie fin = %f\n", (HEIGHT / 2 - h / 2), (HEIGHT / 2 + h / 2));
        while (j <= end)
        {
                pos_img = j * graph->img.size_line * 4 + column * 4;
                
                y_texture = (j - (HEIGHT / 2 - h / 2)) / h * graph->wall_NO.number_line;
                pos_texture = y_texture * 4 * graph->wall_NO.size_line + 4 * x_texture;

                printf("pixel texture : %i %i \n", x_texture, y_texture);
                printf("on ecrit au pixel : %i %i \n", j, column);
                graph->img.img_addr[pos_img] = graph->wall_NO.img_addr[pos_texture];
                graph->img.img_addr[pos_img + 1] = graph->wall_NO.img_addr[pos_texture + 1];
                graph->img.img_addr[pos_img + 2] = graph->wall_NO.img_addr[pos_texture + 2];
                graph->img.img_addr[pos_img + 3] = '\0';
                j++;
        }
}
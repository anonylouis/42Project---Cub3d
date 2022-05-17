/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:19:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/17 13:11:51 by lcalvie          ###   ########.fr       */
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
                //printf("<90 %f et %f\n", *x, *y);
                y_border = ceil(*y - 1);
                x_border = floor(*x + 1);
                //printf("border %f et %f\n", x_border, y_border);
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
        //printf(" temp = %f\n", temp);
        if (angle <= 180)
        {
                if (temp >= y_border)
                {
                        *x = x_border;
                        *y = temp;
                }
                else
                {
                        *x = (y_border - *y) / (tan(rad(angle))) + *x;
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
                        *x = (y_border - *y) / (tan(rad(angle))) + *x;
                        *y = y_border;
                }
        }
}

int     is_a_wall(t_graph *graph, double x, double y, double angle)
{
        int i;
        int j;
        
        if (angle > 45 && angle <= 135)
        {
                i = floor(y - 1);
                j = ceil(x - 1);
        }
        else if (angle > 135 && angle <= 225)
        {
                i = floor(y + 1);
                j = ceil(x - 1);
        }
        else if (angle > 225 && angle <= 315)
        {
                i = floor(y);
                j = floor(x);
        }
        else
        {
                i = ceil(y - 1);
                j = floor(x);
        }
        //printf("check case i = %d , j = %d\n", i, j);
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
                //printf("bordure en x = %f , y = %f\n", x, y);
                if (next)
                        next = 0;
        }
        d = sqrt((graph->game.player_x - x)*(graph->game.player_x - x)
                        + (graph->game.player_y - y) * (graph->game.player_y - y));
        *x_wall = x;
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
        int     x_texture;
        int     y_texture;

        x_wall = x_wall - floor(x_wall);
        h = HEIGHT / d;
        start = max(0, (int) (HEIGHT / 2 - h / 2));
        end = min(HEIGHT, (int) (HEIGHT / 2 + h / 2));
        j = start;
        //printf("debut = %i, fin = %i \n,", start, end);
        x_texture =  x_wall 
        while (j <= end)
        {
                pos_img = j * img.size_line * 4 + column * 4;
                
                y_texture = 
                pos_texture =                 

                graph->img.img_addr[pos_img] = ;
                graph->img.img_addr[pos_img + 1] = ;
                graph->img.img_addr[pos_img + 2] = ;
                graph->img.img_addr[pos_img + 3] = '\0';
                j++;
        }
}
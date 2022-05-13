/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:19:20 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/13 16:39:21 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
# include <stdio.h>

void    find_next_border(double *x, double *y, double angle)
{
        double  temp;
        double  x_border;
        double  y_border;

        if (angle == 90 || angle == 180)
        {
                if (angle == 90)
                        *y = ceil(*y - 1);
                else
                        *y = floor(*y + 1);
                return ;
        }
        else if (angle < 90)
        {
                y_border = ceil(*y - 1);
                x_border = floor(*x + 1);
        }
        else if (angle < 180)
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
        temp = tan(rad(angle)) * (x_border - *x) + *y;
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

        if (angle <= 90)
        {
                i = floor(y - 1);
                j = floor(x);
        }
        else if (angle <= 180)
        {
                i = floor(y - 1);
                j = floor(x - 1);
        }
        else if (angle <= 270)
        {
                i = floor(y);
                j = floor(x - 1);
        }
        else
        {
                i = floor(y);
                j = floor(x);
        }
        printf("check case i = %d , j = %d\n", i, j);
        return (graph->game.map[i][j] == '1');
}

double  wall_distance(t_graph *graph, double angle)
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
        return d;
}


void    draw_pixel_column(t_img img, int column, double d)
{
        double  h;
        int     start;
        int     end;
        int     j;

        h = HEIGHT / d;
        start = max(0, (int) (HEIGHT / 2 - h / 2));
        end = min(HEIGHT, (int) (HEIGHT / 2 + h / 2));
        j = start;
        while (j <= end)
        {
                add_pixel_img(img, column, j, 0xFF0000);
                j++;
        }
}
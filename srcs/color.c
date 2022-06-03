/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:39:52 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/03 11:58:05 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_color(int color)
{
    return (color >= 0 && color <= 255);
}

int is_empty_color(t_color color)
{
    if (color.red == -1 && color.green == -1 && color.blue == -1)
        return (1);
    return (0);
}

int check_color(char **colors)
{
    if (count(colors) == 3 && is_int(colors[0]) 
    && is_color(ft_atoi(colors[0])) && is_int(colors[1]) 
    && is_color(ft_atoi(colors[1])) && is_int(colors[2]) 
    && is_color(ft_atoi(colors[2])))
        return (1);
    ft_free_all(colors);
    return (0);
}

int is_floor(char **tokens, t_game *game)
{
    char **colors;

    if (ft_compare(tokens[0], "F") == 0)
    {
        if (!is_empty_color(game->floor))
        {
            printf("Error: Duplicate line: %s \n", tokens[0]);
            return (0);
        }
        colors = ft_split(tokens[1], ',');
        if (check_color(colors))
        {
            game->floor.red = ft_atoi(colors[0]);
            game->floor.green = ft_atoi(colors[1]);
            game->floor.blue = ft_atoi(colors[2]);
            ft_free_all(colors);
            return (1);
        }
        else
            return (0);
        ft_free_all(colors);
    }
    return (0);
}

int is_ceiling(char **tokens, t_game *game)
{
    char **colors;

    if (ft_compare(tokens[0], "C") == 0)
    {
        if (!is_empty_color(game->ceiling))
        {
            printf("Error: Duplicate line: %s \n", tokens[0]);
            return (0);
        }
        colors = ft_split(tokens[1], ',');
        if (check_color(colors))
        {
            game->ceiling.red = ft_atoi(colors[0]);
            game->ceiling.green = ft_atoi(colors[1]);
            game->ceiling.blue = ft_atoi(colors[2]);
            ft_free_all(colors);
            return 1;
        }
        else
            return (0);
    }
    return (0);
}
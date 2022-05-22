/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:54:05 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/22 23:11:46 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

int get_map_idx(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        if (map[i][0] == '1')
            return i;
        i++;
    }
    return (-1);
}

int is_valid_map_char(char c)
{
    return c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ';
}

int check_walls(char **s, int start)
{
    int i;
    int j;
    int len;

    i = start;
    j = 0;
    while (s[i] != NULL)
    {
        j = 0;
        while (s[i][j] != '\0')
        {
            if (i == start || i == count(s) - 1)
            {
                if (s[i][j] != '1' && s[i][j] != ' ')
                    return (0);
            }
            j++;
        }
        len = ft_strlen(s[i]);
        if (s[i][0] != '1' || s[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_valid_chars(char **s, int start)
{
    int i;
    int j;

    i = start;
    j = 0;
    while (s[i] != NULL)
    {
        j = 0;
        while (s[i][j] != '\0')
        {
            if (!is_valid_map_char(s[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

t_check_result success()
{
    t_check_result result;
    result.success = 1;
    return result;
}

t_check_result error(char *message)
{
    t_check_result result;
    result.success = 0;
    result.message = message;
    return result;
}

int is_orientation(char c)
{
    return c == 'W' || c == 'N' || c == 'E' || c == 'S';
}

int has_orientation(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
    {
        if (is_orientation(s[i]))
            return (i);
        i++;
    }
    return (-1);
}

t_check_result check_orientation(char **s, int start)
{
    int i;
    int j;
    int orientation;

    i = start;
    j = 0;
    orientation = 0;
    while (s[i] != NULL)
    {
        j = 0;
        while (s[i][j] != '\0')
        {
            if (is_orientation(s[i][j]))
                orientation++;
            j++;
        }
        i++;
    }
    if (orientation == 0)
        return error("Error : map must have one orientation");
    if (orientation > 1)
        return error("Error : map must have only one orientation");
    return success();
}

int is_valid_map(char **s, int start)
{
    t_check_result result;

    if (!check_walls(s, start))
        return print_error("Error: map must be surrounded by walls", 0);
    if (!check_valid_chars(s, start))
        return print_error("Error: invalid map char", 0);
    result = check_orientation(s, start);
    if (!result.success)
        return print_error(result.message, 0);
    return (1);
}

void set_angle_vision(t_game *game)
{
    if (game->orientation == 'E') // si le perso est un N au depart
        game->angle_vision = 0;
    else if (game->orientation == 'N')
        game->angle_vision = 90;
    else if (game->orientation == 'W')
        game->angle_vision = 180;
    else if (game->orientation == 'S')
        game->angle_vision = 270;
}

char **extract_map(char **s, int line_idx, t_game *game)
{
    char **map;
    int i;
    int orientation;

    i = 0;
    orientation = 0;
    if (!is_valid_map(s, line_idx))
        return NULL;
    map = malloc(sizeof(char *) * (count(s) - line_idx));
    if (map == NULL)
        return NULL;
    while (s[line_idx] != NULL)
    {
        orientation = has_orientation(s[line_idx]);
        if (orientation != -1)
        {
            game->orientation = s[line_idx][orientation];
            set_angle_vision(game);
        }
        map[i++] = s[line_idx++];
    }
    map[i] = NULL;
    return (map);
}

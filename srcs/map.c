/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:54:05 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/17 21:36:24 by mrahmani         ###   ########.fr       */
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
        {
            return i;
        }
        i++;
    }
    return (-1);
}

int is_valid_map_char(char c)
{
    return c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ';
}

int is_valid_map(char **s, int start)
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
            else
            {
                len = ft_strlen(s[i]);
                if (s[i][0] != '1' && s[i][len - 1] != '1')
                    return (0);
                if (!is_valid_map_char(s[i][j]))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

char **extract_map(char **s, int line_idx)
{
    char **map;
    int i;

    i = 0;
    if (!is_valid_map(s, line_idx))
    {
        print_error("invalid map", 0);
        return NULL;
    }
    map = malloc(sizeof(char *) * (count(s) - line_idx));
    if (map == NULL)
        return NULL;
    while (s[line_idx] != NULL)
    {
        map[i++] = s[line_idx++];
    }
    map[i] = NULL;
    return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:54:05 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 12:51:58 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

int is_beg_map(char *s)
{
    int i;
    
    i = 0;
    if (s == NULL)
        return (0);
    if (is_empty_line(s))
        return (0);
    while (s[i] != '\0')
    {
        if (s[i] != '1' && s[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int get_map_idx(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        if (is_beg_map(map[i]))
            return (i);
        i++;
    }
    return (-1);
}

int is_valid_map_char(char c)
{
    return c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ';
}


int exit_check_map_info(int ret, char **tokens)
{
    ft_free_all(tokens);
    return ret;
}

int check_map_info(char *line, t_game *game)
{
    char **tokens;

    tokens = ft_split(line, ' ');
    if (count(tokens) < 2)
    {
        printf("Error : Invalid line %s\n", line);
        return (exit_check_map_info(0, tokens));
    }
    if (is_ea_texture(tokens, game))
        return exit_check_map_info(1, tokens);
    else if (is_so_texture(tokens, game))
        return exit_check_map_info(1, tokens);
    else if (is_we_texture(tokens, game))
        return exit_check_map_info(1, tokens);
    else if (is_no_texture(tokens, game))
        return (exit_check_map_info(1, tokens));
    else if (is_floor(tokens, game))
        return (exit_check_map_info(1, tokens));
    else if (is_ceiling(tokens, game))
        return (exit_check_map_info(1, tokens));
    else 
        printf("Error : Invalid line %s\n", line);
    return (exit_check_map_info(0, tokens));
}

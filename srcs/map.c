/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:54:05 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/04 23:06:36 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <string.h>

int is_beg_map(char *s)
{
    int i;
    if (s == NULL)
        return (0);
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != '1' && s[i] != ' ')
            return (0);
        i++;
    }
    if (is_empty_line(s))
        return (0);
    return (1);
}

int get_map_idx(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        if (is_beg_map(map[i]))
            return i;
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
    t_check_result result;
    if(s == NULL || start == -1)
        return (print_error("missing map description", 0));
    if (!check_empty_lines(s, start))
        return (print_error("map cannot contain empty lines", 0));
    if (!check_valid_chars(s, start))
        return print_error("invalid map char", 0);
    if (!check_walls(s, start))
        return print_error("map must be surrounded by walls", 0);
    result = check_orientation(s, start);
    if (!result.success)
        return print_error(result.message, 0);
    return (1);
}

char **extract_map(char **s, int line_idx, t_game *game)
{
    char **map;
    int i;
    int orientation;

    i = 0;
    orientation = 0;
    if (!is_valid_map(s, line_idx))
        return (NULL);
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
            game->player_x = orientation + 0.5;
            game->player_y = i + 0.5;
            printf("%f %f\n", game->player_x, game->player_y);
        }
        map[i++] = s[line_idx++];
    }
    map[i] = (NULL);
    return (map);
}

int check_map_info(char *line, t_game *game)
{
    char **tokens;

    tokens = ft_split(line, ' ');
    if (count(tokens) < 2)
    {
        printf("Error : Invalid line %s\n", line);
        return (0);
    }
    if (is_ea_texture(tokens, game))
        return (1);
    else if (is_so_texture(tokens, game))
        return (1);
    else if (is_we_texture(tokens, game))
        return (1);
    else if (is_no_texture(tokens, game))
        return (1);
    else if (is_floor(tokens, game))
        return (1);
    else if (is_ceiling(tokens, game))
        return (1);
    ft_free_all(tokens);
    printf("Error : Invalid line %s\n", line);
    return (0);
}

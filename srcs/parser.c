/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:30:04 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/18 17:56:50 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color empty_color()
{
    t_color t;

    t.b = -1;
    t.g = -1;
    t.r = -1;

    return t;
}

int is_empty_color(t_color color)
{
    if (color.r == -1 && color.g == -1 && color.b == -1)
        return 1;
    return (0);
}

t_game *parse(char *file)
{
    char **map;
    int line_number = 0;
    t_game *game = NULL;

    map = get_map(file);
    game = new_game();
    while (map[line_number] != NULL)
    {
        if (line_number < get_map_idx(map))
        {
            if (!check_textures(map[line_number], game))
                return NULL; // free
        }
        else
            game->map = extract_map(map, get_map_idx(map));
        line_number++;
    }
    return (game);
}

int check_textures(char *line, t_game *game)
{
    char **tokens;
    
    tokens = ft_split(line, ' ');
    if (count(tokens) < 2)
        return 0;
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
    return (0);
}



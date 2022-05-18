/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:30:04 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/18 16:46:52 by mrahmani         ###   ########.fr       */
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
    int map_idx = 0;
    t_game *game = NULL;
    char **tokens;

    map = get_map(file);
    game = new_game();
    map_idx = get_map_idx(map);
    while (map[line_number] != NULL)
    {
        if (line_number < map_idx)
        {
            tokens = ft_split(map[line_number], ' ');
            if (count(tokens) < 2 || !check_textures(tokens, game))
                return NULL; // free
        }
        else 
        {
            game->map = extract_map(map, map_idx);
        }
        line_number++;
    }
    return (game);
}

int check_textures(char **tokens, t_game *game)
{
    if (is_ea_texture(tokens))
    {
        if (game->texture_ea != NULL)
            return print_error("Duplicate line", 0);
        game->texture_ea = tokens[1];
    }
    else if (is_so_texture(tokens))
    {
        if (game->texture_so != NULL)
            return print_error("Duplicate line", 0);
        game->texture_so = tokens[1];
    }
    else if (is_we_texture(tokens))
    {
        if (game->texture_we != NULL)
            return print_error("Duplicate line", 0);
        game->texture_we = tokens[1];
        
    }
    else if (is_no_texture(tokens))
    {
        if (game->texture_no != NULL)
            return print_error("Duplicate line", 0);
        game->texture_no = tokens[1];
        
    }
    else if (ft_compare(tokens[0], "C"))
    {
        if (!is_empty_color(game->floor))
            return print_error("Duplicate line", 0);
        game->floor = is_floor(tokens);
        
    }
    else if (ft_compare(tokens[0], "F"))
    {
        if (!is_empty_color(game->celeing))
            return print_error("Duplicate line", 0);
        game->celeing = is_ceiling(tokens);
    
    }
    return (1);
}

int check_floor_color(char **tokens, t_game *game)
{
    if (!is_empty_color(game->floor))
        return print_error("Duplicate line", 0);
    game->floor = is_floor(tokens);
    return (1);
}

int check_ceiling_color(char **tokens, t_game *game)
{
    if (!is_empty_color(game->celeing))
        return print_error("Duplicate line", 0);
    game->celeing = is_ceiling(tokens);
    return (1);
}

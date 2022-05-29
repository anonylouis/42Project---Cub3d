/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:30:04 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/29 23:24:55 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color empty_color()
{
    t_color t;

    t.blue = -1;
    t.green = -1;
    t.red = -1;
    return (t);
}

int is_empty_color(t_color color)
{
    if (color.red == -1 && color.green == -1 && color.blue == -1)
        return (1);
    return (0);
}

t_game *exit_with_error(t_game *game)
{
    free_game(game);
    return (NULL);
}

t_game *parse(char *file)
{
    int line_number = 0;
    t_game *game;

    game = new_game();
    game->raw_map = get_map(file);
    if (game->raw_map == NULL)
        return exit_with_error(game);
    while (game->raw_map[line_number] != NULL)
    {
        if (line_number < get_map_idx(game->raw_map))
        {
            if (is_empty_line(game->raw_map[line_number]))
            {
                line_number++;
                continue;
            }
            if (!check_map_info(game->raw_map[line_number], game))
                return exit_with_error(game);
        }
        else
        {
            game->map = extract_map(game->raw_map, get_map_idx(game->raw_map), game);
            if (game->map == NULL)
                return exit_with_error(game);
            break;
        }
        line_number++;
    }
    return (game);
}

int check_map_info(char *line, t_game *game)
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
    ft_free_all(tokens);
    printf("Error : Invalid line %s", line);
    return (0);
}

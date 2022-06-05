/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:30:04 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/05 23:39:25 by mrahmani         ###   ########.fr       */
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

int get_map_info(t_game *game, int idx_map)
{
    int line_number;
    line_number = 0;
    while (game->raw_map[line_number] != NULL)
    {
        if (line_number < idx_map)
        {
            if (is_empty_line(game->raw_map[line_number]))
            {
                line_number++;
                continue;
            }
            if (!check_map_info(game->raw_map[line_number], game))
                return (0);
        }
        else
            break;
        line_number++;
    }
    return (1);
}

t_game *parse(char *file)
{
    t_game *game;
    int idx_map;

    game = new_game();
    game->raw_map = get_map(file);
    if (game->raw_map == NULL)
        return exit_with_error(game);
    idx_map = get_map_idx(game->raw_map);
    if (!get_map_info(game, idx_map))
        return (exit_with_error(game));
    game->map = extract_map(game->raw_map, idx_map, game);
    if (game->map == NULL)
        return (exit_with_error(game));
    return (game);
}

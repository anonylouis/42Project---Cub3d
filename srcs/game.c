/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:22:43 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/01 16:54:54 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game *new_game()
{
    t_game *game;
    game = malloc(sizeof(t_game));
    if (!game)
        return NULL;
    game->map = NULL;
    game->orientation = 0;
    game->path_wall_EA = NULL;
    game->path_wall_NO = NULL;
    game->path_wall_WE = NULL;
    game->path_wall_SO = NULL;
    game->floor = empty_color();
    game->ceiling = empty_color();
    game->raw_map = NULL;
    game->nb_line_map = -1;
    return game;
}

void free_game(t_game *game)
{
    if (game != NULL)
    {
        ft_free_all(game->map);
        ft_free_all(game->raw_map);
        free(game);
    }
}

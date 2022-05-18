/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:22:43 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/17 01:40:04 by mrahmani         ###   ########.fr       */
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
    game->nb_lines = 0;
    game->texture_ea = NULL;
    game->texture_no = NULL;
    game->texture_so = NULL;
    game->texture_we = NULL;
    game->floor = empty_color();
    game->celeing = empty_color();
    return game;
}

void free_game(t_game *game)
{
    if (game)
    {
        free(game);
    }
}
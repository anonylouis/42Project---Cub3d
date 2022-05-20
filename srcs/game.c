/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:22:43 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/19 21:53:42 by mrahmani         ###   ########.fr       */
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
    game->success = 0;
    game->nb_lines = 0;
    game->texture_ea = NULL;
    game->texture_no = NULL;
    game->texture_so = NULL;
    game->texture_we = NULL;
    game->floor = empty_color();
    game->celeing = empty_color();
    game->raw_map = NULL;
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
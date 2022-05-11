/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:22:43 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/11 15:26:25 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_game  *new_game(char **map)
{
        t_game  *game;

        game = malloc(sizeof(t_game));
        if (game)
                return(NULL);
        game->map = map;
        return (game);
}

void    free_game(t_game *game)
{
        if (game)
        {
                free(game);
        }
}
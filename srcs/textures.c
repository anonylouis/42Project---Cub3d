/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:02:31 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/19 21:46:04 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_no_texture(char **tokens, t_game *game)
{
    if (ft_compare(tokens[0], "NO") == 0 || ft_compare(tokens[0], "N") == 0)
    {
        if (game->texture_no != NULL)
        {
            printf("Duplicate line: %s: %s", tokens[0], tokens[1]);
            game->success = -1;
            return (0);
        }
        game->texture_no = tokens[1];
        return (1);
    }
    return (0);
}

int is_we_texture(char **tokens, t_game *game)
{
    if (ft_compare(tokens[0], "WE") == 0 || ft_compare(tokens[0], "W") == 0)
    {
        if (game->texture_we != NULL)
        {
            printf("Duplicate line: %s: %s", tokens[0], tokens[1]);
            game->success = -1;
            return (0);
        }
        game->texture_we = tokens[1];
        return (1);
    }
    return (0);
}

int is_ea_texture(char **tokens, t_game *game)
{
    if (ft_compare(tokens[0], "EA") == 0 || ft_compare(tokens[0], "E") == 0)
    {
        if (game->texture_ea != NULL)
        {
            printf("Duplicate line: %s: %s", tokens[0], tokens[1]);
            game->success = -1;
            return (0);
        }
        game->texture_ea = tokens[1];
        return (1);
    }
    return (0);
}

int is_so_texture(char **tokens, t_game *game)
{
    if (ft_compare(tokens[0], "SO") == 0 || ft_compare(tokens[0], "S") == 0)
    {
        if (game->texture_so != NULL)
        {
            printf("Duplicate line: %s: %s", tokens[0], tokens[1]);
            return (0);
        }
        game->texture_so = tokens[1];
        return (1);
    }
    return (0);
}
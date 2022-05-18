/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:02:31 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/16 22:33:26 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
int is_no_texture(char **tokens)
{
    if (ft_compare(tokens[0], "NO") == 0 || ft_compare(tokens[0], "N") == 0)
        return (1);
    return (0);
}

int is_we_texture(char **tokens)
{
    if (ft_compare(tokens[0], "WE") == 0 || ft_compare(tokens[0], "W") == 0)
        return (1);
    return (0);
}

int is_ea_texture(char **tokens)
{
    if (ft_compare(tokens[0], "EA") == 0 || ft_compare(tokens[0], "E") == 0)
        return (1);
    return (0);
}

int is_so_texture(char **tokens)
{
    if (ft_compare(tokens[0], "SO") == 0 || ft_compare(tokens[0], "S") == 0)
        return (1);
    return (0);
}
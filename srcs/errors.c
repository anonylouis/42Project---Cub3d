/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:04:02 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/31 22:55:07 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int print_error(char *msg, int error)
{
    printf("Error: %s\n", msg);
    return (error);
}

char *ft_error(char *msg)
{
    printf("Error: %s\n", msg);
    return NULL;
}
t_game *exit_with_error(t_game *game)
{
    free_game(game);
    return (NULL);
}
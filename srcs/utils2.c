/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:04:50 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/02 16:58:33 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int file_exists(char *path)
{
	int fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int validate_game(t_game *game)
{
	if (is_empty_color(game->ceiling))
		return print_error("missing ceiling color", 0);
	if (is_empty_color(game->floor))
		return print_error("missing floor color", 0);
	if (!file_exists(game->path_wall_EA))
		return print_error("east wall path not found", 0);
	if (!file_exists(game->path_wall_SO))
		return print_error("south wall path not found", 0);
	if (!file_exists(game->path_wall_WE))
		return print_error("west wall path not found", 0);
	if (!file_exists(game->path_wall_NO))
		return print_error("north wall path not found", 0);
	if (count(game->map) <= 0)
		return print_error("missing map", 0);
	return (1);
}
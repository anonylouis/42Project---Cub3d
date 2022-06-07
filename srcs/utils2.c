/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:04:50 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 12:01:31 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	file_exists(char *path)
{
	int	fd;

	if (path == NULL)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_extension(char *path)
{
	int		len;
	char	*ext;
	int		result;

	result = 0;
	len = ft_strlen(path);
	ext = ft_substr(path, len - 4, 4);
	if (len > 4 && ft_compare(".cub", ext) == 0)
		result = 1;
	else
		result = 0;
	ft_free(ext);
	return (result);
}

int	is_valid(char *line)
{
	return (!is_empty_line(line));
}

int	validate_game(t_game *game)
{
	if (is_empty_color(game->ceiling))
		return (print_error("missing ceiling color", 0));
	if (is_empty_color(game->floor))
		return (print_error("missing floor color", 0));
	if (!file_exists(game->path_wall_EA))
		return (print_error("east wall path not found", 0));
	if (!file_exists(game->path_wall_SO))
		return (print_error("south wall path not found", 0));
	if (!file_exists(game->path_wall_WE))
		return (print_error("west wall path not found", 0));
	if (!file_exists(game->path_wall_NO))
		return (print_error("north wall path not found", 0));
	game->nb_line_map = count(game->map);
	if (game->nb_line_map <= 0)
		return (print_error("missing map", 0));
	return (1);
}

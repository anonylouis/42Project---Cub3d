/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:30:04 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/08 11:41:11 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_color	empty_color(void)
{
	t_color	t;

	t.blue = -1;
	t.green = -1;
	t.red = -1;
	return (t);
}

int	get_map_info(t_game *game, int idx_map)
{
	int	line_number;

	line_number = 0;
	while (game->raw_map[line_number] != NULL)
	{
		if (line_number < idx_map)
		{
			if (is_empty_line(game->raw_map[line_number]))
			{
				line_number++;
				continue ;
			}
			if (!check_map_info(game->raw_map[line_number], game))
				return (0);
		}
		else
			break ;
		line_number++;
	}
	return (1);
}

t_game	*parse(char *file)
{
	t_game	*game;
	int		idx_map;

	game = new_game();
	game->raw_map = get_map(file);
	if (game->raw_map == NULL)
		return (exit_with_error(game));
	idx_map = get_map_idx(game->raw_map);
	if (!get_map_info(game, idx_map))
		return (exit_with_error(game));
	game->map = extract_map(game->raw_map, idx_map, game);
	if (game->map == NULL)
		return (exit_with_error(game));
	return (game);
}

int	is_valid_map(char **s, int start)
{
	t_check_result	result;

	if (s == NULL || start == -1)
		return (print_error("missing map description", 0));
	if (!check_empty_lines(s, start))
		return (print_error("map cannot contain empty lines", 0));
	if (!check_valid_chars(s, start))
		return (print_error("invalid map char", 0));
	if (!check_walls(s, start))
		return (print_error("map must be surrounded by walls", 0));
	result = check_orientation(s, start);
	if (!result.success)
		return (print_error(result.message, 0));
	return (1);
}

char	**extract_map(char **s, int line_idx, t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	if (!is_valid_map(s, line_idx))
		return (NULL);
	map = malloc(sizeof(char *) * ((count(s) - line_idx) + 1));
	if (map == NULL)
		return (NULL);
	while (s[line_idx] != NULL)
	{
		set_orientation(s[line_idx], i, game);
		map[i] = ft_strdup(s[line_idx++]);
		i++;
	}
	map[i] = (NULL);
	return (map);
}

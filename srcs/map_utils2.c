/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:52:10 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/07 11:29:52 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_valid_chars(char **s, int start)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (!is_valid_map_char(s[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_empty_lines(char **s, int start)
{
	int	i;

	i = start;
	while (s[i] != NULL)
	{
		if (is_empty_line(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**get_map(char *path)
{
	int		fd;
	char	**map;

	if (path == NULL || !check_extension(path))
	{
		print_error("file extension must be .cub", 0);
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("cannot open map file\n");
		return (NULL);
	}
	map = read_file(fd);
	if (map == NULL)
		printf("Invalid map file\n");
	close(fd);
	return (map);
}

int	is_wall(char c)
{
	if (c == '1' || c == ' ')
		return (1);
	return (0);
}

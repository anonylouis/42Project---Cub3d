/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:30 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 12:03:07 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	copy_to(char **source, char **dest)
{
	int	i;

	i = 0;
	if (source == NULL)
		return ;
	while (source[i] != NULL)
	{
		dest[i] = ft_strdup(source[i]);
		ft_free(source[i]);
		i++;
	}
	free(source);
	source = (NULL);
}

char	*ft_strtrim_end(char *s)
{
	int		i;
	char	*s1;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (i <= 0)
		return (ft_strdup(s));
	while (s[i - 1] == ' ')
		i--;
	s1 = ft_substr(s, 0, i);
	return (s1);
}

char	*clean_line(char *line)
{
	char	*temp;
	char	*temp2;
	int		len;

	len = ft_strlen(line);
	temp = NULL;
	if (line[ft_strlen(line) - 1] == '\n')
		temp = ft_substr(line, 0, len - 1);
	else
		temp = ft_substr(line, 0, len);
	temp2 = ft_strtrim_end(temp);
	ft_free(temp);
	return (temp2);
}

char	**read_file(int fd)
{
	char	*line;
	char	**result;
	char	**temp;
	int		nb_lines;

	result = NULL;
	temp = NULL;
	nb_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nb_lines++;
		temp = result;
		result = malloc(sizeof(char *) * (nb_lines + 1));
		if (result == NULL)
			return (NULL);
		copy_to(temp, result);
		result[nb_lines - 1] = clean_line(line);
		ft_free(line);
		result[nb_lines] = NULL;
	}
	return (result);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (1);
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && ft_isprint(line[i]))
			return (0);
		i++;
	}
	return (1);
}

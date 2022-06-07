/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:20 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/07 11:29:37 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_wall_line(char *s, char *next)
{
	int	i;
	int	len;
	int	len_n;

	i = 0;
	len = ft_strlen(s);
	len_n = ft_strlen(next);
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != '1' && s[i] != ' ')
			return (0);
		if (next == NULL)
			break ;
		if (len <= len_n && s[i] == ' ' && !is_wall(next[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_line(char *s, int len1, int len2)
{
	int	i;

	i = len1 - len2;
	while (i > 0)
	{
		if (s[len1 - 1] != '1')
			return (0);
		i--;
		len1--;
	}
	return (1);
}

int	check_content_map(char *s, char *last_s)
{
	int	len_s;
	int	last_len;

	last_len = ft_strlen(last_s);
	len_s = ft_strlen(s);
	if (last_len < len_s)
	{
		if (!is_valid_line(s, len_s, last_len))
			return (0);
	}
	else if (last_len > len_s)
	{
		if (!is_valid_line(last_s, last_len, len_s))
			return (0);
	}
	return (1);
}

int	check_spaces(char **s, int *i)
{
	int	j;
	int	len;
	int	len_nxt;
	int	len_lst;

	j = 0;
	len = ft_strlen(s[*i]);
	len_nxt = ft_strlen(s[*i + 1]);
	len_lst = ft_strlen(s[*i - 1]);
	while (s[*i][j] != '\0')
	{
		if (s[*i][j] == ' ')
		{
			if (j > 0 && j < len - 1 && (!is_wall(s[*i][j + 1])
				|| !is_wall(s[*i][j - 1])))
				return (0);
			if (j > 0 && j < len - 1 && j < len_nxt && !is_wall(s[*i + 1][j]))
				return (0);
			if (j > 0 && j < len - 1 && j < len_lst && !is_wall(s[*i - 1][j]))
				return (0);
		}
		j++;
	}
	return (1);
}

int	check_walls(char **s, int start)
{
	int	i;
	int	len;

	i = start;
	while (s[i] != NULL)
	{
		len = ft_strlen(s[i]) - 1;
		if (i == start || i == count(s) - 1)
		{
			if (!check_wall_line(s[i], s[i + 1]))
				return (0);
		}
		else
		{
			if (!check_content_map(s[i], s[i - 1]))
				return (0);
			if (!check_spaces(s, &i))
				return (0);
		}
		if (!is_wall(s[i][0]) || !is_wall(s[i][len]))
			return (0);
		i++;
	}
	return (1);
}

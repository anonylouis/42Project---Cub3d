/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:20 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 16:47:53 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_wall(char c)
{
    if (c == '1' || c == ' ')
        return (1);
    return (0);
}

int check_wall_line(char *s, char *next)
{
    int i;
    int len;
    int len_n;

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
            break;
        if (len <= len_n && s[i] == ' ' && !is_wall(next[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_content_map(char *s, char *last_s)
{
    int len_s;
    int last_len;
    int i;

    last_len = ft_strlen(last_s);
    len_s = ft_strlen(s);
    if (last_len < len_s)
    {
        i = len_s - last_len;
        while (i > 0)
        {
            if (s[len_s - 1] != '1')
                return (0);
            i--;
            len_s--;
        }
    }
    else if (last_len > len_s)
    {
        i = last_len - len_s;
        while (i > 0)
        {
            if (last_s[last_len - 1] != '1')
                return (0);
            i--;
            last_len--;
        }
    }
    return (1);
}

int check_spaces(char **s, int *i)
{
    int j;
    int len;
    int len_nxt;
    int len_lst;

    j = 0;
    len = ft_strlen(s[*i]);
    len_nxt = ft_strlen(s[*i + 1]);
    len_lst = ft_strlen(s[*i - 1]);
    while (s[*i][j] != '\0')
    {
        if (s[*i][j] == ' ')
        {
            if (j > 0 && j < len - 1 &&  (!is_wall(s[*i][j + 1]) 
            || !is_wall(s[*i][j - 1])))
                return (0);
            if (j > 0 && j < len - 1 && len <= len_nxt && !is_wall(s[*i + 1][j]))
                return (0);
            if (j > 0 && j < len - 1 && len <= len_lst && !is_wall(s[*i - 1][j]))
                return (0);
        }
        j++;
    }
    return (1);
}

int check_walls(char **s, int start)
{
    int i;
    int len;

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

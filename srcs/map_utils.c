/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:20 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/04 21:45:48 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_wall_line(char *s, char *next)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != '1' && s[i] != ' ')
            return (0);
        if (next == NULL)
            break;
        if (s[i] == ' ' && next[i] != '1')
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
    return (1);
}

int check_spaces(char **s, int *i)
{
    int j;

    j = 0;
    while (s[*i][j] != '\0')
    {
        if (s[*i][j] == ' ')
        {
            if (ft_strlen(s[*i]) - 1 > j && ((s[*i][j + 1] != '1' 
            && s[*i][j + 1] != ' ') || (s[*i][j - 1] != '1' 
            && s[*i][j - 1] != ' ')))
                return (0);
            if (ft_strlen(s[*i]) <= ft_strlen(s[*i + 1]))
            {
                if (s[*i + 1][j] != ' ' && s[*i + 1][j] != '1')
                    return (0);
            }
            if (ft_strlen(s[*i]) <= ft_strlen(s[*i - 1]))
            {
                if (s[*i - 1][j] != '1' && s[*i - 1][j] != ' ')
                    return (0);
            }
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
        len = ft_strlen(s[i] - 1);
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
        if ((s[i][0] != '1' && s[i][0] != ' ') || (s[i][len] != ' ' && s[i][len] != '1'))
            return (0);
        i++;
    }
    return (1);
}

int check_valid_chars(char **s, int start)
{
    int i;
    int j;

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

int check_empty_lines(char **s, int start)
{
    int i;
    i = start;
    while (s[i] != NULL)
    {
        if (is_empty_line(s[i]))
            return (0);
        i++;
    }
    return (1);
}

char **get_map(char *path)
{
    int fd;
    char **map;

    if (path == NULL || !check_extension(path))
    {
        print_error("file extension must be .cub", 0);
        return NULL;
    }
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        printf("cannot open map file\n");
        return NULL;
    }
    map = read_file(fd);
    if (map == NULL)
        printf("Invalid map file\n");
    close(fd);
    return map;
}

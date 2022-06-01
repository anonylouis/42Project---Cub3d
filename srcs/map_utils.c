/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:20 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/01 21:07:36 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_spaces(char **s, int start, int *i)
{
    int j;

    j = 0;
    while (s[*i][j] != '\0')
    {
        if (*i == start || *i == count(s) - 1)
        {
            if (s[*i][j] != '1' && s[*i][j] != ' ')
                return (0);
        }
        else
        {
            if (s[*i][j] == ' ')
            {
                if ((s[*i + 1][j] != ' ' && s[*i + 1][j] != '1') 
                || (s[*i - 1][j] != '1' && s[*i - 1][j] != ' ') 
                || (ft_strlen(s[*i]) - 1 > j && ((s[*i][j + 1] != '1' 
                && s[*i][j + 1] != ' ') 
                || (s[*i][j - 1] != '1' && s[*i][j - 1] != ' '))))
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
        len = ft_strlen(s[i]);
        if (!check_spaces(s, start, &i))
            return (0);
        if ((s[i][0] != '1' && s[i][0] != ' ') || (s[i][len - 1] != ' ' && s[i][len - 1] != '1'))
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
        print_error("Error: file extension must be .cub", 0);
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

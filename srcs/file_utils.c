/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:30 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/18 16:46:22 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int count(char **s)
{
    int i;
    int c;

    c = 0;
    i = 0;
    while (s[i++] != NULL)
    {
        c++;
    }
    return c;
}

t_color is_floor(char **tokens)
{
    char **colors;
    
    if (ft_compare(tokens[0], "F") == 0)
    {
        colors = ft_split(tokens[1], ',');
        if (count(colors) == 3 && ft_compare(tokens[0], "F") == 0 && is_int(colors[0]) && is_int(colors[1]) && is_int(colors[2]))
        {
            printf("%s %s %s \n", colors[0], colors[1], colors[2]);
            t_color c = {.r = ft_atoi(colors[0]), .g = ft_atoi(colors[1]), .b = ft_atoi(colors[2])};
            printf("floor\n");
            return c;
        }
    }
    return empty_color();
}

t_color is_ceiling(char **tokens)
{
    char **colors;

    if (ft_compare(tokens[0], "C") == 0)
    {
        colors = ft_split(tokens[1], ',');
        if (count(colors) == 3 && ft_compare(tokens[0], "C") == 0 && is_int(colors[0]) && is_int(colors[1]) && is_int(colors[2]))
        {
            t_color c = {.r = ft_atoi(colors[0]), .g = ft_atoi(colors[1]), .b = ft_atoi(colors[2])};
            printf("ceiling\n");
            return c;
        }
    }
    return empty_color();
}

int copy_to(char **source, char **dest)
{
    int i = 0;
    if (source == NULL)
        return 0;
    while (source[i] != NULL)
    {
        dest[i] = source[i];
        i++;
    }
    return i;
}

char **get_map(char *path)
{
    int fd;
    char **map;

    if ((fd = open(path, O_RDONLY)) == -1)
    {
        printf("cannot open map file\n");
        close(fd);
        return NULL;
    }
    map = read_file(fd);
    close(fd);
    return map;
}

int is_valid(char *line)
{
    return !is_empty_line(line);
}

char *clean_line(char *line)
{
    char *temp;
    char *temp2;
    temp = ft_strtrim(line, " ");
    temp2 = ft_substr(temp, 0, ft_strlen(temp) - 1);

    free(line);
    free(temp);
    return temp2;
}

char **read_file(int fd)
{
    char *line;
    char **result = NULL;
    char **temp = NULL;
    int nb_lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        if (!is_valid(line))
            continue;
        nb_lines++;
        temp = result;
        result = malloc(sizeof(char *) * (nb_lines + 1));
        copy_to(temp, result);
        result[nb_lines - 1] = clean_line(line);
        free(temp);
    }
    result[nb_lines] = NULL;
    return result;
}

int is_empty_line(char *line)
{
    int i;
    int length;

    i = 0;
    length = 0;
    while (line[i] != '\0')
    {
        length++;
        i++;
    }
    if (length <= 1)
        return (1);
    return (0);
}
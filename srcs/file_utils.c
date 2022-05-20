/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:30 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/19 23:17:59 by mrahmani         ###   ########.fr       */
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

int is_floor(char **tokens, t_game *game)
{
    char **colors;

    if (ft_compare(tokens[0], "F") == 0)
    {
        if (!is_empty_color(game->floor))
        {
            printf("Duplicate line: floor\n");
            return (0);
        }
        colors = ft_split(tokens[1], ',');
        if (count(colors) == 3 && is_int(colors[0]) && is_int(colors[1]) && is_int(colors[2]))
        {
            game->floor.r = ft_atoi(colors[0]);
            game->floor.g = ft_atoi(colors[1]);
            game->floor.b = ft_atoi(colors[2]);
            ft_free_all(colors);
            return (1);
        }
        ft_free_all(colors);
    }
    return (0);
}

int is_ceiling(char **tokens, t_game *game)
{
    char **colors;

    if (ft_compare(tokens[0], "C") == 0)
    {
        if (!is_empty_color(game->celeing))
        {
            printf("Duplicate line: %s", tokens[0]);
            return (0);
        }
        colors = ft_split(tokens[1], ',');
        if (count(colors) == 3 && is_int(colors[0]) && is_int(colors[1]) && is_int(colors[2]))
        {
            game->celeing.r = ft_atoi(colors[0]);
            game->celeing.g = ft_atoi(colors[1]);
            game->celeing.b = ft_atoi(colors[2]);
            ft_free_all(colors);
            return 1;
        }
        ft_free_all(colors);
    }
    return 0;
}

int copy_to(char **source, char **dest)
{
    int i;
    i = 0;
    if (source == NULL)
        return (0);
    while (source[i] != NULL)
    {
        dest[i] = source[i];
        i++;
    }
    return (i);
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
        if (result == NULL)
            return NULL;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:06:30 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/03 11:15:47 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int copy_to(char **source, char **dest)
{
    int i;
    
    i = 0;
    if (source == NULL)
        return (0);
    while (source[i] != NULL)
    {
        dest[i] = ft_strdup(source[i]);
        free(source[i]);
        i++;
    }
    free(source);
    return (i);
}

int check_extension(char *path)
{
    int len;
    char *ext;
    int result;
    
    result = 0;
    len = ft_strlen(path);
    ext = ft_substr(path, len - 4, 4);
    result = len > 4 && ft_compare(".cub", ext) == 0;
    ft_free(ext);
    return (result);
}

int is_valid(char *line)
{
    return (!is_empty_line(line));
}

char *clean_line(char *line)
{
    char *temp;
    char *temp2;

    //temp = ft_strtrim(line, " ");
    temp = ft_strdup(line);
    temp2 = ft_substr(temp, 0, ft_strlen(temp) - 1);
    free(line);
    free(temp);
    return temp2;
}

char **read_file(int fd)
{
    char *line;
    char **result;
    char **temp;
    int nb_lines;
    
    result = NULL;
    temp = NULL;
    nb_lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        nb_lines++;
        temp = result;
        result = malloc(sizeof(char *) * (nb_lines + 1));
        if (result == NULL)
            return NULL;
        copy_to(temp, result);
        result[nb_lines - 1] = clean_line(line);
        result[nb_lines] = NULL;
    }
    return (result);
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
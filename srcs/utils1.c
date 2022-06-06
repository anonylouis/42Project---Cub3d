/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:04:16 by mrahmani          #+#    #+#             */
/*   Updated: 2022/06/06 11:00:42 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_start_index(char *line)
{
    int i;
    i = 0;

    while (line[i] == ' ')
    {
        i++;
    }
    return i;
}

int is_white_space(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
            return 0;
        i++;
    }
    return (1);
}

int ft_compare(char *s1, char *s2)
{
    int len_s1;
    int len_s2;
    int i;

    len_s1 = 0;
    len_s2 = 0;
    i = 0;
    if (s1 == NULL || s2 == NULL)
        return (-1);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    if (len_s1 != len_s2)
        return (-1);
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (-1);
        i++;
    }
    return (0);
}

int is_int(char *s)
{
    int i;

    i = 0;
    if (s == NULL)
        return (0);
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int count(char **s)
{
    int i;

    i = 0;
    if (s == NULL)
        return (0);
    while (s[i] != NULL)
        i++;
    return (i);
}
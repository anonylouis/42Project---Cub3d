/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:04:16 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/16 17:19:57 by mrahmani         ###   ########.fr       */
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
    int len_s1 = ft_strlen(s1);
    int len_s2 = ft_strlen(s2);
    int len;
    if (len_s1 < len_s2)
        len = len_s2;
    len = len_s1;

    int r = (ft_strncmp(s1, s2, len));
    return r;
}

int is_int(char *s)
{
    int i;
    
    i = 0;
    while (s[i] != '\0')
    {
        if (!ft_isdigit(s[i]))
            return 0;
        i++;
    }
    return 1;
}
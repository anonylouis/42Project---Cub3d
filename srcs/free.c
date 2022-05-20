/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:20:21 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/19 21:37:38 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
void ft_free(char *f)
{
    if (f != NULL)
    {
        free(f);
    }
}

void ft_free_all(char **f)
{
    if (f != NULL)
    {
        int i = 0;
        while (f[i] != NULL)
        {
            ft_free(f[i]);
            i++;
        }
        free(f);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:04:02 by mrahmani          #+#    #+#             */
/*   Updated: 2022/05/17 12:04:32 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int print_error(char *msg, int error)
{
    printf("Error: %s\n", msg);
    return (error);
}

char *ft_error(char *msg)
{
    //free
    printf("Error: %s\n", msg);
    return NULL;
}
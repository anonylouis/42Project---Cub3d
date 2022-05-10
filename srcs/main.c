/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/10 16:24:41 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main()
{
        // libft well added if compile
        char str[] = "This is a main test\n";
        write(1, str, ft_strlen(str));

        // minilibx well added if compile
        void *mlx_ptr = mlx_init();
        (void) mlx_ptr;
        
        return (0);
}

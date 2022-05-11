/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/11 17:00:35 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main()
{
        t_graph *graph;

        // libft well added if compile
        char str[] = "This is a main test\n";
        write(1, str, ft_strlen(str));

        // minilibx well added if compile
        void *mlx_ptr = mlx_init();
        (void) mlx_ptr;

        // parsing part here
        // 


        // map test 
        char map[6][6] = {{'1','1','1','1','1','1'}, {'1','0','0','0','0','1'}, {'1','0','0','N','0','1'}, {'1','1','0','0','0','1'}, {' ','1','0','0','0','1'}, {' ','1','1','1','1','1'}};
        ft_putchar_fd(map[2][3], 1);
        // ray casting part
        graph = new_graph();
        if (graph)
                play(graph);
        free_graph(graph);
        return (0);
}

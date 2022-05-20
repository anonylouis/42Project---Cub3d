/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:46:56 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/20 22:50:23 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

void print(t_game *game)
{
        int i = 0;

        printf("EA : %s\n", game->texture_ea);
        printf("NO : %s\n", game->texture_no);
        printf("SO : %s\n", game->texture_so);
        printf("WE : %s\n", game->texture_we);
        printf("F : %d %d %d\n", game->floor.r, game->floor.g, game->floor.b);
        printf("C : %d %d %d\n", game->celeing.r, game->celeing.g, game->celeing.b);

        while (game->map[i] != NULL)
        {
                printf("%s\n", game->map[i++]);
        }
}

int main(int argc, char **argv)
{

         t_graph *graph;
        t_game *game;

        if (argc == 2)
        {
                game = parse(argv[1]);
                if (game != NULL)
                {
                        print(game);
                       // free_game(game);
                }
        }
        //libft well added if compile
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

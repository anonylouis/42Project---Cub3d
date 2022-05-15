/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/15 18:18:25 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "get_next_line.h"

# define WIDTH 700
# define HEIGHT 700

// FOV = Field Of View 
# define FOV 180

typedef struct s_img
{
        int     size_line;
        int     number_line;
        void    *img_ptr;
        char    *img_addr;
}               t_img;

typedef struct s_game
{
        char **map;
        double  player_x;
        double  player_y;
        double  angle_vision;

}               t_game;

typedef struct s_graph
{
        void    *mlx_ptr;
        void    *win_ptr;
        t_img   img;
        t_game  game;
}               t_graph;

typedef struct  s_point
{
        double x;
        double y;
}               t_point;

//GRAPH STRUCT
t_graph *new_graph();
void	free_graph(t_graph *graph);

// GAME STRUCT
t_game  *new_game(char **map);
void    free_game(t_game *game);

// GAME
void    play(t_graph *graph);

// KEYCATCH
int	keycatch(int keycode, t_graph *graph);
int    close_loop(t_graph *graph);

// RAY CASTING
double  wall_distance(t_graph *graph, double angle);
void    draw_pixel_column(t_img img, int column, double d);

// IMG
void    init_img_addr(t_graph *graph, t_img *img, int w, int h);
void    add_pixel_img(t_img img, int x, int y, unsigned int color);

// POINT
void    set_point(t_point *p, double x, double y);

// UTILS
double  rad(double angle);
int     max(int a, int b);
int     min(int a, int b);

#endif

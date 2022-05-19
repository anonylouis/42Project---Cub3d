/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/19 16:15:43 by lcalvie          ###   ########.fr       */
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
# include "keycode.h"

// SIZE OF SCREEN
# define WIDTH 2000
# define HEIGHT 800

// H_MAX OF A WALL
# define H_MAX HEIGHT/1000000000.0

// FOV = Field Of View
# define FOV 90

// ROTATION SPEED OF VIEW ANGLE ( IN DEGREES )
# define DELTA_ANGLE 5

// STEP ON THE MAP
# define STEP 0.2

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_img
{
	int		size_line;
	int		number_line;
	void	*img_ptr;
	char	*img_addr;
}			t_img;

typedef struct s_game
{
	char	**map;
	double	player_x;
	double	player_y;
	double	angle_vision;
	char	*path_wall_NO;
	char	*path_wall_SO;
	char	*path_wall_WE;
	char	*path_wall_EA;
	t_color	floor;
	t_color	ceiling;
}			t_game;

typedef struct s_graph
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_game	game;
	t_img	wall_NO;
	t_img	wall_SO;
	t_img	wall_WE;
	t_img	wall_EA;
}			t_graph;

typedef struct s_point
{
	double	x;
	double	y;
} t_point;

// GRAPH STRUCT
t_graph	*new_graph();
void	free_graph(t_graph *graph);

// GAME STRUCT
t_game	*new_game(char **map);
void	free_game(t_game *game);

// GAME
void	play(t_graph *graph);
void	print_game(t_graph *graph);

// KEYCATCH
int		keycatch(int keycode, t_graph *graph);
int		close_loop(t_graph *graph);
int		keycatch_angle(int keycode, t_graph *graph);
int		keycatch_step(int keycode, t_graph *graph);

// RAY CASTING
double	wall_distance(t_graph *graph, double angle, double *x_wall);
void	draw_pixel_column(t_graph *graph, int column, double d, double x_wall);

// IMG
void	init_img_addr(t_graph *graph, t_img *img, int w, int h);
void	add_pixel_img(t_img img, int x, int y, t_color color);
int		init_textures(t_graph *graph);

// POINT
void	set_point(t_point *p, double x, double y);

// UTILS
double	rad(double angle);
int		max(int a, int b);
int		min(int a, int b);

#endif

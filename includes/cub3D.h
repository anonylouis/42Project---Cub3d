/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/07 12:40:56 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "get_next_line.h"
#include "keycode.h"
#include <fcntl.h>
#include <stdio.h>

// SIZE OF SCREEN
#define WIDTH 1000
#define HEIGHT 700

// MOVEMENT MOUSE
#define MOUSE_MOVED_LEFT 0.4
#define MOUSE_MOVED_RIGHT 0.6
#define MOVED_LEFT WIDTH * MOUSE_MOVED_LEFT
#define MOVED_RIGHT WIDTH * MOUSE_MOVED_RIGHT
#define SPEED_ANGLE 3.6

// H_MAX OF A WALL
#define H_MAX HEIGHT / 1000000000.0

// FOV = Field Of View
#define FOV 90

// ROTATION SPEED OF VIEW ANGLE ( IN DEGREES ) - ARROW
#define DELTA_ANGLE 5

// STEP ON THE MAP
#define STEP 0.2

//IN A WALL
#define IN_WALL 0.05

//MINIMAP
#define MINIMAP_SIZE 200
#define MINIMAP_N_CASE 9

#define MINIMAP_X WIDTH * 3/4
#define MINIMAP_Y 10

#define MINIMAP_CONTOUR 3

#define MINIMAP_COLOR_CONTOUR 0x000000
#define MINIMAP_COLOR_WALL 0x663300
#define MINIMAP_COLOR_FLOOR 0xFFFF00
#define MINIMAP_COLOR_PLAYER 0xFF0000

typedef struct s_color
{
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_img
{
	int size_line;
	int number_line;
	void *img_ptr;
	char *img_addr;
} t_img;

typedef struct s_special_block
{
	struct s_special_block *next;
	int x;
	int y;
	double percent;
} t_special_block;

typedef struct s_game
{
	char **map;
	char orientation;
	double player_x;
	double player_y;
	double angle_vision;
	char *path_wall_NO;
	char *path_wall_SO;
	char *path_wall_WE;
	char *path_wall_EA;
	t_color floor;
	t_color ceiling;
	t_color minimap_contour;
	t_color minimap_wall;
	t_color minimap_floor;
	t_color minimap_player;
	char **raw_map;
	int	nb_line_map;
	int has_parse_error;
} t_game;

typedef struct s_graph
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	face;
	t_special_block	*hit_door;
	double	percent_face;
	t_img	img;
	t_game	game;
	t_img	wall_NO;
	t_img	wall_SO;
	t_img	wall_WE;
	t_img	wall_EA;
	t_special_block *door;
	t_special_block *boost;
} t_graph;

typedef struct s_point
{
	double x;
	double y;
} t_point;

typedef struct s_check_result
{
	int success;
	char* message;
} t_check_result;

// GRAPH STRUCT
t_graph *new_graph();
void free_graph(t_graph *graph);

// GAME STRUCT
t_game *new_game();
void free_game(t_game *game);

// GAME
void play(t_graph *graph);
void print_game(t_graph *graph);

// HOOK
int keycatch(int keycode, t_graph *graph);
int close_loop(t_graph *graph);
int keycatch_angle(int keycode, t_graph *graph);
int keycatch_step(int keycode, t_graph *graph);
int	mousemoved(t_graph *graph);

// RAY CASTING
int	find_next_border(double *x, double *y, double angle);
double wall_distance(t_graph *graph, double angle);
void draw_pixel_column(t_graph *graph, int column, double d);

// IMG
void init_img_addr(t_graph *graph, t_img *img, int w, int h);
void add_pixel_img(t_img img, int x, int y, t_color color);
int init_textures(t_graph *graph);

// MINIMAP
void    init_color_minimap(t_graph *graph);
void    print_minimap(t_graph *graph);

// BOOST && DOOR
int	specal_block_add_back(t_special_block **begin_list, t_special_block *new);
int	init_special_blocks(t_graph *graph);


// POINT
void set_point(t_point *p, double x, double y);

// UTILS
double rad(double angle);
int max(int a, int b);
int min(int a, int b);
double dmin(double a, double b);
double	distance(double x1, double y1, double x2, double y2);
void	correct_angle(double *angle);

// GRAPH STRUCT
t_graph *new_graph();
void free_graph(t_graph *graph);

// file
char **get_map(char *file_path);
char **read_file(int fd);
char *clean_line(char *line);

// parse
int check_walls(char **s, int start);
int check_valid_chars(char **s, int start);
int has_orientation(char *s);
int check_map_info(char *line, t_game *game);
int check_floor_color(char **tokens, t_game *game);
int check_ceiling_color(char **tokens, t_game *game);
int is_no_texture(char **tokens, t_game *game);
int is_we_texture(char **tokens, t_game *game);
int is_ea_texture(char **tokens, t_game *game);
int is_so_texture(char **tokens, t_game *game);
t_game *parse(char *file);
int count(char **s);
int is_ceiling(char **tokens, t_game *game);
int is_floor(char **tokens, t_game *game);
t_color empty_color();
int is_empty_color(t_color color);
int ft_compare(char *s1, char *s2);
int is_empty_line(char *line);
int is_int(char *s);

// map
int is_valid_map(char **s, int start);
int is_valid_map_char(char c);
char **extract_map(char **s, int line_idx, t_game* game);
int get_map_idx(char **map);

// error
int print_error(char *msg, int error);

// free
void ft_free(char *f);
void ft_free_all(char **f);
void free_game(t_game *game);
t_check_result check_orientation(char **s, int start);
t_check_result error(char *message);
t_check_result success();
void set_angle_vision(t_game *game);
int check_empty_lines(char **s, int start);
t_game *exit_with_error(t_game *game);
int check_extension(char *path);
int file_exists(char *path);
int validate_game(t_game *game);
int file_exists(char *path);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/06/09 15:51:32 by lcalvie          ###   ########.fr       */
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
# include <fcntl.h>
# include <stdio.h>

// SIZE OF SCREEN
# define WIDTH 1000
# define HEIGHT 700

// MOVEMENT MOUSE
# define MOUSE_MOVED_LEFT 0.4
# define MOUSE_MOVED_RIGHT 0.6
# define SPEED_ANGLE 4.0

// FOV = Field Of View
# define FOV 90

// STEP & ARROW
# define DELTA_ANGLE 5
# define STEP 0.2

// WALL
# define H_MAX 1000000000.0
# define IN_WALL 0.05

//MINIMAP
# define MINIMAP_SIZE 200
# define MINIMAP_N_CASE 9
# define MINIMAP_X 750
# define MINIMAP_Y 10
# define MINIMAP_CONTOUR 3
# define MINIMAP_COLOR_CONTOUR 0x000000
# define MINIMAP_COLOR_WALL 0x663300
# define MINIMAP_COLOR_FLOOR 0xFFFF00
# define MINIMAP_COLOR_PLAYER 0xFF0000

// DOOR
# define TEXTURE_DOOR_PATH "./xpm/jail2.xpm"
# define SPEED_DOOR_OPENING 0.01
# define TRIGGER_DOOR 0.5

//BOOST
# define FRAME1 "./xpm/battery1.xpm"
# define FRAME2 "./xpm/battery2.xpm"
# define FRAME3 "./xpm/battery3.xpm"
# define FRAME4 "./xpm/battery4.xpm"
# define SPEED_CHARGE_BOOST 0.005
# define TRIGGER_BOOST 0.1

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_img
{
	int		size_line;
	int		number_line;
	void	*img_ptr;
	char	*img_addr;
}	t_img;

typedef struct s_special_block
{
	struct s_special_block	*next;
	int						x;
	int						y;
	double					intersection_x;
	double					intersection_y;
	double					percent;
	double					distance;
	int						face;
	int						open_close;
}	t_special_block;

typedef struct s_game
{
	char			**map;
	char			orientation;
	double			player_x;
	double			player_y;
	double			angle_vision;
	char			*path_wall_no;
	char			*path_wall_so;
	char			*path_wall_we;
	char			*path_wall_ea;
	t_color			floor;
	t_color			ceiling;
	t_color			minimap_contour;
	t_color			minimap_wall;
	t_color			minimap_floor;
	t_color			minimap_player;
	char			**raw_map;
	int				nb_line_map;
	int				has_parse_error;
	t_special_block	*boost;
}	t_game;

typedef struct s_graph
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				face;
	int				last_hit_door;
	t_special_block	*hit_door;
	double			percent_face;
	t_img			img;
	t_game			game;
	t_img			wall_no;
	t_img			wall_so;
	t_img			wall_we;
	t_img			wall_ea;
	t_img			texture_door;
	t_special_block	*door;
	t_img			boost1;
	t_img			boost2;
	t_img			boost3;
	t_img			boost4;
	int				hit_boost;
	double			is_boost;
}	t_graph;

typedef struct s_check_result
{
	int		success;
	char	*message;
}	t_check_result;

// GRAPH STRUCT
t_graph			*new_graph(void);
void			free_graph(t_graph *graph);

// GAME STRUCT
t_game			*new_game(void);
void			free_game(t_game *game);

// GAME
void			play(t_graph *graph);
void			print_game(t_graph *graph);

// HOOK
int				keycatch(int keycode, t_graph *graph);
int				close_loop(t_graph *graph);
int				keycatch_angle(int keycode, t_graph *graph);
int				keycatch_step(int keycode, t_graph *graph);
int				mousemoved(t_graph *graph);

// RAY CASTING
int				find_next_border(double *x, double *y, double angle);
void			draw_pixel_column(t_graph *graph, int column, double d);
double			wall_distance(t_graph *graph, double angle);

// IMG
int				init_textures(t_graph *graph);
int				init_texture(t_graph *graph, t_img *img, char *path);
void			init_img_addr(t_graph *graph, t_img *img, int w, int h);
void			add_pixel_img(t_img img, int x, int y, t_color color);

// MINIMAP
void			init_color_minimap(t_graph *graph);
void			print_minimap(t_graph *graph);

// SPECIAL_BLOCK
int				init_special_blocks(t_graph *graph);
int				special_block_add_back(t_special_block **begin_list,
					t_special_block *new_list);
void			special_block_clear(t_special_block **begin_list);
void			sort_special_block(t_special_block *lst);
t_special_block	*copy_special_block(t_special_block *copy);
t_special_block	*new_special_block(int pt_y, int pt_x, double pc);

//DOOR
int				init_texture_door(t_graph *graph);
int				change_door_status(t_graph *graph);
int				update_door(t_graph *graph);
void			draw_doors(t_graph *graph, int column,
					double fish_eye_correction);
double			collision(t_graph *graph, double angle);
t_special_block	*find_door(t_graph *graph, int i, int j);

//BOOST
int				init_textures_boost(t_graph *graph);
t_special_block	*find_boost(t_graph *graph, int i, int j);
void			update_boost(t_graph *graph);
int				take_boost(t_graph *graph);

// UTILS
int				max(int a, int b);
int				min(int a, int b);
void			correct_angle(double *angle);
double			rad(double angle);
double			dmin(double a, double b);
double			distance(double x1, double y1, double x2, double y2);

// FILE
char			**get_map(char *file_path);
char			**read_file(int fd);
char			*clean_line(char *line);

// PARSING
int				check_walls(char **s, int start);
int				check_valid_chars(char **s, int start);
int				check_valid_chars_bonus(char **s, int start, t_game *game);
int				has_orientation(char *s);
int				check_map_info(char *line, t_game *game);
int				check_floor_color(char **tokens, t_game *game);
int				check_ceiling_color(char **tokens, t_game *game);
int				is_no_texture(char **tokens, t_game *game);
int				is_we_texture(char **tokens, t_game *game);
int				is_ea_texture(char **tokens, t_game *game);
int				is_so_texture(char **tokens, t_game *game);
int				count(char **s);
int				is_ceiling(char **tokens, t_game *game);
int				is_floor(char **tokens, t_game *game);
int				is_empty_color(t_color color);
int				ft_compare(char *s1, char *s2);
int				is_empty_line(char *line);
int				is_int(char *s);
void			set_orientation(char *line, int index, t_game *game);
t_game			*parse(char *file);
t_color			empty_color(void);

// MAP
int				is_valid_map(char **s, int start);
int				is_valid_map_bonus(char **s, int start, t_game *game);
int				is_valid_map_char(char c);
int				get_map_idx(char **map);
int				is_wall(char c);
char			**extract_map(char **s, int line_idx, t_game *game);

// ERRORS
int				print_error(char *msg, int error);
int				check_empty_lines(char **s, int start);
int				check_extension(char *path);
int				file_exists(char *path);
int				validate_game(t_game *game);
int				file_exists(char *path);
void			ft_free(char *f);
void			ft_free_all(char **f);
void			free_game(t_game *game);
void			set_angle_vision(t_game *game);
t_game			*exit_with_error(t_game *game);
t_check_result	check_orientation(char **s, int start);
t_check_result	error(char *message);
t_check_result	success(void);

#endif

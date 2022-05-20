/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:52:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/05/19 21:17:46 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "get_next_line.h"

#define WIDTH 700
#define HEIGHT 700

// FOV = Field Of View
#define FOV 90

typedef struct s_graph
{
        void *mlx_ptr;
        void *win_ptr;
} t_graph;

typedef struct s_color
{
        int r;
        int g;
        int b;
} t_color;

typedef struct s_game
{
        char **map;
        int success;
        int nb_lines;
        int nb_col;
        char *error_message;
        int has_errors;

        char *texture_no;
        char *texture_we;
        char *texture_ea;
        char *texture_so;

        t_color floor;
        t_color celeing;
        char** raw_map;
        
} t_game;

typedef struct s_point
{
        double x;
        double y;
} t_point;

// GRAPH STRUCT
t_graph *new_graph();
void free_graph(t_graph *graph);

// GAME STRUCT
t_game *new_game();
void free_game(t_game *game);

// GAME
void play(t_graph *graph);

// POINT
void set_point(t_point *p, double x, double y);

// file
char **get_map(char *file_path);
char** read_file(int fd);
char *clean_line(char *line);
// parse
int check_textures(char *line, t_game *game);
int check_floor_color(char **tokens, t_game *game);
int check_ceiling_color(char **tokens, t_game *game);
int is_no_texture(char **tokens, t_game *game);
int is_we_texture(char **tokens, t_game *game);
int is_ea_texture(char **tokens, t_game *game);
int is_so_texture(char **tokens, t_game *game);
t_game* parse(char* file);
int count(char** s);
int is_ceiling(char **tokens, t_game *game);
int is_floor(char **tokens, t_game *game);
t_color empty_color();
int is_empty_color(t_color color);
int ft_compare(char *s1, char *s2);
int is_empty_line(char *line);
int is_int(char *s);

//map
int is_valid_map(char **s, int start);
int is_valid_map_char(char c);
char **extract_map(char **s, int line_idx);
int get_map_idx(char **map);
//error
int print_error(char *msg, int error);
char *ft_error(char *msg);

//free

void ft_free(char *f);
void ft_free_all(char **f);
void free_game(t_game* game);

#endif

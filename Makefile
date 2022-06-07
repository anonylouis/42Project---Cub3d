CC = gcc

FLAGS = -g -Wall -Wextra -Werror -O3

NAME = cub3D
NAME_BONUS = cub3D_bonus

SRCS_DIR = ./srcs/
#remplir .c ici
SOURCES_COMMON =	game.c \
			point.c \
			get_next_line.c \
			get_next_line_utils.c \
			parser.c \
			textures.c\
			utils1.c\
			errors.c\
			file_utils.c\
			free.c\
			img.c\
			hook.c\
			utils.c\
			raycasting.c\
			texture.c\
			find_next_border.c\
			orientation.c\
			map_utils.c\
			color.c\
			utils2.c\
			keycatch_step.c\
			map_utils2.c\

SOURCES_MANDATORY =	play.c\
			main.c\
			graph.c\
			map.c\
			wall_distance.c\

SOURCES_BONUS =		bonus_play.c\
			bonus_mousemoved.c\
			bonus_minimap.c\
			bonus_main.c\
			bonus_graph.c\
			bonus_special_block.c\
			bonus_map.c\
			bonus_wall_distance.c\

OBJS_DIR = ./objs/

OBJECTS_COMMON = ${SOURCES_COMMON:.c=.o}
OBJS_COMMON = $(addprefix $(OBJS_DIR), $(OBJECTS_COMMON))

OBJECTS_MANDATORY = ${SOURCES_MANDATORY:.c=.o}
OBJS_MANDATORY = $(addprefix $(OBJS_DIR), $(OBJECTS_MANDATORY))

OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(OBJECTS_BONUS))

HEADERS_DIR = ./includes/
#remplir .h ici
HEADER_FILES =	cub3D.h \
		get_next_line.h \
		keycode.h \

HDRS = $(addprefix $(HEADERS_DIR), $(HEADER_FILES))

DEPENDENCIES = ${OBJS:.o=.d}

LIBFT_AR = libft.a
LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_AR))

MINILIBX_AR = libmlx.a
MINILIBX_DIR = ./minilibx/
MINILIBX = $(addprefix $(MINILIBX_DIR), $(MINILIBX_AR))

MINILIBX_FLAGS = -L/user/include/../lib -lXext -lX11 -lm

all : $(NAME)

$(NAME) :	$(MINILIBX) $(LIBFT) $(OBJS_COMMON) $(OBJS_MANDATORY)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_COMMON) $(OBJS_MANDATORY) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) :		$(MINILIBX) $(LIBFT) $(OBJS_COMMON) $(OBJS_BONUS)
		$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_COMMON) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS)

clean :
		$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
		rm -f $(OBJS_COMMON)  $(OBJS_MANDATORY) $(OBJECTS_BONUS) $(DEPENDENCIES)
		rm -rf $(OBJS_DIR)

fclean :	clean
		$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
		$(MAKE) -C $(MINILIBX_DIR) clean --no-print-directory
		rm -f $(NAME)
		rm -f $(NAME_BONUS)

re :	fclean all

$(LIBFT) :
		$(MAKE) bonus -C $(LIBFT_DIR) --no-print-directory

$(MINILIBX) :
		$(MAKE) all -C $(MINILIBX_DIR) --no-print-directory

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(HDRS)
			mkdir -p $(OBJS_DIR)
			$(CC) $(FLAGS) -MMD -I $(HEADERS_DIR) -o $@ -c $<

.PHONY : all re clean fclean bonus

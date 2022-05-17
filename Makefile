CC = gcc

FLAGS = -Wall -Wextra -Werror -g

NAME = cub3D

SRCS_DIR = ./srcs/
#remplir .c ici
SOURCES =	main.c \
		game.c \
		graph.c \
		play.c \
		point.c \
		get_next_line.c \
		get_next_line_utils.c \
		img.c \
		hook.c \
		utils.c \
		raycasting.c \
		texture.c

OBJS_DIR = ./objs/
OBJECTS = ${SOURCES:.c=.o}
OBJS = $(addprefix $(OBJS_DIR), $(OBJECTS))

HEADERS_DIR = ./includes/
#remplir .h ici
HEADER_FILES =	cub3D.h \
		get_next_line.h \


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

$(NAME) :	$(MINILIBX) $(LIBFT) $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS)

clean : 
		$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
		rm -f $(OBJS) $(DEPENDENCIES)
		rm -rf $(OBJS_DIR)

fclean :	clean
		$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
		$(MAKE) -C $(MINILIBX_DIR) clean --no-print-directory
		rm -f $(NAME)

re :	fclean all

$(LIBFT) :
		$(MAKE) bonus -C $(LIBFT_DIR) --no-print-directory

$(MINILIBX) :
		$(MAKE) all -C $(MINILIBX_DIR) --no-print-directory

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(HDRS)
			mkdir -p $(OBJS_DIR)
			$(CC) $(FLAGS) -MMD -I $(HEADERS_DIR) -o $@ -c $<

.PHONY : all re clean fclean

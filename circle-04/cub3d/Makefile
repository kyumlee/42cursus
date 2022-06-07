# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 00:22:49 by kyumlee           #+#    #+#              #
#    Updated: 2021/06/20 23:41:27 by kyumlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_MLX = -Lmlx -lmlx
FRAMEWORK = -framework OpenGL -framework AppKit
SRCS = ./srcs/gnl.c ./srcs/gnl_utils.c \
	   ./srcs/graphics.c ./srcs/key_handling.c \
	   ./srcs/main.c ./srcs/map.c \
	   ./srcs/mlx_utils.c ./srcs/parse.c \
	   ./srcs/parse_fc.c ./srcs/parse_map.c \
	   ./srcs/parse_tex.c ./srcs/parse_utils.c \
	   ./srcs/parse_utils2.c ./srcs/player.c \
	   ./srcs/raycasting.c ./srcs/raycasting2.c \
	   ./srcs/raycasting_utils.c ./srcs/string_utils.c \
	   ./srcs/textures.c ./srcs/utils.c ./srcs/wall.c
OBJS = $(SRCS:.c=.o)
BONUS = ./bonus/gnl_bonus.c ./bonus/gnl_utils_bonus.c \
		./bonus/graphics_bonus.c ./bonus/key_handling_bonus.c \
		./bonus/main_bonus.c ./bonus/map_bonus.c \
		./bonus/mlx_utils_bonus.c ./bonus/parse_bonus.c \
		./bonus/parse_fc_bonus.c ./bonus/parse_map_bonus.c \
		./bonus/parse_tex_bonus.c ./bonus/parse_utils2_bonus.c \
		./bonus/parse_utils_bonus.c ./bonus/player_bonus.c \
		./bonus/raycasting2_bonus.c ./bonus/raycasting_bonus.c \
		./bonus/raycasting_utils_bonus.c ./bonus/sprite_bonus.c \
		./bonus/sprite_utils_bonus.c ./bonus/string_utils_bonus.c \
		./bonus/textures_bonus.c ./bonus/utils_bonus.c \
		./bonus/wall_bonus.c
BONUS_OBJS = $(BONUS:.c=.o)
MLX = ./mlx/
RM = rm -f
PATH_TO_LIB = install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(NAME)

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(MLX)
	$(CC) $(OBJS) $(CFLAGS) $(LIB_MLX) $(FRAMEWORK) -I./include/cub3d.h -o $(NAME)
	$(PATH_TO_LIB)

bonus : $(BONUS_OBJS)
	make all -C $(MLX)
	$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIB_MLX) $(FRAMEWORK) -I./include/cub3d_bonus.h -o $(NAME)
	$(PATH_TO_LIB)

clean :
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean : clean
	make clean -C $(MLX)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

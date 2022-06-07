# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 23:30:36 by kyumlee           #+#    #+#              #
#    Updated: 2021/06/14 16:44:43 by kyumlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= ./srcs/main.c ./srcs/utils.c ./srcs/check.c \
			  ./srcs/lst_func.c ./srcs/parse.c \
			  ./srcs/swap.c ./srcs/push.c ./srcs/rotate.c \
			  ./srcs/case_small.c ./srcs/case_big.c \
			  ./srcs/a_2_b.c ./srcs/b_2_a.c
OBJS		= $(SRCS:.c=.o)
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -I./includes/push_swap.h -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

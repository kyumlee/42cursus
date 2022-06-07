# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/17 22:44:00 by kyumlee           #+#    #+#              #
#    Updated: 2021/07/19 21:09:41 by kyumlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= ./srcs/main.c ./srcs/utils.c ./srcs/ft_split.c ./srcs/get_cmd_path.c
OBJS	= $(SRCS:.c=.o)
INCL	= -I./includes/pipex.h
OUTFILE	= outfile
RM		= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(OUTFILE)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

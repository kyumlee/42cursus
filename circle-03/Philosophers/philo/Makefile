NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -pthread
SRCS	= ./srcs/atoi.c ./srcs/init.c ./srcs/main.c ./srcs/time.c ./srcs/utils.c \
		  ./srcs/run.c ./srcs/actions.c
OBJS	= $(SRCS:.c=.o)
INCL	= -I./philo.h
RM		= rm -f

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCL) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re

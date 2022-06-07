NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_printf_ntoa.c ft_printf_padding.c ft_printf_precision.c ft_printf_print.c ft_printf_specifiers.c ft_printf_struct.c ft_printf_utils.c ft_printf_bonus.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft
LIBFT_LIB = libft.a
RM = rm -f
LIBC = ar rc

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

bonus : all

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re


#ifndef __MICRO_PAINT_H__
# define __MICRO_PAINT_H__

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define ARG_ERR	1
# define FILE_ERR	2

typedef struct	{
	int		w;
	int		h;
	char	ch;
	char	**img;
}			t_bg;

int			ft_strlen(char *s);
int			ft_putstr_fd(int fd, char *s);
int			ft_putendl_fd(int fd, char *s);
int			ft_error(int no);
int			free_return(char **img, int j);

int			init_bg(FILE *fp, t_bg *bg);

#endif

#ifndef __MINI_PAINT_H__
# define __MINI_PAINT_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define ARG_ERR	1
# define FILE_ERR	2

// fopen fread fscanf fclose write
// malloc calloc realloc free
// memset
// powf sqrt

typedef struct	s_all {
	int		z_w;
	int		z_h;
	char	z_bg;
	char	r;
	float	r_x;
	float	r_y;
	float	r_w;
	float	r_h;
	char	r_bg;
	char	**img;
}			t_all;

int			ft_strlen(char *s);
int			ft_putstr_fd(int fd, char *s);
int			ft_putendl_fd(int fd, char *s);
int			ft_error(int no);

int			init_all(char *filename, FILE *fp, t_all *all);
void		fill(t_all *all);

#endif

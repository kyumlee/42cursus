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

typedef struct	s_info {
	int			w;
	int			h;
	char		ch;

	char		type;
	float		x;
	float		y;
	float		r;
	char		c_ch;

	char		**rect;
}				t_info;

int				ft_strlen(char *s);
int				ft_putstr_fd(int fd, char *s);
int				ft_putendl_fd(int fd, char *s);
int				ft_error(int no);

float			distance(float Xa, float Ya, float Xb, float Yb);

int				init_info(FILE *fp, t_info *info);
int				fill_circles(FILE *fp, t_info *info);

int				draw(char **rect);

#endif

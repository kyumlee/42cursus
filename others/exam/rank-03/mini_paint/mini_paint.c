#include "./mini_paint.h"

int		ft_strlen(char *s) {
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putstr_fd(int fd, char *s) {
	write(fd, s, ft_strlen(s));
	return (0);
}

int		ft_putendl_fd(int fd, char *s) {
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\n");
	return (0);
}

int		ft_error(int no) {
	ft_putstr_fd(1, "Error: ");
	if (no == ARG_ERR)
		ft_putendl_fd(1, "argument");
	else if (no == FILE_ERR)
		ft_putendl_fd(1, "Operation file corrupted");
	return (1);
}

int		free_rect(char **rect, int i) {
	for (int a = 0; a < i; a++)
		free(rect[i]);
	free(rect);
	return (1);
}

float	distance(float Xa, float Ya, float Xb, float Yb) {
	return (sqrt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb)));
}

int		init_info(FILE *fp, t_info *info) {
	if (fscanf(fp, "%d %d %c\n", &info->w, &info->h, &info->ch) != 3)
		return (1);

	if (info->w > 300 || info->w < 1)
		return (1);
	if (info->h > 300 || info->w < 1)
		return (1);

	info->rect = malloc(sizeof(char **) * (info->h + 1));
	if (!info->rect)
		return (1);
	for (int i = 0; i < info->h; i++) {
		info->rect[i] = malloc(sizeof(char *) * (info->w + 1));
		if (!info->rect[i])
			return (free_rect(info->rect, i));
	}

	for (int i = 0; i < info->h; i++) {
		for (int j = 0; j < info->w; j++) {
			info->rect[i][j] = info->ch;
		}
		info->rect[i][info->w] = 0;
	}
	info->rect[info->h] = 0;

	return (0);
}

int		fill_circles(FILE *fp, t_info *info) {
	while (fscanf(fp, "%c %f %f %f %c\n", &info->type, &info->x, &info->y, &info->r, &info->c_ch) == 5) {
		if (info->type != 'c' && info->type != 'C')
			return (free_rect(info->rect, info->w));
		if (info->r <= 0.0)
			return (free_rect(info->rect, info->w));

		for (int i = 0; i < info->h; i++) {
			for (int j = 0; j < info->w; j++) {
				float	dist = distance(j, i, info->x, info->y) - info->r;
				if (dist <= 0.0) {
					info->rect[i][j] = info->c_ch;
					if (dist <= -1.0 && info->type == 'c')
						info->rect[i][j] = info->ch;
				}
			}
		}
	}
	return (0);
}

int		draw(char **rect) {
	int	i = 0;

	while (rect[i]) {
		ft_putendl_fd(1, rect[i]);
		i++;
	}

	return (0);
}

int		main (int argc, char **argv) {
	if (argc != 2)
		return (ft_error(ARG_ERR));

	FILE	*fp = fopen(argv[1], "r");
	if (fp == NULL)
		return (ft_error(FILE_ERR));

	t_info	info;
	if (init_info(fp, &info))
		return (ft_error(FILE_ERR));

	if (fill_circles(fp, &info))
	{
		// fix memory leak
		system("leaks a.out");
		return (ft_error(FILE_ERR));
	}

	draw(info.rect);

	system("leaks a.out");

	return (0);
}

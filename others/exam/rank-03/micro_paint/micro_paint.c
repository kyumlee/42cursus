#include "./micro_paint.h"

int	ft_strlen(char *s) {
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(int fd, char *s) {
	write(fd, s, ft_strlen(s));
	return (1);
}

int	ft_putendl_fd(int fd, char *s) {
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\n");
	return (1);
}

int	ft_error(int err) {
	ft_putstr_fd(1, "Error: ");
	if (err == ARG_ERR)
		return (ft_putendl_fd(1, "argument"));
	return (ft_putendl_fd(1, "Operation file corrupted"));
}

int	free_return(char **img, int j) {
	for (int i = 0; i < j; i++)
		free(img[i]);
	free(img);

	return (1);
}

int	init_bg(FILE *fp, t_bg *bg) {
	if (fscanf(fp, "%d %d %c\n", &bg->w, &bg->h, &bg->ch) != 3)
		return (1);

	if (bg->w > 300 || bg->w < 1 || bg->h > 300 || bg->h < 1)
		return (1);

	bg->img = malloc(sizeof(char *) * bg->h);
	if (!bg->img)
		return (1);
	for (int i = 0; i < bg->h; i++) {
		bg->img[i] = malloc(sizeof(char) * bg->w);
		if (!bg->img[i])
			return (free_return(bg->img, i));
	}

	for (int i = 0; i < bg->h; i++) {
		for (int j = 0; j < bg->w; j++) {
			bg->img[i][j] = bg->ch;
		}
	}
	return (0);
}

int	is_in_rectangle(float Xa, float Ya, float Xtl, float Ytl, float Xbr, float Ybr) {
	if (Xtl <= Xa && Xa <= Xbr && Ytl <= Ya && Ya <= Ybr) {
		if (Xa - Xtl < 1 || Xbr - Xa < 1 || Ya - Ytl < 1 || Ybr - Ya < 1)
			return (1);
		return (2);
	}
	return (0);
}

int	draw_rectangles(FILE *fp, t_bg *bg) {
	char	type, ch;
	float	x, y, w, h;
	size_t	fs = fscanf(fp, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h, &ch);
	
	if (fs != 6)
		return (free_return(bg->img, bg->h));

	while (fs == 6) {
		if ((type != 'r' && type != 'R') || (w <= 0.0 || h <= 0.0))
			return (free_return(bg->img, bg->h));

		for (int i = 0; i < bg->h; i++) {
			for (int j = 0; j < bg->w; j++) {
				int	iir = is_in_rectangle(j, i, x, y, x + w, y + h);
				if ((iir == 2 && type == 'R') || iir == 1)
					bg->img[i][j] = ch;
			}
		}
		fs = fscanf(fp, "%c %f %f %f %f %c\n", &type, &x, &y, &w, &h, &ch);
	}
	return (0);
}

void	draw(t_bg bg) {
	for (int i = 0; i < bg.h; i++) {
		for (int j = 0; j < bg.w; j++)
			write(1, &bg.img[i][j], 1);
		ft_putendl_fd(1, "");
	}
}

int	main(int argc, char **argv) {
	if (argc != 2)
		return (ft_error(ARG_ERR));

	FILE	*fp = fopen(argv[1], "r");
	if (!fp)
		return (ft_error(FILE_ERR));

	t_bg	bg;
	if (init_bg(fp, &bg))
		return (ft_error(FILE_ERR));

	if (draw_rectangles(fp, &bg))
		return (ft_error(FILE_ERR));

	draw(bg);

	free_return(bg.img, bg.h);

	return (0);
}

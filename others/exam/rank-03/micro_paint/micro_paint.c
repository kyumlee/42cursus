#include "./micro_paint.h"

// TODO
// 1. math functions
// 2. if char is non-printable character

int	ft_strlen(char *s) {
	int	i = 0;

	if (!s || !s[0])
		return (i);
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

int	init_all(char *filename, FILE *fp, t_all *all) {
	if (!(fp = fopen(filename, "r"))) return (1);
	if (fscanf(fp, "%d %d %c\n", &all->z_w, &all->z_h, &all->z_bg) != 3) return (1);
	if (fscanf(fp, "%c %f %f %f %f %c", &all->r, &all->r_x, &all->r_y, &all->r_w, &all->r_h, &all->r_bg) != 6) return (1);
	if (all->z_w <= 0 || all->z_w > 300 || all->z_h <= 0 || all->z_h > 300) return (1);
	if (all->r_w == 0.0 || all->r_h == 0.0) return (1);
	if (all->r_x >= all->z_w || all->r_y >= all->z_h) return (1);

	all->img = (char **)malloc(sizeof(char *) * all->z_h + 1);
	for (int i = 0; i < all->z_h; i++)
		all->img[i] = (char *)malloc(sizeof(char) * all->z_w + 1);

	fclose(fp);
	return (0);
}

void	fill(t_all *all) {
	for (int i = 0; i < all->z_h; i++) {
		for (int j = 0; j < all->z_w; j++)
			all->img[i][j] = all->z_bg;
		all->img[i][all->z_w] = '\0';
	}

	int	r_x = all->r_x;
	int	r_y = all->r_y;
	int	r_w = (all->r_x + all->r_w >= all->z_w) ? all->z_w : all->r_x + all->r_w;
	int	r_h = (all->r_y + all->r_h >= all->z_h) ? all->z_h : all->r_y + all->r_h;

	for (int i = r_y; i < r_h; i++) {
		all->img[i][r_x] = all->r_bg;
		all->img[i][r_w - 1] = all->r_bg;
	}
	for (int j = r_x; j < r_w; j++) {
		all->img[r_y][j] = all->r_bg;
		all->img[r_h - 1][j] = all->r_bg;
	}

	for (int i = r_y + 1; i < r_h - 1; i++) {
		for (int j = r_x + 1; j < r_w - 1; j++) {
			if (all->r == 'r')
				all->img[i][j] = ' ';
			else
				all->img[i][j] = all->r_bg;
		}
	}
}

int	main(int argc, char **argv) {
	FILE	*fp = NULL;
	t_all	all;

	if (argc != 2)
		return (ft_error(ARG_ERR));

	if (init_all(argv[1], fp, &all))
		return (ft_error(FILE_ERR));

	fill(&all);

	for (int i = 0; all.img[i]; i++)
		ft_putendl_fd(0, all.img[i]);

	for (int i = 0; i < all.z_h; i++)
		free(all.img[i]);
	free(all.img);
	return (0);
}

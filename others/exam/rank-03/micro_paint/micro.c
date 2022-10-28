#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define ARG_ERROR 1
#define FILE_ERROR 2

typedef struct {
	int w, h;
	char c;
	char **zone;
}	bg;

typedef struct {
	char r, c;
	float x, y, w, h;
}	rect;

int ft_strlen(char *s) {
	int i = 0;

	while(s[i])
		i++;

	return (i);
}

void	ft_putstr_fd(int fd, char *s) {
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(int fd, char *s) {
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\n");
}

int	return_error(int err) {
	ft_putstr_fd(1, "Error: ");
	if (err == ARG_ERROR)
		ft_putendl_fd(1, "argument");
	else if (err == FILE_ERROR)
		ft_putendl_fd(1, "Operation file corrupted");

	return (1);
}

int	free_till(char **rect, int j) {
	for (int i = 0; i < j; i++)
		free(rect[i]);
	free(rect);
	return (1);
}

int init_bg(FILE *fp, bg *bg) {
	int size = fscanf(fp, "%d %d %c\n", &bg->w, &bg->h, &bg->c);

	if (size != 3)
		return (1);
	if (bg->w	< 1 || bg->w > 300 || bg->h < 1 || bg->h > 300)
		return (1);

	char	**temp = malloc(sizeof(char *) * (bg->h + 1));
	if (!temp)
		return (free_till(temp, 0));
	for (int i = 0; i < bg->h; i++) {
		temp[i] = malloc(sizeof(char) * (bg->w + 1));
		if (!temp[i])
			return (free_till(temp, i));
	}
	bg->zone = temp;

	for (int i = 0; i < bg->h; i++) {
		for (int j = 0; j < bg->w; j++)
			bg->zone[i][j] = bg->c;
		bg->zone[i][bg->w] = 0;
	}
	bg->zone[bg->h] = 0;
	return (0);
}

int is_in_rect(rect *rect, int x, int y) {
	if (x < rect->x || rect->x + rect->w < x || y < rect->y || rect->y + rect->h < y)
		return (0);
	if (x - rect->x < 1 || rect->x + rect->w - x < 1 || y - rect->y < 1 || rect->y + rect->h - y < 1)
		return (1);
	return (2);
}

void draw_rect(bg *bg, rect *rect) {
	for (int i = 0; i < bg->h; i++) {
		for (int j = 0; j < bg->w; j++) {
			int distance = is_in_rect(rect, j, i);
			if (distance == 1 || (distance == 2 && rect->r == 'R'))
				bg->zone[i][j] = rect->c;
		}
	}
}

int draw(FILE *fp, bg *bg, rect *rect) {
	int size = fscanf(fp, "%c %f %f %f %f %c\n", &rect->r, &rect->x, &rect->y, &rect->w, &rect->h, &rect->c);
	while (size == 6) {
		if ((rect->r != 'r' && rect->r != 'R') || rect->w <= 0 || rect->h <= 0)
			return (1);
		draw_rect(bg, rect);
		size = fscanf(fp, "%c %f %f %f %f %c\n", &rect->r, &rect->x, &rect->y, &rect->w, &rect->h, &rect->c);
	}
	if (size == -1) {
		for (int i = 0; i < bg->h; i++)
			ft_putendl_fd(1, bg->zone[i]);
		return (0);
	}
	free_till(bg->zone, bg->h);
	return (1);
}

int	main(int argc, char **argv) {
	if (argc != 2)
		return (return_error(ARG_ERROR));

	bg		bg;
	rect	rect;

	memset(&bg, 0, sizeof(bg));
	memset(&rect, 0, sizeof(rect));

	FILE	*fp = fopen(argv[1], "r");
	if (!fp)
		return (return_error(FILE_ERROR));

	if (init_bg(fp, &bg))
		return (return_error(FILE_ERROR));

	if (draw(fp, &bg, &rect))
		return (return_error(FILE_ERROR));

	free_till(bg.zone, bg.h);

	return (0);
}

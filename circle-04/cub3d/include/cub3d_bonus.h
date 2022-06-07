/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:03:54 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:30:53 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <math.h>
# include <fcntl.h>
# include <float.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include "../mlx/mlx.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 1280
# define HEIGHT 720
# define MINIMAP_SCALE 0.25
# define EPSILON 0.2

typedef struct		s_check_id {
	char			f;
	char			c;
	char			no;
	char			so;
	char			we;
	char			ea;
	char			s;
}					t_check_id;

typedef struct		s_map {
	unsigned int	cols;
	unsigned int	rows;
	char			*joined_line;
	char			**grid;
}					t_map;

typedef struct		s_img {
	void			*img;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct		s_mlx {
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_player {
	double			x;
	double			y;
	double			size;
	char			start;
	int				turn_direction;
	int				walk_fb;
	int				walk_rl;
	double			rotation_angle;
	double			walk_speed;
	double			turn_speed;
	int				check;
}					t_player;

typedef struct		s_point {
	double			x;
	double			y;
}					t_point;

typedef struct		s_ray {
	double			angle;
	double			distance;
	t_point			wall_hit;
	char			was_hit_vert;
}					t_ray;

typedef struct		s_texture {
	char			*path;
	t_img			img;
}					t_texture;

typedef struct		s_wall {
	double			perp_distance;
	double			height;
	int				strip_height;
	int				ceiling;
	int				floor;
}					t_wall;

typedef struct		s_sprite {
	double			x;
	double			y;
	int				visible;
	double			angle;
	double			distance;
	double			perp_distance;
	double			size;
	double			top;
	double			bottom;
	double			pos_x;
	double			left;
	double			right;
}					t_sprite;

typedef struct		s_all {
	t_texture		textures[5];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_map			map;
	double			tile;
	double			dist_proj_plane;
	double			fov;
	t_mlx			mlx;
	t_img			img;
	t_player		player;
	t_ray			*rays;
	int				sprite_count;
	t_sprite		*sprites;
}					t_all;

typedef uint32_t	t_color;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				set_point(t_point *point, double x, double y);
void				draw_pixel(t_all *all, int x, int y, t_color color);
t_color				select_pixel(t_img *img, int x, int y);
void				draw_line(t_all *all, t_point p1, t_point p2, t_color c);
void				draw_rectangle(t_all *all, int x, int y, t_color color);
int					quit_program(t_all *all);
int					key_press(int keycode, t_all *all);
int					key_release(int keycode, t_all *all);
void				render_map(t_all *all);
int					is_inside_map(double x, double y);
int					map_has_wall_at(t_all *all, double x, double y);
void				set_mlx(t_all *all, char *title);
void				set_img(t_all *all);
void				clear_img(t_all *all);
int					parse(t_all *all, char *s);
int					parse_f_c(t_all *all, char *s, t_check_id *check);
int					join_map_lines(t_all *all, char *s);
void				parse_map(t_map *map);
int					parse_textures(t_all *all, char *s, t_check_id *check);
void				reset_map(t_map *map);
void				check_map(t_map *map);
void				fill_map(t_map *map);
int					is_t_id(char *s);
int					check_start(char *s);
int					is_map_content(char c);
int					check_if_map(char *s);
void				get_map_cols(t_map *map, int *cols, int rows);
void				set_player(t_all *all);
void				move_player(t_all *all);
void				render_player(t_all *all);
void				adjust_point(t_point *point);
t_point				get_h_hit(t_all *all, t_ray *ray, double angle);
t_point				get_v_hit(t_all *all, t_ray *ray, double angle);
double				normalize_angle(double angle);
void				cast_all_rays(t_all *all);
void				render_rays(t_all *all);
void				set_rays(t_all *all);
int					is_ray_facing_down(double angle);
int					is_ray_facing_up(double angle);
int					is_ray_facing_right(double angle);
int					is_ray_facing_left(double angle);
void				render_sprite_projection(t_all *all);
void				count_sprites(t_all *all, t_map *map);
void				set_sprites(t_all *all);
void				get_sprites_location(t_all *all);
double				find_angle(t_player player, t_sprite *sprite);
void				sort_sprites(t_sprite *sprite, int count);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
void				load_textures(t_all *all);
int					select_texture(t_ray *ray);
void				render_wall_projection(t_all *all);
void				ft_error(char *str);
int					check_filename(char *s);
int					ft_isspace(char c);
int					skip_space(char *s);
void				set_all_rest(t_all *all);

#endif

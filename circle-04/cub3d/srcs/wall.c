/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:29:25 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:55:19 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_wall(t_all *all, t_wall *wall, int x)
{
	wall->perp_distance = all->rays[x].distance
		* cos(all->rays[x].angle - all->player.rotation_angle);
	wall->height = (all->tile / wall->perp_distance) * all->dist_proj_plane;
	wall->strip_height = wall->height;
	wall->ceiling = (HEIGHT / 2) - (wall->strip_height / 2);
	if (wall->ceiling < 0)
		wall->ceiling = 0;
	wall->floor = (HEIGHT / 2) + (wall->strip_height / 2);
	if (wall->floor > HEIGHT)
		wall->floor = HEIGHT - 1;
}

void	draw_textures(t_all *all, int x, int y, t_wall wall)
{
	t_point	tex_pos;
	int		distance_from_top;
	t_color	color;
	int		i;

	i = select_texture(&all->rays[x]);
	if (all->rays[x].was_hit_vert)
		tex_pos.x = (int)all->rays[x].wall_hit.y % (int)all->tile;
	else
		tex_pos.x = (int)all->rays[x].wall_hit.x % (int)all->tile;
	distance_from_top = y + (wall.strip_height / 2) - (HEIGHT / 2);
	tex_pos.y = distance_from_top
		* ((double)all->textures[i].img.height / wall.strip_height);
	color = select_pixel(&all->textures[i].img, tex_pos.x, tex_pos.y);
	draw_pixel(all, x, y, color);
}

void	render_wall_projection(t_all *all)
{
	int		x;
	int		y;
	t_wall	wall;

	x = 0;
	while (x < WIDTH)
	{
		set_wall(all, &wall, x);
		y = -1;
		while (++y < wall.ceiling)
			draw_pixel(all, x, y, all->ceiling_color);
		y = wall.ceiling - 1;
		while (++y < wall.floor)
			draw_textures(all, x, y, wall);
		y = wall.floor;
		while (++y < HEIGHT)
			draw_pixel(all, x, y, all->floor_color);
		x++;
	}
}

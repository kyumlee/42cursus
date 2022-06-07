/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 02:14:09 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 17:38:49 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

t_sprite	*g_visible;

void	init_info(t_all *all, int count)
{
	int			i;
	double		angle;
	t_sprite	*sprite;

	i = -1;
	while (++i < count)
	{
		sprite = &g_visible[i];
		sprite->perp_distance = sprite->distance * cos(sprite->angle);
		sprite->size = all->tile / sprite->perp_distance * all->dist_proj_plane;
		sprite->top = (HEIGHT / 2) - (sprite->size / 2);
		sprite->bottom = (HEIGHT / 2) + (sprite->size / 2);
		if (sprite->top < 0)
			sprite->top = 0;
		if (sprite->bottom >= HEIGHT)
			sprite->bottom = HEIGHT - 1;
		angle = atan2(sprite->y - all->player.y, sprite->x - all->player.x)
			- all->player.rotation_angle;
		sprite->pos_x = tan(angle) * all->dist_proj_plane;
		sprite->left = (WIDTH / 2) + sprite->pos_x - (sprite->size / 2);
		sprite->right = sprite->left + sprite->size;
	}
}

int		find_visible(t_all *all, t_player player)
{
	int			i;
	int			count;
	double		angle;

	g_visible = malloc(sizeof(t_sprite) * all->sprite_count);
	if (!g_visible)
		ft_error("Memory allocation failed");
	i = -1;
	count = 0;
	get_sprites_location(all);
	while (++i < all->sprite_count)
	{
		angle = find_angle(player, &all->sprites[i]);
		if (angle < (all->fov / 2) + EPSILON)
		{
			all->sprites[i].visible = 1;
			all->sprites[i].angle = angle;
			all->sprites[i].distance = hypot(
					all->sprites[i].y - player.y, all->sprites[i].x - player.x);
			g_visible[count++] = all->sprites[i];
		}
	}
	init_info(all, count);
	sort_sprites(g_visible, count);
	return (count);
}

t_color	select_texture_pixel(t_all *all, t_sprite *sprite, int x, int y)
{
	double	texel_width;
	int		distance_from_top;
	int		tex_offset_x;
	int		tex_offset_y;

	texel_width = all->textures[4].img.width / sprite->size;
	tex_offset_x = (x - sprite->left) * texel_width;
	distance_from_top = y + (sprite->size / 2) - (HEIGHT / 2);
	tex_offset_y = distance_from_top
		* (all->textures[4].img.height / sprite->size);
	return (select_pixel(&all->textures[4].img, tex_offset_x, tex_offset_y));
}

void	render_sprite_projection(t_all *all)
{
	int		i;
	int		x;
	int		y;
	int		count;

	count = find_visible(all, all->player);
	i = -1;
	while (++i < count)
	{
		x = g_visible[i].left - 1;
		while (++x < g_visible[i].right)
		{
			y = g_visible[i].top - 1;
			while (++y < g_visible[i].bottom)
			{
				if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
					if (select_texture_pixel(all, &g_visible[i], x, y)
						&& g_visible[i].distance < all->rays[x].distance)
						draw_pixel(all, x, y,
							select_texture_pixel(all, &g_visible[i], x, y));
			}
		}
	}
	free(g_visible);
}

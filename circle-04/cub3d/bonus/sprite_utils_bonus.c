/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:38:36 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 17:54:58 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	count_sprites(t_all *all, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	all->sprite_count = 0;
	while (i < (int)map->rows)
	{
		j = 0;
		while (j < (int)map->cols)
		{
			if (map->grid[i][j] == '2')
				all->sprite_count++;
			j++;
		}
		i++;
	}
}

void	set_sprites(t_all *all)
{
	int	i;

	all->sprites = malloc(sizeof(t_sprite) * all->sprite_count);
	if (!all->sprites)
		return ;
	i = 0;
	while (i < all->sprite_count)
	{
		all->sprites[i].x = 0;
		all->sprites[i].y = 0;
		all->sprites[i].visible = 0;
		all->sprites[i].angle = 0;
		all->sprites[i].distance = 0;
		all->sprites[i].perp_distance = 0;
		all->sprites[i].size = 0;
		all->sprites[i].top = 0;
		all->sprites[i].bottom = 0;
		all->sprites[i].pos_x = 0;
		all->sprites[i].left = 0;
		all->sprites[i].right = 0;
		i++;
	}
}

void	get_sprites_location(t_all *all)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < (int)all->map.rows)
	{
		j = 0;
		while (j < (int)all->map.cols)
		{
			if (all->map.grid[i][j] == '2')
			{
				all->sprites[k].x = (j * all->tile) + (all->tile / 2);
				all->sprites[k].y = (i * all->tile) + (all->tile / 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

double	find_angle(t_player player, t_sprite *sprite)
{
	double	angle;

	angle = player.rotation_angle
		- atan2(sprite->y - player.y, sprite->x - player.x);
	if (angle > M_PI)
		angle -= M_PI * 2;
	if (angle < -M_PI)
		angle += M_PI * 2;
	angle = fabs(angle);
	return (angle);
}

void	sort_sprites(t_sprite *sprites, int count)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = -1;
	while (++i < count - 1)
	{
		j = i;
		while (++j < count)
		{
			if (sprites[i].distance < sprites[j].distance)
			{
				temp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = temp;
			}
		}
	}
}

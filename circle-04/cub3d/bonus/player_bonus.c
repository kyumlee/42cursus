/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:14:23 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:22:35 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	get_player_location(t_all *all, t_player *player)
{
	int		i;
	int		j;
	char	pos;

	i = 0;
	while (i < (int)all->map.rows)
	{
		j = 0;
		while (j < (int)all->map.cols)
		{
			pos = all->map.grid[i][j];
			if (pos == 'N' || pos == 'S' || pos == 'W' || pos == 'E')
			{
				player->x = j * all->tile + (all->tile / 2 - player->size / 2);
				player->y = i * all->tile + (all->tile / 2 - player->size / 2);
				player->start = pos;
				player->check++;
			}
			j++;
		}
		i++;
	}
}

void	set_player(t_all *all)
{
	all->player.size = 5;
	all->player.check = 0;
	get_player_location(all, &all->player);
	if (all->player.check != 1)
		ft_error("Wrong number of player in the map");
	all->player.walk_fb = 0;
	all->player.walk_rl = 0;
	all->player.turn_direction = 0;
	if (all->player.start == 'N')
		all->player.rotation_angle = M_PI * 1.5;
	if (all->player.start == 'S')
		all->player.rotation_angle = M_PI / 2;
	if (all->player.start == 'W')
		all->player.rotation_angle = M_PI;
	if (all->player.start == 'E')
		all->player.rotation_angle = M_PI * 2;
	all->player.walk_speed = 5;
	all->player.turn_speed = 5 * (M_PI / 180);
}

void	move_player(t_all *all)
{
	t_point		new_pos;
	t_player	*player;
	double		move_step;
	double		angle;

	player = &all->player;
	player->rotation_angle += player->turn_direction * player->turn_speed;
	player->rotation_angle = normalize_angle(player->rotation_angle);
	move_step = player->walk_fb * player->walk_speed;
	if (!player->walk_rl)
		angle = player->rotation_angle;
	else
		angle = player->rotation_angle + (player->walk_rl * M_PI * 0.5);
	angle = normalize_angle(angle);
	new_pos.x = player->x + cos(angle) * move_step;
	new_pos.y = player->y + sin(angle) * move_step;
	if (!map_has_wall_at(all, new_pos.x, new_pos.y))
	{
		player->x = new_pos.x;
		player->y = new_pos.y;
	}
}

void	render_player(t_all *all)
{
	int	i;
	int	i2;
	int	j;
	int	j2;

	i = all->player.x * MINIMAP_SCALE;
	i2 = i;
	while (i < i2 + (all->player.size * MINIMAP_SCALE))
	{
		j = all->player.y * MINIMAP_SCALE;
		j2 = j;
		while (j < j2 + (all->player.size * MINIMAP_SCALE))
		{
			draw_pixel(all, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}

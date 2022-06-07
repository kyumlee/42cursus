/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:46:12 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:44:57 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	quit_program(t_all *all)
{
	mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	exit(0);
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		quit_program(all);
	if (keycode == KEY_W)
		all->player.walk_fb = +1;
	if (keycode == KEY_S)
		all->player.walk_fb = -1;
	if (keycode == KEY_D)
	{
		all->player.walk_rl = +1;
		all->player.walk_fb = +1;
	}
	if (keycode == KEY_A)
	{
		all->player.walk_rl = -1;
		all->player.walk_fb = +1;
	}
	if (keycode == KEY_RIGHT)
		all->player.turn_direction = +1;
	if (keycode == KEY_LEFT)
		all->player.turn_direction = -1;
	return (1);
}

int	key_release(int keycode, t_all *all)
{
	if (keycode == KEY_W)
		all->player.walk_fb = 0;
	if (keycode == KEY_S)
		all->player.walk_fb = 0;
	if (keycode == KEY_A)
	{
		all->player.walk_rl = 0;
		all->player.walk_fb = 0;
	}
	if (keycode == KEY_D)
	{
		all->player.walk_rl = 0;
		all->player.walk_fb = 0;
	}
	if (keycode == KEY_RIGHT)
		all->player.turn_direction = 0;
	if (keycode == KEY_LEFT)
		all->player.turn_direction = 0;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:53:09 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 17:38:43 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	set_rays(t_all *all)
{
	int	i;

	all->rays = malloc(sizeof(t_ray) * WIDTH);
	if (!all->rays)
		return ;
	i = 0;
	while (i < WIDTH)
	{
		all->rays[i].angle = 0;
		all->rays[i].distance = 0;
		set_point(&all->rays[i].wall_hit, 0, 0);
		all->rays[i].was_hit_vert = 0;
		i++;
	}
}

int		is_ray_facing_down(double angle)
{
	return (angle > 0 && angle < M_PI);
}

int		is_ray_facing_up(double angle)
{
	return (!is_ray_facing_down(angle));
}

int		is_ray_facing_right(double angle)
{
	return (angle < 0.5 * M_PI || angle > 1.5 * M_PI);
}

int		is_ray_facing_left(double angle)
{
	return (!is_ray_facing_right(angle));
}

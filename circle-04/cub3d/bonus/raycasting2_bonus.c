/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:45:10 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:27:32 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	adjust_point(t_point *p)
{
	if (p->x < 0)
		p->x = 0;
	if (p->y < 0)
		p->y = 0;
	if (p->x >= WIDTH)
		p->x = WIDTH - 1;
	if (p->y >= HEIGHT)
		p->y = HEIGHT - 1;
}

t_point	check_h_hit(t_all *all, t_ray *ray, t_point intercept, t_point step)
{
	t_point	next;
	t_point	check;

	next = intercept;
	while (is_inside_map(next.x, next.y))
	{
		check = next;
		if (is_ray_facing_up(ray->angle))
			check.y += -1;
		if (map_has_wall_at(all, check.x, check.y) == 1)
			return (next);
		next.x += step.x;
		next.y += step.y;
	}
	adjust_point(&next);
	return (next);
}

t_point	check_v_hit(t_all *all, t_ray *ray, t_point intercept, t_point step)
{
	t_point	next;
	t_point	check;

	next = intercept;
	while (is_inside_map(next.x, next.y))
	{
		check = next;
		if (is_ray_facing_left(ray->angle))
			check.x += -1;
		if (map_has_wall_at(all, check.x, check.y) == 1)
			return (next);
		next.x += step.x;
		next.y += step.y;
	}
	adjust_point(&next);
	return (next);
}

t_point	get_h_hit(t_all *all, t_ray *ray, double angle)
{
	t_point	intercept;
	t_point	step;

	intercept.y = floor(all->player.y / all->tile) * all->tile;
	if (is_ray_facing_down(angle))
		intercept.y += all->tile;
	intercept.x = all->player.x + (intercept.y - all->player.y) / tan(angle);
	step.y = all->tile;
	if (is_ray_facing_up(angle))
		step.y *= -1;
	step.x = all->tile / tan(angle);
	if ((is_ray_facing_left(angle) && step.x > 0)
		|| (is_ray_facing_right(angle) && step.x < 0))
		step.x *= -1;
	return (check_h_hit(all, ray, intercept, step));
}

t_point	get_v_hit(t_all *all, t_ray *ray, double angle)
{
	t_point	intercept;
	t_point	step;

	intercept.x = floor(all->player.x / all->tile) * all->tile;
	if (is_ray_facing_right(angle))
		intercept.x += all->tile;
	intercept.y = all->player.y + (intercept.x - all->player.x) * tan(angle);
	step.x = all->tile;
	if (is_ray_facing_left(angle))
		step.x *= -1;
	step.y = all->tile * tan(angle);
	if ((is_ray_facing_up(angle) && step.y > 0)
		|| (is_ray_facing_down(angle) && step.y < 0))
		step.y *= -1;
	return (check_v_hit(all, ray, intercept, step));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:28:27 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:28:15 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

double	get_ray_distance(t_all *all, t_ray *ray, t_point h_hit, t_point v_hit)
{
	double	h_distance;
	double	v_distance;

	h_distance = hypot(h_hit.x - all->player.x, h_hit.y - all->player.y);
	v_distance = hypot(v_hit.x - all->player.x, v_hit.y - all->player.y);
	if (h_distance < v_distance)
	{
		ray->wall_hit = h_hit;
		ray->was_hit_vert = 0;
		return (h_distance);
	}
	else
	{
		ray->wall_hit = v_hit;
		ray->was_hit_vert = 1;
		return (v_distance);
	}
}

void	cast_ray(t_all *all, t_ray *ray, double angle)
{
	t_point	h_hit;
	t_point	v_hit;

	h_hit = get_h_hit(all, ray, angle);
	v_hit = get_v_hit(all, ray, angle);
	ray->distance = get_ray_distance(all, ray, h_hit, v_hit);
}

void	cast_all_rays(t_all *all)
{
	double	angle;
	int		i;

	angle = all->player.rotation_angle - (all->fov / 2);
	i = 0;
	while (i < WIDTH)
	{
		all->rays[i].angle = normalize_angle(angle);
		cast_ray(all, &all->rays[i], all->rays[i].angle);
		angle += (all->fov / WIDTH);
		i++;
	}
}

void	render_rays(t_all *all)
{
	int		i;
	t_point	p1;
	t_point	p2;

	i = 0;
	while (i < WIDTH)
	{
		set_point(&p1,
			all->player.x + (all->player.size / 2),
			all->player.y + (all->player.size / 2));
		set_point(&p2,
			all->rays[i].wall_hit.x,
			all->rays[i].wall_hit.y);
		draw_line(all, p1, p2, 0x00FF0000);
		i++;
	}
}

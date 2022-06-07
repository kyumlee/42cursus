/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:03:59 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:28:02 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	set_point(t_point *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

void	draw_pixel(t_all *all, int x, int y, t_color color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = all->img.data + (y * all->img.size_l) + (x * (all->img.bpp / 8));
		*(t_color *)dst = color;
	}
}

t_color	select_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->data + (y * img->size_l) + (x * (img->bpp / 8));
	return (*(t_color *)dst);
}

void	draw_line(t_all *all, t_point p1, t_point p2, t_color color)
{
	t_point	delta;
	t_point	cur;
	double	step;
	int		i;

	set_point(&delta,
		(p2.x - p1.x) * MINIMAP_SCALE, (p2.y - p1.y) * MINIMAP_SCALE);
	if (fabs(delta.x) > fabs(delta.y))
		step = fabs(delta.x);
	else
		step = fabs(delta.y);
	delta.x /= step;
	delta.y /= step;
	set_point(&cur, p1.x * MINIMAP_SCALE, p1.y * MINIMAP_SCALE);
	i = 0;
	while (i < step)
	{
		draw_pixel(all, (int)floor(cur.x), (int)floor(cur.y), color);
		cur.x += delta.x;
		cur.y += delta.y;
		i++;
	}
}

void	draw_rectangle(t_all *all, int x, int y, t_color color)
{
	int	i;
	int	j;

	x *= all->tile * MINIMAP_SCALE;
	y *= all->tile * MINIMAP_SCALE;
	i = 0;
	while (i < all->tile * MINIMAP_SCALE)
	{
		j = 0;
		while (j < all->tile * MINIMAP_SCALE)
		{
			draw_pixel(all, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

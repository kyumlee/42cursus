/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:03:59 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:44:50 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

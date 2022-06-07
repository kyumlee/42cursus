/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:41:07 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:27:50 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	draw_lines(t_all *all, t_map map)
{
	int		i;
	t_point	p1;
	t_point	p2;

	i = -1;
	while (++i < (int)map.cols)
	{
		set_point(&p1, i * all->tile, 0);
		set_point(&p2, i * all->tile, map.rows * all->tile);
		draw_line(all, p1, p2, 0x00b3b3b3);
	}
	set_point(&p1, map.cols * all->tile - 1, 0);
	set_point(&p1, map.cols * all->tile - 1, map.rows * all->tile);
	draw_line(all, p1, p2, 0x00b3b3b3);
	i = -1;
	while (++i < (int)map.rows)
	{
		set_point(&p1, 0, i * all->tile);
		set_point(&p2, map.cols * all->tile, i * all->tile);
		draw_line(all, p1, p2, 0x00b3b3b3);
	}
	set_point(&p1, 0, map.rows * all->tile - 1);
	set_point(&p2, map.cols * all->tile, map.rows * all->tile - 1);
	draw_line(all, p1, p2, 0x00b3b3b3);
}

void	draw_rectangles(t_all *all, t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)map.rows)
	{
		j = -1;
		while (++j < (int)map.cols)
		{
			if (map.grid[i][j] == '1')
				draw_rectangle(all, j, i, 0x00000000);
			else if (map.grid[i][j] == '2')
				draw_rectangle(all, j, i, 0x0000FF00);
			else
				draw_rectangle(all, j, i, 0x00FFFFFF);
		}
	}
}

void	render_map(t_all *all)
{
	draw_rectangles(all, all->map);
	draw_lines(all, all->map);
}

int		is_inside_map(double x, double y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int		map_has_wall_at(t_all *all, double x, double y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= all->map.cols * all->tile
		|| y < 0 || y >= all->map.rows * all->tile)
		return (3);
	map_x = floor(y / all->tile);
	map_y = floor(x / all->tile);
	if (all->map.grid[map_x][map_y] == '1')
		return (1);
	if (all->map.grid[map_x][map_y] == '2')
		return (2);
	return (0);
}

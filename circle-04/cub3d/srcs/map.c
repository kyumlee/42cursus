/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:41:07 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:47:44 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	return (0);
}

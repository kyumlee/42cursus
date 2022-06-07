/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:48:14 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:19:38 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	reset_map(t_map *map)
{
	map->cols = 0;
	map->rows = 0;
	map->joined_line = 0;
	map->grid = 0;
}

void	check_map3(t_map *map)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < (int)map->rows - 1)
	{
		j = i + 1;
		if (ft_strlen(map->grid[i]) < ft_strlen(map->grid[j]))
		{
			k = ft_strlen(map->grid[i]) - 2;
			while (++k < (int)ft_strlen(map->grid[j]))
				if (map->grid[j][k] != '1')
					ft_error("Map must be surrounded by walls (1)\n\
(not fully surrounded)");
		}
		if (ft_strlen(map->grid[i]) > ft_strlen(map->grid[j]))
		{
			k = ft_strlen(map->grid[j]) - 2;
			while (++k < (int)ft_strlen(map->grid[i]))
				if (map->grid[i][k] != '1')
					ft_error("Map must be surrounded by walls (1)\n\
(not fully surrounded)");
		}
	}
}

void	check_map2(t_map *map)
{
	int	space;
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->rows - 1)
	{
		j = 0;
		space = skip_space(map->grid[i]);
		while (j < space)
		{
			if (!(map->grid[i + 1][j] == '1' || map->grid[i + 1][j] == ' '))
				ft_error("Map must be surrounded by walls (1)\n\
(not fully surrounded)");
			j++;
		}
		i++;
	}
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)map->rows)
	{
		j = skip_space(map->grid[i]);
		while (j < (int)ft_strlen(map->grid[i]))
		{
			if (!is_map_content(map->grid[i][j]))
				ft_error("Not a valid map (0, 1, 2, N, S, W, E)");
			if ((i == 0 || i == (int)map->rows - 1)
				&& !(map->grid[i][j] == '1' || map->grid[i][j] == ' '))
				ft_error("Map must be surrounded by walls (1)\n\
(1st and last rows must all be 1 or space)");
			if (map->grid[i][(int)ft_strlen(map->grid[i]) - 1] != '1')
				ft_error("Map must be surrounded by walls (1)\n\
(last element of each row must be 1)");
			j++;
		}
		i++;
	}
	check_map2(map);
	check_map3(map);
}

void	fill_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)map->rows)
	{
		j = ft_strlen(map->grid[i]) - 1;
		while (++j < (int)map->cols)
			map->grid[i][j] = '1';
		map->grid[i][j] = 0;
	}
}

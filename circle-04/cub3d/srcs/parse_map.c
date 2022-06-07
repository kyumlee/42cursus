/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:53:35 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:47:58 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*join_lines(char *s1, char *s2, char *delimiter)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!ret)
		ft_error("Memory allocation failed");
	if (!s1_len)
		ft_strncpy(ret, s2, s2_len);
	else
	{
		ft_strncpy(ret, s1, s1_len);
		ft_strncat(ret, delimiter, 1);
		ft_strncat(ret, s2, s2_len);
	}
	free(s1);
	return (ret);
}

int		join_map_lines(t_all *all, char *s)
{
	static char	*buf;

	buf = join_lines(buf, s, ",");
	all->map.joined_line = buf;
	all->map.rows++;
	return (1);
}

int		*get_cols(char *s, int rows)
{
	int	i;
	int	j;
	int	count;
	int	*ret;

	ret = malloc(sizeof(int) * rows);
	if (!ret)
		ft_error("Memory allocation failed");
	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (is_map_content(s[i]))
			count++;
		if (s[i] == ',')
		{
			ret[j++] = count;
			count = 0;
		}
		i++;
	}
	ret[j] = count;
	return (ret);
}

void	parse_map(t_map *map)
{
	int	i;
	int	j;
	int	*cols;

	cols = get_cols(map->joined_line, map->rows);
	get_map_cols(map, cols, map->rows);
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		ft_error("Memory allocation failed");
	i = -1;
	while (++i < (int)map->rows)
	{
		map->grid[i] = malloc(sizeof(char) * (map->cols + 1));
		if (!map->grid[i])
			ft_error("Memory allocation failed");
	}
	i = -1;
	j = 0;
	while (++i < (int)map->rows)
	{
		ft_strncpy(map->grid[i], &map->joined_line[j], cols[i]);
		j += cols[i] + 1;
	}
	free(cols);
	check_map(map);
}

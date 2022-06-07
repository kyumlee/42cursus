/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:49:22 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:49:59 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

int		is_t_id(char *s)
{
	int	i;

	i = skip_space(s);
	if (!ft_strncmp(&s[i], "NO", 2) || !ft_strncmp(&s[i], "SO", 2)
		|| !ft_strncmp(&s[i], "WE", 2) || !ft_strncmp(&s[i], "EA", 2)
		|| (*s == 'S' && ft_isspace(*(s + 1))))
		return (1);
	return (0);
}

int		check_start(char *s)
{
	int	i;

	i = skip_space(s);
	if (s[i] == 'F' || s[i] == 'C'
		|| is_t_id(&s[i]) || !s[i] || s[i] == '1')
		return (1);
	return (0);
}

int		is_map_content(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2'
		|| c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		check_if_map(char *s)
{
	int		i;

	i = skip_space(s);
	if (is_map_content(s[i]))
		return (1);
	return (0);
}

void	get_map_cols(t_map *map, int *cols, int rows)
{
	int	i;
	int	temp;

	i = 0;
	map->cols = cols[i++];
	while (i < rows)
	{
		temp = cols[i];
		if (temp > (int)map->cols)
			map->cols = temp;
		i++;
	}
}

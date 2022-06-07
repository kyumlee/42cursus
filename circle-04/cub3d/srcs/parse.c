/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:51:26 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:05:49 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reset_check(t_check_id *check)
{
	check->f = 0;
	check->c = 0;
	check->no = 0;
	check->so = 0;
	check->we = 0;
	check->ea = 0;
}

void	parse_line(t_all *all, char *s, int *count, t_check_id *check)
{
	int	i;

	i = skip_space(s);
	if (!s[0] && *count == 0)
	{
		free(s);
		return ;
	}
	if (!s[0] && *count > 0)
		ft_error("Empty line is not allowed inside the map");
	else if (s[i] == 'F' || s[i] == 'C')
		parse_f_c(all, s, check);
	else if (is_t_id(&s[i]))
		parse_textures(all, s, check);
	else if (check_if_map(s))
		*count += join_map_lines(all, s);
	free(s);
}

void	check_duplicates(t_check_id *check, int fd)
{
	if (check->f > 1 || check->c > 1 || check->no > 1
		|| check->so > 1 || check->we > 1 || check->ea > 1)
	{
		close(fd);
		ft_error("Duplicate ID is found");
	}
	if (check->f == 0 || check->c == 0 || check->no == 0
		|| check->so == 0 || check->we == 0 || check->ea == 0)
	{
		close(fd);
		ft_error("Missing ID (NO, SO, WE, EA, F, C)");
	}
}

void	free_and_close(char *line, char *map_line, int fd)
{
	free(line);
	free(map_line);
	close(fd);
}

int		parse(t_all *all, char *s)
{
	t_check_id	check;
	int			fd;
	int			count;
	char		*line;

	fd = check_filename(s);
	count = 0;
	reset_map(&all->map);
	reset_check(&check);
	while (get_next_line(fd, &line) > 0)
	{
		if (!check_start(line))
			ft_error("Wrong ID / map should start with a wall");
		parse_line(all, line, &count, &check);
	}
	check_duplicates(&check, fd);
	parse_map(&all->map);
	free_and_close(line, all->map.joined_line, fd);
	return (1);
}

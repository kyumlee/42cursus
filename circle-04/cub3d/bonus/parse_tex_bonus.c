/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:55:12 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 17:38:12 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	count_duplicate(char *s, t_check_id *check)
{
	if (!ft_strncmp(s, "NO", 2))
		check->no++;
	else if (!ft_strncmp(s, "SO", 2))
		check->so++;
	else if (!ft_strncmp(s, "WE", 2))
		check->we++;
	else if (!ft_strncmp(s, "EA", 2))
		check->ea++;
	else if (*s == 'S' && ft_isspace(*(s + 1)))
		check->s++;
}

int		get_index_id(char *s, t_check_id *check)
{
	count_duplicate(s, check);
	if (!ft_strncmp(s, "NO", 2))
		return (0);
	else if (!ft_strncmp(s, "SO", 2))
		return (1);
	else if (!ft_strncmp(s, "WE", 2))
		return (2);
	else if (!ft_strncmp(s, "EA", 2))
		return (3);
	else if (*s == 'S' && ft_isspace(*(s + 1)))
		return (4);
	return (-1);
}

void	check_tex_file(char *s)
{
	int	fd;
	int	len;

	len = ft_strlen(s);
	if (!s || !len)
		ft_error("Wrong filename");
	if (ft_strncmp(&s[len - 4], ".xpm", 4))
		ft_error("Wrong filename extension (.xpm)");
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("File does not exist");
	}
	close(fd);
}

int		parse_textures(t_all *all, char *s, t_check_id *check)
{
	int	i;
	int	id;

	if (!is_t_id(s))
		return (0);
	i = skip_space(s);
	id = get_index_id(&s[i], check);
	if (id == -1)
		ft_error("Unknown texture ID (NO, SO, WE, EA, S)");
	i++;
	if (id >= 0 && id <= 3)
		i++;
	i += skip_space(&s[i]);
	all->textures[id].path = ft_strdup(&s[i]);
	check_tex_file(all->textures[id].path);
	return (1);
}

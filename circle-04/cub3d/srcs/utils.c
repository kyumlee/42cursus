/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:13:39 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:23:00 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(char *str)
{
	write(2, "ERROR\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

int		check_filename(char *s)
{
	int	fd;
	int	len;

	len = ft_strlen(s);
	if (!s || !len)
		ft_error("Wrong filename");
	if (!(s[len - 4] == '.' && s[len - 3] == 'c'
			&& s[len - 2] == 'u' && s[len - 1] == 'b'))
		ft_error("Wrong filename extension (.cub)");
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_error("File does not exist");
	}
	return (fd);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		skip_space(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

void	set_all_rest(t_all *all)
{
	all->tile = WIDTH / all->map.cols;
	all->fov = 60 * M_PI / 180;
	all->dist_proj_plane = ((WIDTH / 2) / tan(all->fov / 2));
}

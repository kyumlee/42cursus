/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:15:31 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:44:36 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		has_newline(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*join(char *s1, char *s2, int *check_error)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	*check_error = 1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	*check_error = 0;
	if (s1_len == 0)
		ft_strncpy(str, s2, s2_len);
	else
	{
		ft_strncpy(str, s1, s1_len);
		ft_strncat(str, s2, s2_len);
	}
	free(s1);
	return (str);
}

char	*split(char **line, char *s_buf, int *check_error)
{
	char	*res;
	int		i;

	i = 0;
	*check_error = 1;
	while (s_buf[i] && s_buf[i] != '\n')
		i++;
	*line = malloc(sizeof(char) * (i + 1));
	if (!*line)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s_buf) - i + 1));
	if (!res)
		return (NULL);
	*check_error = 0;
	ft_strncpy(*line, s_buf, i);
	if (s_buf[i] == '\0')
	{
		free(res);
		res = 0;
	}
	else
		ft_strncpy(res, &s_buf[i + 1], ft_strlen(s_buf) - i);
	free(s_buf);
	return (res);
}

int		free_return(char *buf)
{
	free(buf);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*s_buf[OPEN_MAX];
	int			size;
	int			check_error;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	size = 1;
	while (size != 0 && !has_newline(s_buf[fd]))
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (free_return(buf));
		buf[size] = '\0';
		s_buf[fd] = join(s_buf[fd], buf, &check_error);
	}
	free(buf);
	s_buf[fd] = split(line, s_buf[fd], &check_error);
	if (!s_buf[fd])
		free(s_buf[fd]);
	if (size == 0)
		return (0);
	return (1);
}

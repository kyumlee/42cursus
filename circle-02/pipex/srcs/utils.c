/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:45:40 by kyumlee           #+#    #+#             */
/*   Updated: 2021/07/24 18:40:40 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_error(char *s, char *name)
{
	write(2, s, ft_strlen(s));
	if (!name)
		exit(1);
	write(2, ": ", 2);
	write(2, name, ft_strlen(name));
	write(2, "\n", 1);
	exit(1);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	if (!dst && !src)
		ft_error("Both strings are null", 0);
	i = 0;
	while (src[i] && len--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < (int)n)
	{
		if (s1[i] == s2[i])
		{
			i++;
			continue ;
		}
		return (s1[i] - s2[i]);
	}
	if ((int)n == i || (!s1[i] && !s2[i]))
		return (0);
	return (s1[i] - s2[i]);
}

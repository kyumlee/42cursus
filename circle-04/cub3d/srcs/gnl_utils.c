/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:15:38 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:44:43 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (src[i] && len--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s2[i] && n--)
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}

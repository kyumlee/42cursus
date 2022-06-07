/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:30:11 by kyumlee           #+#    #+#             */
/*   Updated: 2021/01/19 19:45:30 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
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

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	int		i;
	int		j;

	if (!dst && !src)
		return (NULL);
	i = 0;
	j = ft_strlen(dst);
	while (src[i] && len--)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (dst);
}

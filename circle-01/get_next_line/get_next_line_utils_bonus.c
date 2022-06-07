/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 06:11:30 by kyumlee           #+#    #+#             */
/*   Updated: 2021/01/23 06:11:32 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

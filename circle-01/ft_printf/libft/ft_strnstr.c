/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:21:45 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 16:49:35 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		if (haystack[i] == needle[k])
		{
			j = i;
			while (haystack[j] == needle[k] && needle[k] && j < len && k < len)
			{
				j++;
				k++;
			}
			if (needle[k] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

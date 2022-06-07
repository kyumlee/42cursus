/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:12:11 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 17:31:32 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*tmpd = *tmps;
		if (*tmps == (unsigned char)c)
			return (tmpd + 1);
		tmpd++;
		tmps++;
	}
	return (NULL);
}

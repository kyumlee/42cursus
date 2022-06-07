/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:58:30 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 17:30:57 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (tmpd == NULL && tmps == NULL)
		return (NULL);
	while (n--)
		*tmpd++ = *tmps++;
	return (dst);
}

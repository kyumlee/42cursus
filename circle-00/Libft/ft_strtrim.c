/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:59:22 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 01:52:19 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*tmp;
	int		cnt_set;
	int		r_len;

	if (s1 == NULL)
		return (NULL);
	tmp = (char *)s1;
	cnt_set = 0;
	while (isset(*tmp++, set) == 1)
		cnt_set++;
	while (*tmp)
		tmp++;
	while (isset(*--tmp, set) == 1)
		cnt_set++;
	r_len = ft_strlen(s1) - cnt_set;
	result = malloc(sizeof(char) * (r_len + 1));
	if (result == NULL)
		return (result);
	while (isset(*s1, set) == 1)
		s1++;
	ft_strlcpy(result, s1, r_len + 1);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:21:22 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 01:52:45 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnt_strs(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			cnt++;
		s++;
	}
	return (cnt);
}

int		len_str(char const *s, char c)
{
	int		cnt;
	char	*tmp;

	tmp = (char *)s;
	cnt = 0;
	while (*tmp == c)
		tmp++;
	while (*tmp)
	{
		if (*tmp != c)
			cnt++;
		else
			break ;
		tmp++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		cnt_s;

	if (s == NULL)
		return (NULL);
	i = 0;
	cnt_s = cnt_strs((char *)s, c);
	if (!(strs = malloc(sizeof(char *) * (cnt_s + 1))))
		return (strs);
	while (*s)
	{
		if (*s != c)
		{
			if (!(strs[i] = malloc(sizeof(char *) * (len_str(s, c) + 1))))
				return (strs);
			ft_strlcpy(strs[i], s, len_str(s, c) + 1);
			s += len_str(s, c);
			i++;
		}
		else
			s++;
	}
	strs[i] = 0;
	return (&strs[0]);
}

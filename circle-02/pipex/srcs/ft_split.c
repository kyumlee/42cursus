/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:21:22 by kyumlee           #+#    #+#             */
/*   Updated: 2021/07/19 21:08:53 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

int	cnt_strs(char *s, char c)
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

int	len_str(char const *s, char c)
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

char	**split(char *s, char c, int cnt)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * (cnt + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret[i] = malloc(sizeof(char) * (len_str(s, c) + 1));
			if (!ret[i])
				return (0);
			ft_strncpy(ret[i], s, len_str(s, c));
			s += len_str(s, c);
			i++;
		}
		else
			s++;
	}
	ret[i] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		cnt_s;

	if (!s)
		return (0);
	cnt_s = cnt_strs((char *)s, c);
	ret = split((char *)s, c, cnt_s);
	return (ret);
}

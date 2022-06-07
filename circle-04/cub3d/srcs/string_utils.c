/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:56:50 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 18:54:33 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
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
		i++;
	}
	if ((int)n == i || (!s1[i] && !s2[i]))
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	if (!s1)
		return (0);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

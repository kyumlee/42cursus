/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:40:30 by kyumlee           #+#    #+#             */
/*   Updated: 2021/05/28 19:24:09 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(char *s, int *i)
{
	int	num;

	num = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		num = num * 10 + (s[*i] - 48);
		(*i)++;
	}
	return (num);
}

int	check_color(char *s)
{
	int	i;
	int	count;

	i = 1;
	while (ft_isspace(s[i]))
		i++;
	count = 0;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i])
	{
		if (s[i] == ',' && s[i + 1] >= '0' && s[i + 1] <= '9')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	parse_floor(t_all *all, char *s)
{
	int	i;
	int	j;
	int	k;

	if (!check_color(s))
		ft_error("Not a valid color for F ([R,G,B])");
	all->floor_color = 0x00000000;
	i = skip_space(s) + 1;
	j = -1;
	k = 16;
	while (++j < 3)
	{
		i += skip_space(&s[i]);
		all->floor_color |= ft_atoi(s, &i) << k;
		i += skip_space(&s[i]);
		if (s[i] == ',')
			i++;
		k -= 8;
	}
	i += skip_space(&s[i]);
	if (s[i] != '\0')
		ft_error("Wrong format for F(loor)");
	return (1);
}

int	parse_ceiling(t_all *all, char *s)
{
	int	i;
	int	j;
	int	k;

	if (!check_color(s))
		ft_error("Not a valid color for C ([R,G,B])");
	all->ceiling_color = 0x00000000;
	i = skip_space(s) + 1;
	j = -1;
	k = 16;
	while (++j < 3)
	{
		i += skip_space(&s[i]);
		all->ceiling_color |= ft_atoi(s, &i) << k;
		i += skip_space(&s[i]);
		if (s[i] == ',')
			i++;
		k -= 8;
	}
	i += skip_space(&s[i]);
	if (s[i] != '\0')
		ft_error("Wrong format for C(eiling)");
	return (1);
}

int	parse_f_c(t_all *all, char *s, t_check_id *check)
{
	int	i;

	i = skip_space(s);
	if (!(s[i] == 'F' || s[i] == 'C'))
		return (0);
	else if (s[i] == 'F')
	{
		check->f++;
		return (parse_floor(all, s));
	}
	else
	{
		check->c++;
		return (parse_ceiling(all, s));
	}
}

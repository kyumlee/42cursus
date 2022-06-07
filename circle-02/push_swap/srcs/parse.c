/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:34:56 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/10 17:32:52 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		count_signs(char *s, int *i)
{
	int	neg;
	int	pos;

	neg = 0;
	pos = 0;
	while (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			neg++;
		if (s[*i] == '+')
			pos++;
		(*i)++;
	}
	if (neg == 1 && pos == 0)
		return (-1);
	else if (neg == 0 && (pos == 1 || pos == 0))
		return (1);
	else
		return (0);
}

int		ft_atoi(char *s, long *ret)
{
	int	i;
	int	sign;

	*ret = 0;
	i = 0;
	sign = count_signs(&s[i], &i);
	while (ft_isdigit(s[i]))
	{
		*ret = (*ret * 10) + (s[i] - '0');
		i++;
	}
	*ret *= sign;
	return (i);
}

void	parse(char *s, t_list *a)
{
	int		i;
	long	num;

	i = ft_atoi(s, &num);
	if (num > 2147483647 || num < -2147483648)
		ft_error();
	insert_end(&a, num);
	while (s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		if (!s[i])
			break ;
		i += ft_atoi(&s[i], &num);
		insert_end(&a, num);
	}
}

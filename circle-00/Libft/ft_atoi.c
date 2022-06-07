/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:11:27 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 01:17:47 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		skip_nondigits(char *str)
{
	int	cnt_minus;
	int	cnt_plus;

	cnt_minus = 0;
	cnt_plus = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cnt_minus++;
		if (*str == '+')
			cnt_plus++;
		str++;
	}
	if (cnt_minus == 1 && cnt_plus == 0)
		return (-1);
	else if (cnt_minus == 0 && (cnt_plus == 0 || cnt_plus == 1))
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str)
{
	int	result;
	int	check;

	result = 0;
	check = skip_nondigits((char *)str);
	if (check == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * check);
}

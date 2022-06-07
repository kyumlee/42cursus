/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:58:21 by kyumlee           #+#    #+#             */
/*   Updated: 2020/12/27 01:47:17 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnt_digits(int n)
{
	int		tmp;
	int		cnt;

	tmp = n;
	if (n < 0)
	{
		tmp *= -1;
		cnt = 1;
	}
	else
		cnt = 0;
	while (tmp != 0)
	{
		cnt++;
		tmp /= 10;
	}
	if (n == 0)
		cnt = 1;
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		cnt;
	char	*s;

	cnt = cnt_digits(n);
	if (!(s = malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	s[cnt] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			s[--cnt] = '8';
			n /= 10;
		}
		n *= -1;
		s[0] = '-';
	}
	else if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		s[--cnt] = (n % 10) + 48;
		n /= 10;
	}
	return (s);
}

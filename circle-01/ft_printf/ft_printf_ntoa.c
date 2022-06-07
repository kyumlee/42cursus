/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ntoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 04:07:14 by kyumlee           #+#    #+#             */
/*   Updated: 2021/02/10 00:48:08 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse(char *buf, int i, int cnt)
{
	char	*res;

	if (!(res = malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	while (i < cnt)
	{
		res[i] = buf[cnt - i - 1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	dtoa(char **res, long long num)
{
	char	buf[21];
	int		i;
	int		cnt;

	cnt = cnt_digits(num);
	i = 0;
	if (num == 0)
		buf[i++] = '0';
	if (num < 0)
	{
		num *= -1;
		buf[cnt - 1] = '-';
	}
	while (num)
	{
		buf[i] = "0123456789"[num % 10];
		i++;
		num /= 10;
	}
	i = 0;
	*res = reverse(buf, i, cnt);
}

void	utoa(char **res, unsigned long long num)
{
	char	buf[21];
	int		i;
	int		cnt;

	cnt = 0;
	if (num == 0)
		buf[cnt++] = '0';
	while (num)
	{
		buf[cnt++] = "0123456789"[num % 10];
		num /= 10;
	}
	i = 0;
	*res = reverse(buf, i, cnt);
}

void	xtoa(char **res, unsigned long long num, char opt)
{
	char	buf[21];
	int		i;
	int		cnt;

	cnt = 0;
	if (num == 0)
		buf[cnt++] = '0';
	while (num)
	{
		if (opt == 'x' || opt == 'p')
			buf[cnt++] = "0123456789abcdef"[num % 16];
		else
			buf[cnt++] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	i = 0;
	*res = reverse(buf, i, cnt);
}

void	ptoa(char **res, unsigned long long num)
{
	char	buf[21];
	int		i;
	int		cnt;

	cnt = 0;
	if (num == 0)
		buf[cnt++] = '0';
	while (num)
	{
		buf[cnt++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	i = 0;
	*res = reverse(buf, i, cnt);
}

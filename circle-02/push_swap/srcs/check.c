/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 20:18:00 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/12 18:06:44 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_argv(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || ft_isspace(s[i])
			|| (s[i] == '-' && ft_isdigit(s[i + 1]))
			|| (s[i] == '+' && ft_isdigit(s[i + 1])))
			i++;
		else
			ft_error();
	}
}

void	check_dup(t_list *a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		count;

	tmp1 = a->next;
	while (tmp1 != a)
	{
		tmp2 = a->next;
		count = 0;
		while (tmp2 != a)
		{
			if (tmp1->data == tmp2->data)
				count++;
			tmp2 = tmp2->next;
		}
		if (count > 1)
			ft_error();
		tmp1 = tmp1->next;
	}
}

int		check_if_sorted_a(t_list *list)
{
	t_list	*tmp;

	if (!count_list(list))
		exit(0);
	tmp = list->next;
	while (tmp->next != list)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int		check_if_sorted_d(t_list *list)
{
	t_list	*tmp;

	if (!count_list(list))
		exit(0);
	tmp = list->next;
	while (tmp->next != list)
	{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

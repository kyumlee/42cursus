/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:25:33 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/09 01:39:58 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_swap(t_list *list)
{
	t_list	*first;
	t_list	*second;

	if (count_list(list) < 2)
		return ;
	first = list->next;
	second = first->next;
	list->next = second;
	second->prev = list;
	first->next = second->next;
	second->next->prev = first;
	first->prev = second;
	second->next = first;
}

void	swap(t_stack stack, char c)
{
	if (c == 'a')
	{
		do_swap(stack.a);
		ft_puts("sa\n");
	}
	else if (c == 'b')
	{
		do_swap(stack.b);
		ft_puts("sb\n");
	}
	else if (c == 's')
	{
		do_swap(stack.a);
		do_swap(stack.b);
		ft_puts("ss\n");
	}
	else
		ft_error();
}

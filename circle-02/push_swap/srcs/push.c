/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:59:47 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/09 02:13:07 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_push(t_list *from, t_list *to)
{
	t_list	*tmp_from;

	if (!count_list(from))
		return ;
	tmp_from = from->next;
	from->next = tmp_from->next;
	tmp_from->next->prev = from;
	to->next->prev = tmp_from;
	tmp_from->next = to->next;
	tmp_from->prev = to;
	to->next = tmp_from;
}

void	push(t_stack stack, char c)
{
	if (c == 'a')
	{
		do_push(stack.b, stack.a);
		ft_puts("pa\n");
	}
	else if (c == 'b')
	{
		do_push(stack.a, stack.b);
		ft_puts("pb\n");
	}
	else
		ft_error();
}

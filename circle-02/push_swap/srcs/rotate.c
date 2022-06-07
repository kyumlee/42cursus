/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:36:11 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/11 21:05:35 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rotate(t_list *list)
{
	t_list	*first;
	t_list	*tmp;

	first = list->next;
	tmp = list->next;
	list->next = first->next;
	list->prev = first;
	while (tmp->next != list)
		tmp = tmp->next;
	tmp->next = first;
	first->next = list;
	first->prev = tmp;
}

void	do_reverse_rotate(t_list *list)
{
	t_list	*first;
	t_list	*last;
	t_list	*tmp;

	first = list->next;
	last = list->next;
	while (last->next != list)
		last = last->next;
	tmp = last->prev;
	last->next = first;
	last->prev = list;
	list->next = last;
	first->prev = last;
	tmp->next = list;
	list->prev = tmp;
}

void	rotate(t_stack stack, char c)
{
	if (c == 'a')
	{
		do_rotate(stack.a);
		ft_puts("ra\n");
	}
	else if (c == 'b')
	{
		do_rotate(stack.b);
		ft_puts("rb\n");
	}
	else if (c == 'r')
	{
		do_rotate(stack.a);
		do_rotate(stack.b);
		ft_puts("rr\n");
	}
	else
		ft_error();
}

void	reverse_rotate(t_stack stack, char c)
{
	if (c == 'a')
	{
		do_reverse_rotate(stack.a);
		ft_puts("rra\n");
	}
	else if (c == 'b')
	{
		do_reverse_rotate(stack.b);
		ft_puts("rrb\n");
	}
	else if (c == 'r')
	{
		do_reverse_rotate(stack.a);
		do_reverse_rotate(stack.b);
		ft_puts("rrr\n");
	}
	else
		ft_error();
}

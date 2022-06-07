/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 01:15:10 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/13 02:10:59 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_2_top(t_stack stack, char c, int data)
{
	int		count;
	t_list	*tmp;
	t_list	*list;

	count = 0;
	list = 0;
	if (c == 'a')
		list = stack.a;
	else if (c == 'b')
		list = stack.b;
	tmp = list->next;
	while (tmp->data != data)
	{
		tmp = tmp->next;
		count++;
	}
	if (count <= count_list(list) / 2)
		while (count--)
			rotate(stack, c);
	else
	{
		count = count_list(list) - count;
		while (count--)
			reverse_rotate(stack, c);
	}
}

void		push_b_back_2_a(t_stack stack, int count)
{
	t_list	*b;

	b = stack.b->next;
	while (count--)
		push(stack, 'a');
}

void		case_2(t_stack stack)
{
	t_list	*list;

	list = stack.a;
	if (list->next->data < list->next->next->data)
		return ;
	else
		swap(stack, 'a');
}

void		case_3(t_stack stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack.a->next->data;
	mid = stack.a->next->next->data;
	bot = stack.a->next->next->next->data;
	if (top > mid && mid < bot && bot > top)
		swap(stack, 'a');
	else if (top > mid && mid > bot && bot < top)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (top > mid && mid < bot && bot < top)
		rotate(stack, 'a');
	else if (top < mid && mid > bot && bot > top)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (top < mid && mid > bot && bot < top)
		reverse_rotate(stack, 'a');
}

void		case_4_5_6(t_stack stack, int count)
{
	int	i;
	int	j;
	int	min;

	if (check_if_sorted_a(stack.a))
		return ;
	j = count - 3;
	i = -1;
	while (++i < j)
	{
		min = get_min(stack, 'a');
		move_2_top(stack, 'a', min);
		push(stack, 'b');
	}
	case_3(stack);
	push_b_back_2_a(stack, j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_2_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:17:44 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/13 02:10:11 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		move_top_push(t_stack stack, int data, int count)
{
	int	r_count;

	r_count = 0;
	while (count--)
	{
		if (stack.b->next->data == data)
		{
			push(stack, 'a');
			break ;
		}
		rotate(stack, 'b');
		r_count++;
	}
	if (r_count != count_list(stack.b))
		while (r_count--)
			reverse_rotate(stack, 'b');
}

static int	return_case(t_stack stack, int count)
{
	t_list	*list;
	int		i;
	int		max;

	if (count > 3)
		return (0);
	list = stack.b->next;
	i = -1;
	if (count == 2)
	{
		if (list->data < list->next->data)
			swap(stack, 'b');
		push_b_back_2_a(stack, count);
	}
	else if (count == 3)
	{
		while (++i < count)
		{
			max = get_max(stack, 'b', count - i);
			move_top_push(stack, max, count);
		}
	}
	return (1);
}

void		b_2_a(t_stack stack, int count)
{
	int	pivot;
	int	rb_count;
	int	pa_count;
	int	i;

	if (return_case(stack, count))
		return ;
	pivot = get_pivot(stack, 'b', count);
	rb_count = 0;
	pa_count = 0;
	while (count--)
	{
		if (stack.b->next->data >= pivot && ++pa_count)
			push(stack, 'a');
		else if (stack.b->next->data < pivot && ++rb_count)
			rotate(stack, 'b');
	}
	i = -1;
	if (rb_count != count_list(stack.b))
		while (++i < rb_count)
			reverse_rotate(stack, 'b');
	a_2_b(stack, pa_count);
	b_2_a(stack, rb_count);
}

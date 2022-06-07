/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:14:06 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/14 16:49:07 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rsrr(t_stack stack)
{
	rotate(stack, 'a');
	swap(stack, 'a');
	reverse_rotate(stack, 'a');
}

void		rsr(t_stack stack, int order)
{
	if (order == 132)
		rsrr(stack);
	else if (order == 213)
		swap(stack, 'a');
	else if (order == 231)
	{
		rsrr(stack);
		swap(stack, 'a');
	}
	else if (order == 312)
	{
		swap(stack, 'a');
		rsrr(stack);
	}
	else if (order == 321)
	{
		swap(stack, 'a');
		rsrr(stack);
		swap(stack, 'a');
	}
}

void		case_3_in_a(t_stack stack)
{
	int	top;
	int	mid;
	int	bot;

	top = stack.a->next->data;
	mid = stack.a->next->next->data;
	bot = stack.a->next->next->next->data;
	if (top < mid && mid < bot && bot > top)
		return ;
	if (top < mid && top < bot && mid > bot)
		rsr(stack, 132);
	else if (top > mid && mid < bot && bot > top)
		rsr(stack, 213);
	else if (top < mid && mid > bot && bot < top)
		rsr(stack, 231);
	else if (top > mid && mid < bot && bot < top)
		rsr(stack, 312);
	else if (top > mid && mid > bot && bot < top)
		rsr(stack, 321);
}

static int	return_case(t_stack stack, int count)
{
	if (count > 3)
		return (0);
	if (check_if_sorted_a(stack.a))
		return (1);
	if (count == 2 && count_list(stack.a) == 2)
		case_2(stack);
	else if (count == 2 && count_list(stack.a) != count
		&& stack.a->next->data > stack.a->next->next->data)
		swap(stack, 'a');
	else if (count == 3 && count_list(stack.a) == count)
		case_3(stack);
	else if (count == 3 && count_list(stack.a) != count)
		case_3_in_a(stack);
	return (1);
}

void		a_2_b(t_stack stack, int count)
{
	int			pivot;
	int			ra_count;
	int			pb_count;
	int			i;

	if (return_case(stack, count))
		return ;
	pivot = get_pivot(stack, 'a', count);
	ra_count = 0;
	pb_count = 0;
	while (count--)
	{
		if (stack.a->next->data >= pivot && ++ra_count)
			rotate(stack, 'a');
		else if (stack.a->next->data < pivot && ++pb_count)
			push(stack, 'b');
	}
	i = -1;
	if (ra_count != count_list(stack.a))
		while (++i < ra_count)
			reverse_rotate(stack, 'a');
	a_2_b(stack, ra_count);
	b_2_a(stack, pb_count);
}

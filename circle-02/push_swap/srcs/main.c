/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:06:31 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/14 16:49:42 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *stack)
{
	stack->a = malloc(sizeof(t_list));
	if (!stack->a)
		ft_error();
	stack->a->data = 0;
	stack->a->next = stack->a;
	stack->a->prev = stack->a;
	stack->b = malloc(sizeof(t_list));
	if (!stack->b)
		ft_error();
	stack->b->data = 0;
	stack->b->next = stack->b;
	stack->b->prev = stack->b;
}

void	if_sorted_d(t_stack stack, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		push(stack, 'b');
	i = -1;
	while (++i < count)
	{
		if (i < count - 1)
			reverse_rotate(stack, 'b');
		push(stack, 'a');
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	t_stack	stack;

	if (argc == 1)
		exit(0);
	i = 0;
	init_stacks(&stack);
	while (++i < argc)
	{
		check_argv(argv[i]);
		parse(argv[i], stack.a);
	}
	check_dup(stack.a);
	if (check_if_sorted_a(stack.a) || count_list(stack.a) == 1)
		exit(0);
	else if (check_if_sorted_d(stack.a) && count_list(stack.a) > 6)
		if_sorted_d(stack, count_list(stack.a));
	else if (count_list(stack.a) >= 4 && count_list(stack.a) <= 6)
		case_4_5_6(stack, count_list(stack.a));
	else
		case_big(stack, count_list(stack.a));
	free_stack(&stack.a);
	free_stack(&stack.b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:22:48 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/12 23:11:36 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_end(t_list **head, int data)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *head;
	new = malloc(sizeof(t_list));
	if (!tmp)
	{
		new->data = data;
		new->next = new;
		new->prev = new;
		tmp = new;
	}
	else
	{
		new->next = tmp;
		new->data = data;
		tmp->prev = new;
		while (tmp->next != *head)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

int		count_list(t_list *list)
{
	t_list	*tmp;
	int		count;

	tmp = list->next;
	count = 0;
	while (tmp != list)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int		get_min(t_stack stack, char c)
{
	t_list	*tmp;
	t_list	*list;
	int		min;

	list = 0;
	if (c == 'a')
		list = stack.a;
	else if (c == 'b')
		list = stack.b;
	else
		ft_error();
	tmp = list->next;
	min = tmp->data;
	while (tmp->next != list)
	{
		if (tmp->next->data < min)
			min = tmp->next->data;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max(t_stack stack, char c, int count)
{
	t_list	*tmp;
	t_list	*list;
	int		max;

	list = 0;
	if (c == 'a')
		list = stack.a;
	else if (c == 'b')
		list = stack.b;
	else
		ft_error();
	tmp = list->next;
	max = tmp->data;
	while (count--)
	{
		if (tmp->next->data > max)
			max = tmp->next->data;
		tmp = tmp->next;
	}
	return (max);
}

void	free_stack(t_list **list)
{
	t_list	*next;
	t_list	*temp;

	if (!list || !*list)
		return ;
	next = (*list)->next;
	while (next && (next != *list))
	{
		temp = next;
		next = next->next;
		free(temp);
	}
	free(*list);
	*list = NULL;
}

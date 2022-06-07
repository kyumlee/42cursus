/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:11:48 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/14 16:49:55 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_arr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		swap_arr(&arr[min], &arr[i]);
		i++;
	}
}

int		*sort_list_2_arr(t_list *list, int count)
{
	int		*ret;
	int		i;
	t_list	*tmp;

	ret = malloc(sizeof(int) * count);
	if (!ret)
		ft_error();
	i = 0;
	tmp = list->next;
	while (count--)
	{
		ret[i++] = tmp->data;
		tmp = tmp->next;
	}
	selection_sort(ret, i);
	return (ret);
}

int		get_pivot(t_stack stack, char c, int count)
{
	int	*arr;
	int	ret;
	int	i;

	arr = 0;
	if (c == 'a')
		arr = sort_list_2_arr(stack.a, count);
	else if (c == 'b')
		arr = sort_list_2_arr(stack.b, count);
	else
		ft_error();
	i = count / 2;
	ret = arr[i];
	free(arr);
	return (ret);
}

void	case_big(t_stack stack, int count)
{
	a_2_b(stack, count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:08:27 by kyumlee           #+#    #+#             */
/*   Updated: 2021/06/12 23:22:34 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list {
	int				data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;
typedef struct		s_stack {
	t_list			*a;
	t_list			*b;
}					t_stack;
void				ft_error(void);
int					ft_isspace(char c);
int					ft_isdigit(char c);
void				ft_puts(char *s);
void				check_argv(char *s);
void				check_dup(t_list *a);
int					check_if_sorted_a(t_list *list);
int					check_if_sorted_d(t_list *list);
void				parse(char *s, t_list *list);
void				insert_end(t_list **head, int data);
int					count_list(t_list *list);
int					get_min(t_stack stack, char c);
int					get_max(t_stack stack, char c, int count);
void				free_stack(t_list **list);
void				swap(t_stack stack, char c);
void				push(t_stack stack, char c);
void				rotate(t_stack stack, char c);
void				reverse_rotate(t_stack stack, char c);
void				push_b_back_2_a(t_stack stack, int count);
void				case_2(t_stack stack);
void				case_3(t_stack stack);
void				case_4_5_6(t_stack stack, int count);
int					get_pivot(t_stack stack, char c, int count);
void				case_big(t_stack stack, int count);
void				a_2_b(t_stack stack, int count);
void				b_2_a(t_stack stack, int count);

#endif

#ifndef __STACK_TEST_HPP__
# define __STACK_TEST_HPP__

# include <iostream>
# include <vector>
# include <stack>
# include "./../stack.hpp"

# if !defined(USING_STD)
#  define NAMESPACE	ft
# else
#  define NAMESPACE	std
# endif

# define T_STACK	int

typedef	NAMESPACE::stack<T_STACK, NAMESPACE::vector<T_STACK> >	Stack;

void	print_stack (Stack& st, std::string name);
void	stack_test ();

#endif

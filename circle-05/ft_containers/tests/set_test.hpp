#ifndef __SET_TEST_HPP__
# define __SET_TEST_HPP__

# include <iostream>
# include <set>
# include "./../set.hpp"

# if !defined(USING_STD)
#  define NAMESPACE	ft
# else
#  define NAMESPACE	std
# endif

# define T_SET	int

typedef	NAMESPACE::set<T_SET>	Set;
typedef	Set::iterator			set_iterator;
typedef	Set::reverse_iterator	set_rev_iterator;

void	print_set (Set& set, std::string name);
void	set_test ();

#endif

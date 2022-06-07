#ifndef __VECTOR_TEST_HPP__
# define __VECTOR_TEST_HPP__

# include <vector>
# include <iostream>
# include "../vector.hpp"

# if !defined(USING_STD)
#  define NAMESPACE	ft
# else
#  define NAMESPACE	std
# endif

# define T_VEC int

typedef	NAMESPACE::vector<T_VEC>	Vector;
typedef	Vector::iterator			vec_iterator;
typedef	Vector::reverse_iterator	vec_rev_iterator;

void	print_vec (Vector vec, std::string name);
void	print_it (vec_iterator it, std::string name, bool nl);
void	print_it (vec_rev_iterator it, std::string name, bool nl);
void	vec_it_test (Vector v1, Vector v2, Vector v3, Vector v4);
void	vector_test ();

#endif

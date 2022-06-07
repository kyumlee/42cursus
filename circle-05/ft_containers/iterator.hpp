#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

# include "./iterator_traits.hpp"

namespace	ft {

	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	struct iterator {
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template< class InputIterator, class Distance >
	void	advance (InputIterator& it, Distance n) {
		while (n--)
			it++;
	}

	template< class InputIterator >
	typename ft::iterator_traits<InputIterator>::difference_type	distance (InputIterator first, InputIterator last) {
		typename ft::iterator_traits<InputIterator>::difference_type	ret = 0;
		for (InputIterator tmp = first; tmp != last; tmp++)
			ret++;
		return (ret);
	};

}

#endif

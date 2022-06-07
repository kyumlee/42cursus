#ifndef __EASY_FIND_HPP__
# define __EASY_FIND_HPP__

# include <iostream>
# include <exception>

class						NotFoundException : public std::exception {
	const char				*what(void) const throw();
};

template <typename T>
typename T::iterator		easyfind(T &arr, int &a) {
	typename T::iterator	iter = std::find(arr.begin(), arr.end(), a);

	if (iter == arr.end())
		throw (NotFoundException());

	return (iter);
}

#endif

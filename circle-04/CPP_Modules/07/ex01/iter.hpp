#ifndef __ITER_HPP__
# define __ITER_HPP__

# include <iostream>

template <typename T>
void	print(T &i) {
	std::cout << "[" << i << "] ";
}

template <typename T>
void	printAddress(T &p) {
	std::cout << "[" << &p << "] ";
}

template <typename T>
void	increment(T &a) {
	a++;
}

template <typename T>
void	iter(T *addr, int len, void (*f)(T &)) {
	for (int i = 0; i < len; i++) {
		f(addr[i]);
	}
};

#endif

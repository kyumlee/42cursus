#include "./iter.hpp"

int	main(void) {
	int	i_arr[3] = {0, 1, 2};
	std::cout << "elements of i_arr: ";
	::iter(i_arr, 3, ::print);
	std::cout << std::endl;
	std::cout << "increment all elements of array by 1." << std::endl;
	::iter(i_arr, 3, ::increment);
	std::cout << "print of <int> iter: ";
	::iter(i_arr, 3, ::print);
	std::cout << std::endl;
	std::cout << "print of <int> iter: ";
	::iter(i_arr, 3, ::printAddress);

	std::cout << std::endl << std::endl;

	float	f_arr[5] = {0.0, 0.1, 0.2, 0.3, 0.4};
	std::cout << "elements of f_arr: ";
	::iter(f_arr, 3, print);
	std::cout << std::endl;
	std::cout << "increment all elements of array by 1." << std::endl;
	::iter(f_arr, 5, ::increment);
	std::cout << "print of <int> iter: ";
	::iter(f_arr, 5, ::print);
	std::cout << std::endl;
	std::cout << "print of <int> iter: ";
	::iter(f_arr, 5, ::printAddress);

	std::cout << std::endl << std::endl;

	std::string	s_arr[5] = {"hello", "this", "is", "c", "plus plus"};
	std::cout << "elements of s_arr: ";
	for (unsigned long i = 0; i < sizeof(s_arr) / sizeof(s_arr[0]); i++) {
		std::cout << "[" << s_arr[i] << "] ";
	} std::cout << std::endl;
	::iter(s_arr, 5, ::increment);
	std::cout << "print of <string> iter: ";
	::iter(s_arr, 5, ::print);
	std::cout << std::endl;
	std::cout << "print of address <string> iter: ";
	::iter(s_arr, 5, ::printAddress);

	std::cout << std::endl;
}

#include <iostream>
#include "./Array.hpp"

#define MAX_VAL 750

void	deepCopyTest(void) {

	std::cout << "DEEP COPY TEST" << std::endl << std::endl;

	Array<int>	a(10);
	for (int i = 0; i < 10; i++)
		a[i] = i;

	std::cout << "COPY CONSTRUCTOR" << std::endl;
	Array<int>	b(a);
	b[5] = 50;
	std::cout << "A: ";
	for (int i = 0; i < 10; i++)
		std::cout << "[" << a[i] << "] ";
	std::cout << std::endl;
	std::cout << "B: ";
	for (int i = 0; i < 10; i++)
		std::cout << "[" << b[i] << "] ";
	std::cout << std::endl << std::endl;

	std::cout << "ASSIGNATION OPERATOR" << std::endl;
	Array<int>	c;
	c = b;
	c[0] = 100;
	std::cout << "B: ";
	for (int i = 0; i < 10; i++)
		std::cout << "[" << b[i] << "] ";
	std::cout << std::endl;
	std::cout << "C: ";
	for (int i = 0; i < 10; i++)
		std::cout << "[" << c[i] << "] ";
	std::cout << std::endl << std::endl;

}

int	main(void) {

	deepCopyTest();

	// create [numbers] of type Array
    Array<int>	numbers(MAX_VAL);
	// create [mirror] of type int[]
    int*		mirror = new int[MAX_VAL];

	// insert a random number to each element of both arrays
    srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	// SCOPE
	{
		Array<int>	tmp = numbers;
		Array<int>	test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}

	delete [] mirror;

	return 0;
}

#include <iostream>
 #include "./Convert.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Input a literal!!" << std::endl;
		return (1);
	}

	std::string	s = argv[1];

	Convert	c(s);

	std::cout << c;

}

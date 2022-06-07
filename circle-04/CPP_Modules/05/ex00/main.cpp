#include "./Bureaucrat.hpp"

int	main(void) {

	try {
		std::cout << "CONSTRUCTOR WITH 0" << std::endl;
		Bureaucrat	br3("CCC", 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		std::cout << "CONSTRUCTOR WITH 151" << std::endl;
		Bureaucrat	br3("DDD", 151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "CONSTRUCTOR WITH 1, 150" << std::endl;
	Bureaucrat	br1("AAA", 1);
	Bureaucrat	br2("BBB", 150);
	
	std::cout << br1 << std::endl << br2 << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "INCREMENT FROM 1 TO 0" << std::endl;
		br1.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		std::cout << "DECREMENT FROM 150 TO 151" << std::endl;
		br2.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << br1 << std::endl << br2 << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "DECREMENT FROM 1 TO 2" << std::endl;
		br1.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try {
		std::cout << "INCREMENT FROM 150 TO 149" << std::endl;
		br2.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << br1 << std::endl << br2 << std::endl;
	std::cout << std::endl;
}

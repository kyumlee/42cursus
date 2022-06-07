#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int	main(void) {

	{
		std::cout << "CONSTRUCTOR WITH 151, 157" << std::endl;
		try {
			Bureaucrat	br("AAA", 150);
			Form		f("BBB", 151, 157);
			br.signForm(f);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	{
		std::cout << "CONSTRUCTOR WITH 100, 50" << std::endl;
		Bureaucrat	br("AAA", 150);
		Form		f("BBB", 100, 50);
		try {
			std::cout << "BUREAU GRADE(150) > FORM GRADE" << std::endl;
			f.beSigned(br);
		} catch (std::exception &e) {
			e.what();
		}
		br.signForm(f);
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "CONSTRUCTOR WITH 100, 50" << std::endl;
		Bureaucrat	br("AAA", 100);
		Form		f("BBB", 100, 50);
		try {
			std::cout << "BUREAU GRADE(100) == FORM GRADE" << std::endl;
			f.beSigned(br);
		} catch (std::exception &e) {
			e.what();
		}
		br.signForm(f);
		std::cout << std::endl << std::endl;
	}
	
	{
		std::cout << "CONSTRUCTOR WITH 100, 50" << std::endl;
		Bureaucrat	br("AAA", 50);
		Form		f("BBB", 100, 50);
		try {
			std::cout << "BUREAU GRADE(50) < FORM GRADE" << std::endl;
			f.beSigned(br);
		} catch (std::exception &e) {
			e.what();
		}
		br.signForm(f);
		std::cout << std::endl;
	}

}

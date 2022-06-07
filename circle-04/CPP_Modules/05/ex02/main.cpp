#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

int	main(int argc, char **argv) {

	if (argc != 2)	return (1);
	int	a = atoi(argv[1]);
	if (a == 1) {					// b <= f
		{
			Bureaucrat	b("AAA", 137);
			Form		*f	= new ShrubberyCreationForm("SCF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
		std::cout << std::endl;	
		{
			Bureaucrat	b("AAA", 138);
			Form		*f	= new ShrubberyCreationForm("SCF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
	}

	if (a == 2) {					// b <= f
		{
			Bureaucrat	b("AAA", 40);
			Form		*f = new RobotomyRequestForm("RRF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
		std::cout << std::endl;	
		{					// b > f
			Bureaucrat	b("AAA", 46);
			Form		*f = new RobotomyRequestForm("RRF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
	}
	
	if (a == 3) {					// b <= f
		{
			Bureaucrat	b("AAA", 5);
			Form		*f = new PresidentialPardonForm("RRF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
		std::cout << std::endl;	
		{					// b > f
			Bureaucrat	b("AAA", 10);
			Form		*f = new PresidentialPardonForm("RRF");

			try {
				f->beSigned(b);
				f->execute(b);
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
			b.signForm(*f);
			std::cout << std::endl;
			b.executeForm(*f);
			std::cout << std::endl;
		}
	}
}

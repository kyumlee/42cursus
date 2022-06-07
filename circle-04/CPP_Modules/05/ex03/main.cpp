#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Intern.hpp"

int	main(void) {

	Intern	i;
	Form	*rrf;

	rrf = i.makeForm("robotomy request", "Bender");
	rrf	= i.makeForm("some random form", "David");

}

#include "./Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &i) {
	static_cast<void>(i);
}

Intern::~Intern(void) {}

Intern		&Intern::operator=(const Intern &i) {
	static_cast<void>(i);

	return (*this);
}

Form		*createSCF(std::string target) { return (new ShrubberyCreationForm(target)); }

Form		*createRRF(std::string target) { return (new RobotomyRequestForm(target)); }

Form		*createPPF(std::string target) { return (new PresidentialPardonForm(target)); }

Form		*Intern::makeForm(std::string name, std::string target) {
	int			i;
	std::string	forms[3]				= { SC, RR, PP };
	Form		*(*ret[3])(std::string)	= { createSCF, createRRF, createPPF };

	try {
		for (i = 0; i < 3; i++) {
			if (name == forms[i]) {
				std::cout << "Intern creates <" << target << ">." << std::endl;
				return (ret[i](target));
			}
		}
		throw UnknownFormException();
	} catch (std::exception &e) {
		std::cerr << "Intern cannot create <" << target << ">, because <" << e.what() << ">." << std::endl;
	}
	return (0);
}

const char	*Intern::UnknownFormException::what(void) const throw() {
	return ("Form type is unknown. (shrubbery creation, robotomy request, presidential pardon)");
}

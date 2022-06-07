#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"

# define SC	"shrubbery creation"
# define RR	"robotomy request"
# define PP	"presidential pardon"

class	Intern {

	public:
		Intern(void);
		Intern(const Intern &i);
		~Intern(void);
		Intern	&operator=(const Intern &i);

		Form	*makeForm(std::string name, std::string target);
		
		class	UnknownFormException : public std::exception {
			const char	*what(void) const throw();
		};

};

#endif

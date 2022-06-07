#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
# define __ROBOTOMY_REQUEST_FORM_HPP__

# include "./Form.hpp"

class	RobotomyRequestForm : public Form {

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &name);
		RobotomyRequestForm(const RobotomyRequestForm &rrf);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rrf);

		virtual void			execute(Bureaucrat const &executor) const;

};

#endif

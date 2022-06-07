#ifndef __SHRUBBERY_CREATION_FORM_HPP__
# define __SHRUBBERY_CREATION_FORM_HPP__

# include "./Form.hpp"

class	ShrubberyCreationForm : public Form {

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &name);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &scf);

		virtual void			execute(Bureaucrat const &executor) const;

};

#endif

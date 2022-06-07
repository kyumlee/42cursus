#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
# define __PRESIDENTIAL_PARDON_FORM_HPP__

# include "./Form.hpp"

class	PresidentialPardonForm : public Form {

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &name);
		PresidentialPardonForm(const PresidentialPardonForm &ppf);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &ppf);

		virtual void			execute(Bureaucrat const &executor) const;

};

#endif

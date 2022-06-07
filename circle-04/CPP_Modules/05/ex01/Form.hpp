#ifndef __FORM_HPP__
# define __FORM_HPP__

# include "./Bureaucrat.hpp"

class	Form {

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form(void);
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &f);
		~Form(void);

		Form				&operator=(const Form &f);

		const std::string	&getName(void) const;
		const bool			&getSign(void) const;
		const int			&getSignGrade(void) const;
		const int			&getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat &br);

		class				GradeTooHighException : public std::exception {
			const char		*what(void) const throw();
		};
		class				GradeTooLowException : public std::exception {
			const char		*what(void) const throw();
		};

};

std::ostream				&operator<<(std::ostream &os, const Form &f);

#endif

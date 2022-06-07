#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include <exception>

class	Bureaucrat {

	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &br);
		~Bureaucrat(void);
		Bureaucrat			&operator=(const Bureaucrat &br);

		std::string			getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);

		class				GradeTooHighException : public std::exception {
			public:
				const char	*what(void) const throw();
		};
		class				GradeTooLowException : public std::exception {
			public:
				const char	*what(void) const throw();
		};

};

std::ostream				&operator<<(std::ostream &os, const Bureaucrat &br);

#endif

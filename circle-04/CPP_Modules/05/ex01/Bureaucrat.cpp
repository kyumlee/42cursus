#include "./Bureaucrat.hpp"
#include "./Form.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)		throw GradeTooHighException();
	if (_grade > 150)	throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &br) : _name(br.getName()), _grade(br.getGrade()) {
	if (_grade < 1)		throw GradeTooHighException();
	if (_grade > 150)	throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &br) {
	if (this != &br) {
		static_cast<std::string>(_name)	= br.getName();
		_grade							= br.getGrade();
	}

	return (*this);
}

std::string		Bureaucrat::getName(void) const { return (_name); }

int				Bureaucrat::getGrade(void) const { return (_grade); }

void			Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)		throw GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)	throw GradeTooLowException();
	_grade++;
}

void			Bureaucrat::signForm(const Form &f) {
	try {
		if (!f.getSign())	throw (GradeTooLowException());
			std::cout << "<" << _name << "> signs <" << f.getName() << ">.";
	} catch (std::exception &e) {
		std::cout << "<" << _name << "> cannot sign <" << f.getName() << "> because <" << e.what() << ">." << std::endl;
	}
}

const char		*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high! Highest possible grade is 1.");
}

const char		*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low! Lowest possible grade is 150. (or should be high enough to sign a form)");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &br) {
	os << "<" << br.getName() << ">, bureaucrat grade <" << br.getGrade() << ">.";

	return (os);
}

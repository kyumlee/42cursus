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
	if (f.getSign())
		std::cout << "<" << _name << "> signs <" << f.getName() << ">.";
	else {
		std::cout << "<" << _name << "> cannot sign <" << f.getName() << "> because <";
		if (_grade > f.getSignGrade())
			std::cout << _name << "'s grade is lower than " << f.getName() << "'s grade>.";
	}
}

void			Bureaucrat::executeForm(const Form &f) {
	if (f.getSign() && _grade <= f.getExecuteGrade())
		std::cout << "<" << _name << "> executes <" << f.getName() << ">.";
	else {
		std::cout << "<" << _name << "> cannot execute <" << f.getName() << ">.";
	}
}

const char		*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high! Highest possible grade is 1.");
}

const char		*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low! Lowest possible grade is 150.");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &br) {
	os << "<" << br.getName() << ">, bureaucrat grade <" << br.getGrade() << ">.";

	return (os);
}

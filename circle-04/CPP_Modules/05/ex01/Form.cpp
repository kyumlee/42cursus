#include "./Form.hpp"

Form::Form(void) : _name(0), _signed(0), _signGrade(0), _executeGrade(0) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signed(0), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (_signGrade < 1 || _executeGrade < 1)		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)	throw GradeTooLowException();
}

Form::Form(const Form &f) : _name(f.getName()), _signed(f.getSign()), _signGrade(f.getSignGrade()), _executeGrade(f.getExecuteGrade()) {
	if (_signGrade < 1 || _executeGrade < 1)		throw GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)	throw GradeTooLowException();
}

Form::~Form(void) {}

Form				&Form::operator=(const Form &f) {
	if (this != &f) {
		*(const_cast<std::string *>(&_name))	= f.getName();
		_signed									= f.getSign();
		*(const_cast<int *>(&_signGrade))		= f.getSignGrade();
		*(const_cast<int *>(&_executeGrade))	= f.getExecuteGrade();
	}

	return (*this);
}

const std::string	&Form::getName(void) const { return (_name); }

const bool			&Form::getSign(void) const { return (_signed); }

const int			&Form::getSignGrade(void) const { return (_signGrade); }

const int			&Form::getExecuteGrade(void) const { return (_executeGrade); }

void				Form::beSigned(const Bureaucrat &br) {
	if (br.getGrade() > _signGrade)	throw GradeTooLowException();
	_signed = true;
}

const char			*Form::GradeTooHighException::what(void) const throw() {
	return ("Grade is too high! Highest possible grade is 1.");
}

const char			*Form::GradeTooLowException::what(void) const throw() {
	return ("Grade is too low! Lowest possible grade is 150.");
}

std::ostream		&operator<<(std::ostream &os, const Form &f) {
	os << "<" << f.getName() << "> is ";
	if (!f.getSign()) os << "not ";
	os << "signed" << std::endl;
	os << "Grade required to sign : " << f.getSignGrade() << std::endl;
	os << "Grade required to execute : " << f.getExecuteGrade();

	return (os);
}

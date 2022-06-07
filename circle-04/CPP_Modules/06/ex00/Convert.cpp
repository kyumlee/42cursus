#include "./Convert.hpp"

Convert::Convert(void) {
	throw NoParameterException();
}

Convert::Convert(const std::string &input) : _input(input), _type(-1), _c(0), _i(0), _f(0.0f), _d(0.0) {
	detectType();
	convert();
}

Convert::Convert(const Convert &cvt) {
	_input	= cvt.getInput();
	_type	= cvt.getType();
	_c		= cvt.getC();
	_i		= cvt.getI();
	_f		= cvt.getF();
	_d		= cvt.getD();
}

Convert::~Convert(void) {}

Convert			&Convert::operator=(const Convert &cvt) {
	_input	= cvt.getInput();
	_type	= cvt.getType();
	_c		= cvt.getC();
	_i		= cvt.getI();
	_f		= cvt.getF();
	_d		= cvt.getD();

	return (*this);
}

std::string		Convert::getInput(void) const { return (_input); }

int				Convert::getType(void) const { return (_type); }

void			skipWhitespaces(std::string str, unsigned long *idx) {
	for (unsigned long i = 0; std::isspace(str[i]); i++)
		(*idx)++;
}

void			skipDigits(std::string str, unsigned long *idx) {
	for (unsigned long i = 0; std::isdigit(str[i]); i++)
		(*idx)++;
}

bool			Convert::isPseudo(void) const {
	if (_input == "nan" || _input == "nanf"
		|| _input == "inf" || _input == "inff"
		|| _input == "+inf" || _input == "+inff"
		|| _input == "-inf" || _input == "-inff")
		return (true);
	return (false);
}

bool			Convert::isChar(void) const {
	if (_input.length() == 1 && !std::isdigit(_input[0]))
		return (true);
	return (false);
}

bool			Convert::isInt(void) const {
	unsigned long	i = 0;
	
	skipWhitespaces(&_input[i], &i);
	if (_input[i] == '-' || _input[i] == '+')
		i++;
	skipDigits(&_input[i], &i);
	if (!_input[i] && _input.length())
		return (true);
	return (false);
}

bool			Convert::isFloat(void) const {
	unsigned long	i = 0;

	skipWhitespaces(&_input[i], &i);
	if (_input[i] == '-' || _input[i] == '+')
		i++;
	skipDigits(&_input[i], &i);
	if (_input[i] == 'f')
		return (true);
	else if (_input[i] == '.' && _input[i + 1]) {
		i++;
		skipDigits(&_input[i], &i);
		if (_input[i] == 'f' && !_input[i + 1])
			return (true);
	}
	return (false);
}

bool			Convert::isDouble(void) const {
	unsigned long	i = 0;

	skipWhitespaces(&_input[i], &i);
	if (_input[i] == '-' || _input[i] == '+')
		i++;
	skipDigits(&_input[i], &i);
	if (_input[i] == '.' && _input[i + 1]) {
		i++;
		skipDigits(&_input[i], &i);
		if (!_input[i])
			return (true);
	}
	return (false);
}

bool			Convert::isInIntRange(void) const {
	long	i = std::atol(_input.c_str());

	if (i > 2147483647 || i < -2147483648)
		return (false);
	return (true);
}

void			Convert::detectType(void) {
	if (isPseudo())
		_type	= PSEUDO;
	else if (isChar())
		_type	= CHAR;
	else if (isInt())
		_type	= INT;
	else if (isFloat())
		_type	= FLOAT;
	else if (isDouble())
		_type	= DOUBLE;
	else
		_type	= ERROR;
	std::cout << "TYPE: " << _type << std::endl;
}


char			Convert::getC(void) const { return (_c); }

int				Convert::getI(void) const { return (_i); }

float			Convert::getF(void) const { return (_f); }

double			Convert::getD(void) const { return (_d); }

void			Convert::convert(void) {
	switch (_type) {
		case CHAR:
			_c = _input[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break;

		case INT:
			_i = std::atoi(_input.c_str());
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break;

		case FLOAT:
			_f = std::atof(_input.c_str());
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break;

		case DOUBLE:
		case PSEUDO:
			_d = std::strtod(_input.c_str(), NULL);
			_c = static_cast<char>(_d);
			_i = static_cast<int>(_d);
			_f = static_cast<float>(_d);
			break;
	}
}

void			Convert::printChar(std::ostream &os) const {
	os << "char: ";

	if (_type == ERROR || _type == PSEUDO)
		os << "impossible";
	else if (_c >= 32 && _c <= 127)
		os <<  '\'' << _c << '\'';
	else if (_c < 32 || _c > 127)
		os << "Non displayable";

	os << std::endl;
}

void			Convert::printInt(std::ostream &os) const {
	os << "int: ";

	if (_type == ERROR || _type == PSEUDO || !isInIntRange())
		os << "impossible";
	else
		os << _i;

	os << std::endl;
}

void			Convert::printFloat(std::ostream &os) const {
	os << "float: ";

	if (_type == ERROR || (_type == INT && !isInIntRange()))
		os << "impossible";
	else
		os << std::fixed << std::setprecision(1) << _f << "f";

	os << std::endl;
}

void			Convert::printDouble(std::ostream &os) const {
	os << "double: ";

	if (_type == ERROR || (_type == INT && !isInIntRange()))
		os << "impossible";
	else
		os << _d;

	os << std::endl;
}

const char		*Convert::NoParameterException::what(void) const throw() {
	return ("Input a literal!!");
}

std::ostream	&operator<<(std::ostream &os, const Convert &cvt) {
	cvt.printChar(os);
	cvt.printInt(os);
	cvt.printFloat(os);
	cvt.printDouble(os);

	return (os);
}

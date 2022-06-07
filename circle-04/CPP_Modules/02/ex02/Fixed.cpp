#include "./Fixed.hpp"

Fixed::Fixed(void) {
//	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
};

Fixed::Fixed(const int intValue) {
//	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = intValue << FRACTIONAL_BITS;
}

Fixed::Fixed(const float floatValue) {
//	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(floatValue * (1 << FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &f) {
//	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = f.getRawBits();
};

Fixed::~Fixed(void) {
//	std::cout << "Destructor called" << std::endl;
};

Fixed			&Fixed::operator=(const Fixed &f) {
	if (this != &f)
		fixedPointValue = f.getRawBits();
	return (*this);
}

bool			Fixed::operator>(const Fixed &f) { return (fixedPointValue > f.fixedPointValue); };

bool			Fixed::operator<(const Fixed &f) { return (fixedPointValue < f.fixedPointValue); };

bool			Fixed::operator>=(const Fixed &f) { return (fixedPointValue >= f.fixedPointValue); };

bool			Fixed::operator<=(const Fixed &f) { return (fixedPointValue <= f.fixedPointValue); };

bool			Fixed::operator==(const Fixed &f) { return (fixedPointValue == f.fixedPointValue); };

bool			Fixed::operator!=(const Fixed &f) { return (fixedPointValue != f.fixedPointValue); };

Fixed			Fixed::operator+(const Fixed &f) { return (Fixed(this->toFloat() + f.toFloat())); };

Fixed			Fixed::operator-(const Fixed &f) { return (Fixed(this->toFloat() - f.toFloat())); };

Fixed			Fixed::operator*(const Fixed &f) { return (Fixed(this->toFloat() * f.toFloat())); };

Fixed			Fixed::operator/(const Fixed &f) { return (Fixed(this->toFloat() / f.toFloat())); };

Fixed			&Fixed::operator++(void) {
	fixedPointValue++;
	return (*this);
};

Fixed			&Fixed::operator--(void) {
	fixedPointValue--;
	return (*this);
};

Fixed			Fixed::operator++(int) {
	Fixed	temp(*this);

	fixedPointValue++;
	return (temp);
};

Fixed			Fixed::operator--(int) {
	Fixed	temp(*this);

	fixedPointValue--;
	return (temp);
};

int				Fixed::getRawBits(void) const { return (fixedPointValue); };

void			Fixed::setRawBits(int const raw) { fixedPointValue = raw; };

float			Fixed::toFloat(void) const {
	return ((float)fixedPointValue / (1 << FRACTIONAL_BITS));
};

int				Fixed::toInt(void) const {
	return (fixedPointValue >> FRACTIONAL_BITS);
};

const Fixed		&Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.fixedPointValue < f2.fixedPointValue) return (f1);
	else return (f2);
};

const Fixed 	&Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.fixedPointValue > f2.fixedPointValue) return (f1);
	else return (f2);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &f) {
	os << f.toFloat();
	return (os);
}

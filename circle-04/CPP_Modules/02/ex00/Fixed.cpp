#include "./Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
};

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = f.getRawBits();
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};

Fixed	&Fixed::operator=(const Fixed &f) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &f)	fixedPointValue = f.getRawBits();

	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointValue);
};

void	Fixed::setRawBits(int const raw) { fixedPointValue = raw; };

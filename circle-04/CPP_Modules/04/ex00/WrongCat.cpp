#include "./WrongCat.hpp"

/* WRONGW_CAT CLASS */

WrongCat::WrongCat(void) {
	_type = "WrongCat";

	std::cout << W_CAT << "Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) {
	_type = cat.getType();

	std::cout << W_CAT << "Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << W_CAT << "Destructor called" << std::endl;
}

WrongCat			&WrongCat::operator=(const WrongCat &cat) {
	_type = cat.getType();

	std::cout << W_CAT << "Assignation operator called" << std::endl;

	return (*this);
}

void		WrongCat::makeSound(void) const {
	std::cout << W_CAT << "Meow~" << std::endl;
}

#include "./Cat.hpp"

/* CAT CLASS */

Cat::Cat(void) {
	_type = "Cat";

	std::cout << CAT << "Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	_type = cat.getType();

	std::cout << CAT << "Copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << CAT << "Destructor called" << std::endl;
}

Cat				&Cat::operator=(const Cat &cat) {
	_type = cat.getType();

	std::cout << CAT << "Assignation operator called" << std::endl;

	return (*this);
}

void			Cat::makeSound(void) const {
	std::cout << CAT << "Meow~" << std::endl;
}

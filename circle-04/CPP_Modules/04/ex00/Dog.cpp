#include "./Dog.hpp"

/* DOG CLASS */

Dog::Dog(void) {
	_type = "Dog";

	std::cout << DOG << "Default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	_type = dog.getType();

	std::cout << DOG << "Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << DOG << "Destructor called" << std::endl;
}

Dog				&Dog::operator=(const Dog &dog) {
	_type = dog.getType();

	std::cout << DOG << "Assignation operator called" << std::endl;

	return (*this);
}

void			Dog::makeSound(void) const {
	std::cout << DOG << "Bark!" << std::endl;
}

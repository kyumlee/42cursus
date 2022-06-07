#include "./Dog.hpp"

/* DOG CLASS */

Dog::Dog( void ) {
	_type	= "Dog";
	_brain	= new Brain();

	std::cout << DOG << "Default constructor called" << std::endl;
}

Dog::Dog( const Dog& dog ) {
	_type	= dog.getType();
	_brain	= new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, dog.getBrain()->getIdea(i));

	std::cout << DOG << "Copy constructor called" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << DOG << "Destructor called" << std::endl;
	delete _brain;
}

Dog&			Dog::operator=( const Dog& dog ) {
	_type	= dog.getType();
	_brain	= new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, dog.getBrain()->getIdea(i));
	
	std::cout << DOG << "Assignation operator called" << std::endl;

	return ( *this );
}

void			Dog::makeSound( void ) const {
	std::cout << DOG << "Bark!" << std::endl;
}

Brain*			Dog::getBrain( void ) const { return ( _brain ); }

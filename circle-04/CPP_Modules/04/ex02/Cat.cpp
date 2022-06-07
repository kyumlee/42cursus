#include "./Cat.hpp"

/* CAT CLASS */

Cat::Cat( void ) {
	_type	= "Cat";
	_brain	= new Brain();

	std::cout << CAT << "Default constructor called" << std::endl;
}

Cat::Cat( const Cat& cat ) {
	_type	= cat.getType();
	_brain	= new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, cat.getBrain()->getIdea(i));

	std::cout << CAT << "Copy constructor called" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << CAT << "Destructor called" << std::endl;
	delete _brain;
}

Cat&			Cat::operator=(const Cat& cat ) {
	_type	= cat.getType();
	_brain	= new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, cat.getBrain()->getIdea(i));

	std::cout << CAT << "Assignation operator called" << std::endl;

	return ( *this );
}

void			Cat::makeSound( void ) const {
	std::cout << CAT << "Meow~" << std::endl;
}

Brain*			Cat::getBrain( void ) const { return ( _brain ); }

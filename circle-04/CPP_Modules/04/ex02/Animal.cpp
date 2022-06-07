#include "./Animal.hpp"

/* ANIMAL CLASS */

Animal::Animal( void ) {
	std::cout << AN << "Default constructor called" << std::endl;
}

Animal::Animal( std::string type ) : _type( type ) {
	std::cout << AN << "Constructor called" << std::endl;
}

Animal::Animal( const Animal& an ) {
	_type = an.getType();

	std::cout << AN << "Copy constructor called" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << AN << "Destructor called" << std::endl;
}

Animal&			Animal::operator=( const Animal& an ) {
	_type = an.getType();

	std::cout << AN << "Assignation operator called" << std::endl;

	return ( *this );
}

void			Animal::makeSound( void ) const {
	std::cout << AN << "Cannot make any sound. Type of an animal is not specified." << std::endl;
}

std::string		Animal::getType( void ) const { return ( _type ); }

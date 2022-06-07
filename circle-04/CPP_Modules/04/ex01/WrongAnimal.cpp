#include "./WrongAnimal.hpp"

/* WRONGW_ANIMAL CLASS */

WrongAnimal::WrongAnimal( void ) {
	std::cout << W_AN << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
	std::cout << W_AN << "Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& an ) {
	_type = an.getType();

	std::cout << W_AN << "Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << W_AN << "Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& an ) {
	_type = an.getType();

	std::cout << W_AN << "Assignation operator called" << std::endl;

	return ( *this );
}

void			WrongAnimal::makeSound( void ) const {
	std::cout << W_AN << "(WRONG ANIMAL CLASS) Cannot make any sound. Type of an animal is not specified." << std::endl;
}

std::string		WrongAnimal::getType( void ) const { return ( _type ); }

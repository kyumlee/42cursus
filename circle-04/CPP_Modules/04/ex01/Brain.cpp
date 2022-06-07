#include "./Brain.hpp"

/* BRAIN CLASS */

Brain::Brain( void ) {
	std::cout << BR << "Default constructor called" << std::endl;
}

Brain::Brain( const Brain& br ) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = br.getIdea(i);
}

Brain::~Brain( void ) {
	std::cout << BR << "Destructor called" << std::endl;
}

Brain&			Brain::operator=( const Brain& br ) {
	if (this != &br) *this = br;

	return ( *this );
}

std::string		Brain::getIdea( int index ) const {
	return ( _ideas[index] );
}

void			Brain::setIdea( int index, std::string idea ) {
	_ideas[index] = idea;
}

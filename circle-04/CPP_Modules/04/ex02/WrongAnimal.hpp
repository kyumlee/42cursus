#ifndef __WRONG_ANIMAL_HPP__
# define __WRONG_ANIMAL_HPP__

# include "./Animal.hpp"

# define W_AN	"[ WRONG ANIMAL ] "

class	WrongAnimal {

	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& an );
		virtual			~WrongAnimal( void );

		WrongAnimal&	operator=( const WrongAnimal& an );
		void			makeSound( void ) const;

		std::string		getType( void ) const;

};

#endif

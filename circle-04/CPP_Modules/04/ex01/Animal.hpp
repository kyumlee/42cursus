#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

# include <iostream>

# define AN		"[    ANIMAL    ] "

class	Animal {

	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& an );
		virtual			~Animal( void );

		Animal&			operator=( const Animal& an );

		virtual void	makeSound( void ) const;

		std::string		getType( void ) const;

};

#endif

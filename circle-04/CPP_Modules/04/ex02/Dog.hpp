#ifndef __DOG_HPP__
# define __DOG_HPP__

# include "./Animal.hpp"
# include "./Brain.hpp"

# define DOG	"[     DOG      ] "

class	Dog : public Animal {

	private:
		Brain*	_brain;

	public:
		Dog( void );
		Dog( const Dog& dog );
		virtual			~Dog( void );

		Dog&			operator=( const Dog& dog );
		virtual void	makeSound( void ) const;
		Brain*			getBrain( void ) const;

};

#endif

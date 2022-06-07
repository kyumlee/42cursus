#ifndef __CAT_HPP__
# define __CAT_HPP__

# include "./Animal.hpp"
# include "./Brain.hpp"

# define CAT	"[     CAT      ] "

class	Cat : public Animal {

	private:
		Brain*	_brain;

	public:
		Cat( void );
		Cat( const Cat& cat );
		virtual			~Cat( void );

		Cat&			operator=(const Cat& cat);
		virtual void	makeSound( void ) const;
		Brain*			getBrain( void ) const;

};

#endif

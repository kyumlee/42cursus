#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include "./Animal.hpp"

# define BR		"[    BRAIN     ] "

class	Brain {

	private:
		std::string	_ideas[100];

	public:
		Brain( void );
		Brain( const Brain& br );
		~Brain( void );
		Brain&			operator=( const Brain& br );

		std::string		getIdea( int index ) const;
		void			setIdea( int index, std::string idea );
};

#endif

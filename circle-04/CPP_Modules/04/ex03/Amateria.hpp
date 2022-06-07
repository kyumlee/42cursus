#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__

# include <iostream>
# include "./ICharacter.hpp"

class	AMateria {

	protected:
		std::string			_type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &am);
		virtual				~AMateria(void);

		AMateria			&operator=(const AMateria &am);

		std::string	const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif

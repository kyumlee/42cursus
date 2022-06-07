#ifndef __ICE_HPP__
# define __ICE_HPP__

# include "./Amateria.hpp"

class	Ice : public AMateria {

	public:
		Ice(void);
		Ice(const Ice &ice);
		~Ice(void);
		Ice				&operator=(const Ice &ice);

		virtual Ice		*clone(void) const;
		virtual void	use(ICharacter &target);

};

#endif

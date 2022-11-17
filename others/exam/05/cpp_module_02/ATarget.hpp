#ifndef __ATARGET_HPP__
# define __ATARGET_HPP__

# include <iostream>

class	ASpell;

class	ATarget {
	protected:
		std::string	_type;

	public:
		ATarget();
		ATarget(std::string const& type);
		ATarget(ATarget const& at);
		ATarget&			operator=(ATarget const& at);
		virtual ~ATarget();

		std::string const&	getType() const;

		virtual	ATarget*	clone() const = 0;

		void				getHitBySpell(const ASpell& asp) const;
};

# include "./ASpell.hpp"

#endif

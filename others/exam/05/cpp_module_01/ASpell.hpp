#ifndef __ASPELL_HPP__
# define __ASPELL_HPP__

# include <iostream>

class	ATarget;

class	ASpell {
	protected:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell();
		ASpell(std::string const& name, std::string const& effects);
		ASpell(ASpell const& asp);
		ASpell&				operator=(ASpell const& asp);
		virtual ~ASpell();

		std::string const&	getName() const;
		std::string const&	getEffects() const;

		virtual ASpell*		clone() const = 0;

		void				launch(ATarget const& at) const;
};

# include "./ATarget.hpp"

#endif

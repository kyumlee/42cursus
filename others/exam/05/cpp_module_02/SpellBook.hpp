#ifndef __SPELL_BOOK_HPP__
# define __SPELL_BOOK_HPP__

# include <iostream>
# include <map>
# include "./ASpell.hpp"

class	SpellBook {
	private:
		std::map<std::string, ASpell*>	_sb;
	public:
		SpellBook();
		~SpellBook();
		void	learnSpell(ASpell* asp);
		void	forgetSpell(std::string const& spell);
		ASpell*	createSpell(std::string const& spell);
};

#endif

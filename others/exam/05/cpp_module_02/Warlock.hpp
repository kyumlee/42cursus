#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

# include <iostream>
# include <map>

# include "./ATarget.hpp"
# include "./ASpell.hpp"
# include "./SpellBook.hpp"

class	Warlock {
	private:
		std::string	_name;
		std::string	_title;
		SpellBook	_book;

	public:
		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(const std::string& title);
		Warlock(std::string name, std::string title);
		void				introduce() const;
		~Warlock();

		void				learnSpell(ASpell* asp);
		void				forgetSpell(std::string);
		void				launchSpell(std::string, ATarget const& at);
};

#endif

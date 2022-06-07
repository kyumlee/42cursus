#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include "./ICharacter.hpp"
# include "./Amateria.hpp"

class	Character : public ICharacter {
	
	private:
		std::string					_name;
		AMateria					**_inven;

	public:
		Character(void);
		Character(std::string name);
		Character(const Character &ch);
		virtual						~Character(void);

		Character					&operator=(const Character &ch);
		virtual std::string const	&getName(void) const;
		AMateria					*getInven(int idx) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);

};

#endif

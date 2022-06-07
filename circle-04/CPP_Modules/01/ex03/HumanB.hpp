#ifndef	__HUMAN_B_HPP__
# define __HUMAN_B_HPP__

# include "./Weapon.hpp"

class	HumanB {

private:
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);
	void		setWeapon(Weapon &weapon);
	void		attack(void);
};

#endif

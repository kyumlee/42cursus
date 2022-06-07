#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <iostream>

class	Weapon {

private:
	std::string	_type;

public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	const std::string	&getType(void);
	void				setType(std::string type);
};

#endif

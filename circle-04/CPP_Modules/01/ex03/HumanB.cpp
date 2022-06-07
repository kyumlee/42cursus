#include "./HumanB.hpp"

HumanB::HumanB(std::string name): _name(name) {
	_weapon = 0;
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void	HumanB::attack(void) {
	std::cout << _name;
	if (!_weapon) std::cout << " doesn't have a weapon" << std::endl;
	else std::cout << " attacks with his " << _weapon->getType() << std::endl;
}

#include "./Weapon.hpp"

Weapon::Weapon(void) {
	_type = "default";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon(void) {}

const std::string	&Weapon::getType(void) {
	const std::string	&type = _type;

	return (type);
}

void				Weapon::setType(std::string type) {
	_type = type;
}

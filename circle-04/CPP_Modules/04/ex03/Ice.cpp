#include "./Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &ice) { _type = ice.getType(); }

Ice::~Ice(void) {}

Ice		&Ice::operator=(const Ice &ice) {
	_type = ice.getType();

	return (*this);
}

Ice		*Ice::clone(void) const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

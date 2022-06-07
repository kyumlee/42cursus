#include "./Amateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &am) {
	(void)am;
}

AMateria::~AMateria(void) {}

AMateria			&AMateria::operator=(const AMateria &am) {
	(void)am;

	return (*this);
}

std::string	const	&AMateria::getType(void) const { return (_type); }

void				AMateria::use(ICharacter &target) {
	std::cout << target.getName() << std::endl;
}

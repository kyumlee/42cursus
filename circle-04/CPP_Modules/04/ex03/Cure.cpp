#include "./Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &cure) { _type = cure.getType(); }

Cure::~Cure(void) {}

Cure	&Cure::operator=(const Cure &cure) {
	_type = cure.getType();

	return (*this);
}

Cure	*Cure::clone(void) const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

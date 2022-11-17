#include "./ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const& type) {
	_type = type;
}

ATarget::ATarget(ATarget const& at) : _type(at._type) {}

ATarget&			ATarget::operator=(ATarget const& at) {
	_type = at._type;
	return (*this);
}

ATarget::~ATarget() {}

std::string const&	ATarget::getType() const { return (_type); }

void				ATarget::getHitBySpell(const ASpell& asp) const {
	std::cout << _type << " has been " << asp.getEffects() << "!" << std::endl;
}

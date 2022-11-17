#include "./ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects) {}

ASpell::ASpell(ASpell const& asp) : _name(asp._name), _effects(asp._effects) {}

ASpell&				ASpell::operator=(ASpell const& asp) {
	_name = asp._name;
	_effects = asp._effects;
	return (*this);
}

ASpell::~ASpell() {}

std::string const&	ASpell::getName() const { return (_name); }
std::string const&	ASpell::getEffects() const { return (_effects); }

void				ASpell::launch(const ATarget& at) const {
	at.getHitBySpell((*this));
}

#include "./SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {
	for (std::map<std::string, ASpell*>::iterator it = _sb.begin(); it != _sb.end(); it++)
		delete (it->second);
	_sb.clear();
}

void	SpellBook::learnSpell(ASpell* asp) {
	if (asp)
		_sb.insert(std::pair<std::string, ASpell*>(asp->getName(), asp->clone()));
}
void	SpellBook::forgetSpell(std::string const& spell) {
	std::map<std::string, ASpell*>::iterator it = _sb.find(spell);
	if (it != _sb.end())
		delete (it->second);
	_sb.erase(spell);
}
ASpell*	SpellBook::createSpell(std::string const& spell) {
	std::map<std::string, ASpell*>::iterator it = _sb.find(spell);
	if (it != _sb.end())
		return (_sb[spell]);
	return (0);
}

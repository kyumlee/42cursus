#include "./Warlock.hpp"

const std::string&	Warlock::getName() const { return (_name); }

const std::string&	Warlock::getTitle() const { return (_title); }

void				Warlock::setTitle(const std::string& title) { _title = title; }

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

void				Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void				Warlock::learnSpell(ASpell* asp) {
	if (asp)
		_spells.insert(std::pair<std::string, ASpell*>(asp->getName(), asp->clone()));
}
void				Warlock::forgetSpell(std::string spell) {
	std::map<std::string, ASpell*>::iterator it = _spells.find(spell);
	if (it != _spells.end())
		delete (it->second);
	_spells.erase(spell);
}
void				Warlock::launchSpell(std::string spell, ATarget const& at) {
	ASpell*	tmp = _spells[spell];
	if (tmp)
		tmp->launch(at);
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); it++)
		delete (it->second);
	_spells.clear();
}

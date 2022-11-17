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
	_book.learnSpell(asp);
}
void				Warlock::forgetSpell(std::string spell) {
	_book.forgetSpell(spell);
}
void				Warlock::launchSpell(std::string spell, ATarget const& at) {
	if (&at == (ATarget const*)0)
		return ;
	_book.createSpell(spell)->launch(at);
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

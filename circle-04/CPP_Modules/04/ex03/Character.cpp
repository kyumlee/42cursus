#include "./Character.hpp"

Character::Character(void) : _name("Default") {
	_inven = new AMateria *[4];
	for (int i = 0; i < 4; i++)
		_inven[i] = 0;
}

Character::Character(std::string name) : _name(name) {
	_inven = new AMateria *[4];
	for (int i = 0; i < 4; i++)
		_inven[i] = 0;
}

Character::Character(const Character &ch) {
	delete _inven;

	_name		= ch.getName();
	_inven		= new AMateria *[4];
	for (int i = 0; i < 4; i++) {
		_inven[i] = ch.getInven(i);
	}
}

Character::~Character(void) {
	delete _inven;
}

Character			&Character::operator=(const Character &ch) {
	delete _inven;

	_name		= ch.getName();
	_inven		= new AMateria *[4];
	for (int i = 0; i < 4; i++)
		_inven[i] = ch.getInven(i);

	return (*this);
}

std::string const	&Character::getName(void) const { return (_name); }

AMateria			*Character::getInven(int idx) const { return (_inven[idx]); }

void				Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_inven[i]) {
			_inven[i] = m;
			return ;
		}
	}
}

void				Character::unequip(int idx) {
	if (!(idx >= 0 && idx <= 3)) return ;
	_inven[idx] = 0;
}

void				Character::use(int idx, ICharacter &target) {
	if (!(idx >= 0 && idx <= 3)) return ;
	if (!_inven[idx])
		std::cout << "inven at [" << idx << "] is empty. Equip first." << std::endl;
	else if (_inven[idx]) _inven[idx]->use(target);
}

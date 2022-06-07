#include "./MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < 4; i++) _memory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &ms) {
	for (int i = 0; i < 4; i++) {
		delete _memory[i];
		_memory[i] = ms.getMemory(i);
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		delete _memory[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &ms) {
	for (int i = 0; i < 4; i++) {
		delete _memory[i];
	   _memory[i] = ms.getMemory(i);
	}

	return (*this);
}

void			MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (!_memory[i]) {
			_memory[i] = m;
			break ;
		}
	}
}

AMateria		*MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++)
		if (_memory[i]->getType() == type)
			return (_memory[i]->clone());
	return (0);
}

AMateria		*MateriaSource::getMemory(int idx) const {
	if (!(idx >= 0 && idx <= 3)) return (0);
	return (_memory[idx]);
}

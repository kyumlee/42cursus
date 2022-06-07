#include "./Zombie.hpp"

Zombie::Zombie(void) {
	_name = "default";
}

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie(void) {
	std::cout << "<" << _name << ">" << " destructed" << std::endl;
}

void	Zombie::setName(std::string name, int i) {
	_name = name + std::to_string(i + 1);
}

void	Zombie::announce(void) {
	std::cout << "<" << _name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

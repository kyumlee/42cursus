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

void	Zombie::announce(void) {
	std::cout << "<" << _name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

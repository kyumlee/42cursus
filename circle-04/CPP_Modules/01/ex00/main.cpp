#include <string>
#include "./Zombie.hpp"

int	main(void) {
	std::string	name1 = "kyumlee";
	std::string	name2 = "david";
	std::string	name3 = "lee";

	// STACK
	Zombie	zombie(name1);
	zombie.announce();
	std::cout << std::endl;

	// HEAP
	Zombie	*zombie2 = newZombie(name2);
	zombie2->announce();
	delete (zombie2);
	std::cout << std::endl;

	// STACK
	randomChump(name3);
	std::cout << std::endl;

	return (0);
}

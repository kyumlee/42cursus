#include "./Zombie.hpp"
#include <string>

int	main(void) {
	int			n;
	std::string	name = "";
	Zombie		*horde;

	std::cout << "Number of zombies: ";
	std::cin >> n;
	std::cin.ignore(1, '\n');
	if (n < 1) {
		std::cerr << "INPUT MUST BE AN INTEGER GREATER THAN ZERO" << std::endl;
		return (1);
	}

	std::cout << std::endl;
	while (name == "") {
		std::cout << "Base name of zombies: ";
		std::getline(std::cin, name);
	}

	std::cout << std::endl;
	horde = zombieHorde(n, name);
	// horde->announce();
	for (int i = 0; i < n; i++)
		horde[i].announce();

	std::cout << std::endl;
	delete [] horde;

	std::cout << std::endl;
	return (0);
}

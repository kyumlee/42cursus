#include "./ClapTrap.hpp"

int	main(void) {
	ClapTrap	ct1("AAA");
	ClapTrap	ct2("BBB");

	std::cout << std::endl;
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDamage());
	ct2.beRepaired(ct1.getEnergyPoints());
	ct1.printStatus();
	ct2.printStatus();

	std::cout << std::endl;

	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDamage());
	ct2.beRepaired(ct1.getEnergyPoints());
	ct1.printStatus();
	ct2.printStatus();

	std::cout << std::endl;

	return (0);
}

#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int	main(void) {

	ScavTrap	st1("AAA");
	ScavTrap	st2("BBB");
	ClapTrap	ct1("CCC");
	FragTrap	ft1("DDD");

	std::cout << std::endl << std::endl;

	st1.attack(st2.getName());
	st2.takeDamage(st1.getAttackDamage());
	std::cout << std::endl;

	ft1.attack(st1.getName());
	st1.takeDamage(ft1.getAttackDamage());
	std::cout << std::endl;

	st1.guardGate();
	st2.guardGate();
	std::cout << std::endl;

	ft1.highFivesGuys();
	std::cout << std::endl;

	st1.printStatus(ST);
	st2.printStatus(ST);
	ct1.printStatus(CT);
	ft1.printStatus(FT);

	std::cout << std::endl << std::endl;

	return (0);
}

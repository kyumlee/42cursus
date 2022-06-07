#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int	main(void) {

	ScavTrap	st1("AAA");
	ScavTrap	st2("BBB");
	ClapTrap	ct1("CCC");
	ClapTrap	ct2("DDD");
	ScavTrap	st3 = st2;

	std::cout << std::endl << std::endl;

	st1.attack(st2.getName());
	st2.takeDamage(st1.getAttackDamage());
	std::cout << std::endl;

	ct2.attack(st1.getName());
	st1.takeDamage(ct2.getAttackDamage());
	std::cout << std::endl;

	st1.guardGate();
	st2.guardGate();
	std::cout << std::endl;

	st1.printStatus(ST);
	st2.printStatus(ST);
	ct1.printStatus(CT);
	ct2.printStatus(CT);

	std::cout << std::endl << std::endl;

	return (0);
}

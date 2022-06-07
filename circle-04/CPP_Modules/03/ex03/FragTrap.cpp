#include "./FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	_name = DF;
	_hitPoints = F_HP;
	_energyPoints = F_EP;
	_attackDamage = F_AD;
	std::cout << FT << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hitPoints = F_HP;
	_energyPoints = F_EP;
	_attackDamage = F_AD;
	std::cout << FT << name << " Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft) {
	_name = ft.getName();
	_hitPoints = ft.getHitPoints();
	_energyPoints = ft.getEnergyPoints();
	_attackDamage = ft.getAttackDamage();
	std::cout << FT << _name << " Copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << FT;
	if (_name != DF)
		std::cout << _name << " ";
	std::cout << "Destructor called" << std::endl;
}

void		FragTrap::highFivesGuys(void) {
	std::cout << FT << "[" << std::setw(10) << "HIGHFIVE] ";
	std::cout << _name << ": HIGH FIVE GUYS!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ft) {
	if (this != &ft) {
		_name = ft.getName();
		_hitPoints = ft.getHitPoints();
		_energyPoints = ft.getEnergyPoints();
		_attackDamage = ft.getAttackDamage();
	}

	return (*this);
}

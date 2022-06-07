#include "./ClapTrap.hpp"
#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap() {
	_name = DF;
	_hitPoints = F_HP;
	_energyPoints = S_EP;
	_attackDamage = F_AD;
	std::cout << DT << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	_name = name;
	_hitPoints = F_HP;
	_energyPoints = S_EP;
	_attackDamage = F_AD;
	std::cout << DT << name << " Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) {
	_name = dt.getName();
	_hitPoints = dt.getHitPoints();
	_energyPoints = dt.getEnergyPoints();
	_attackDamage = dt.getAttackDamage();
	std::cout << DT << _name << " Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << DT;
	if (_name != DF)
		std::cout << _name << " ";
	std::cout << "Destructor called" << std::endl;
}

std::string	DiamondTrap::getName(void) const { return (_name); }

void		DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
};

void		DiamondTrap::whoAmI(void) {
	std::cout << DT << "[WHOMI] ";
	std::cout << "Name: " << _name << std::endl;
	std::cout << std::setw(13) << "";
	std::cout << "ClapTrap Name: " << _name << "_clap_name" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &dt) {
	if (this != &dt) {
		_name = dt.getName();
		_hitPoints = dt.getHitPoints();
		_energyPoints = dt.getEnergyPoints();
		_attackDamage = dt.getAttackDamage();
	}

	return (*this);
}

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	_name = DF;
	_hitPoints = S_HP;
	_energyPoints = S_EP;
	_attackDamage = S_AD;
	std::cout << ST << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name = name;
	_hitPoints = S_HP;
	_energyPoints = S_EP;
	_attackDamage = S_AD;
	std::cout << ST << name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &st) {
	_name = st.getName();
	_hitPoints = st.getHitPoints();
	_energyPoints = st.getEnergyPoints();
	_attackDamage = st.getAttackDamage();
	std::cout << ST << _name << " Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << ST;
	if (_name != DF)
		std::cout << _name << " ";
	std::cout << "Destructor called" << std::endl;
}

void		ScavTrap::attack(std::string const &target) {
	std::cout << ST << "[" << std::setw(10) << "ATTACK] ";
	std::cout << _name << AT << target;
	std::cout << " by " << _attackDamage << " points.";
	std::cout << std::endl;
}

void		ScavTrap::guardGate(void) {
	std::cout << ST << "[" << std::setw(10) << "GK-MODE] ";
	std::cout << _name << " has enterred a Gate keeper mode." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &st) {
	if (this != &st) {
		_name = st.getName();
		_hitPoints = st.getHitPoints();
		_energyPoints = st.getEnergyPoints();
		_attackDamage = st.getAttackDamage();
	}

	return (*this);
}

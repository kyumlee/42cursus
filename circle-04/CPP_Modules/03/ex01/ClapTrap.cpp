#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
	_name(DF), _hitPoints(HP), _energyPoints(EP), _attackDamage(AD) {
	std::cout << CT << "Default constructor called";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(std::string name) : 
	_name(name), _hitPoints(HP), _energyPoints(EP), _attackDamage(AD) {
	std::cout << CT << _name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ct) {
	_name = ct.getName();
	_hitPoints = ct.getHitPoints();
	_energyPoints = ct.getEnergyPoints();
	_attackDamage = ct.getAttackDamage();

	std::cout << CT << _name << " Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << CT;
	if (_name != DF)
		std::cout << _name << " ";
	std::cout << "Destructor called" << std::endl;
}

void		ClapTrap::attack(const std::string &target) {
	std::cout << CT << "[" << std::setw(10) << "ATTACK] ";
	std::cout << _name << AT << target;
	std::cout << " by " << _attackDamage << " points.";
	std::cout << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << std::endl;
		std::cout << CT << _name << " is already dead" << std::endl;
		return ;
	}

	_hitPoints -= amount;
	if (_hitPoints < 0) _hitPoints = 0;
	std::cout << CT << "[" << std::setw(10) << "DAMAGED] ";
	std::cout << _name << TD << amount << " points.";
	std::cout << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (!_hitPoints) return ;
	if (amount + _hitPoints > MAX_HP) {
		amount = 100 - _hitPoints;
		std::cout << CT << _name << "'s MAX HP is " << MAX_HP;
		std::cout << std::endl; 
	}
	_hitPoints += amount;
	std::cout << CT << "[" << std::setw(10) << "REPAIRED] ";
	std::cout << _name << RP << amount << " points.";
	std::cout << std::endl;
}

std::string	ClapTrap::getName(void) const { return (_name); }

int			ClapTrap::getHitPoints(void) const { return (_hitPoints); }

int			ClapTrap::getEnergyPoints(void) const { return (_energyPoints); }

int			ClapTrap::getAttackDamage(void) const { return (_attackDamage); }

void		ClapTrap::setName(std::string name) { _name = name; }

void		ClapTrap::setHitPoints(int hitPoints) { _hitPoints = hitPoints; }

void		ClapTrap::setEnergyPoints(int energyPoints) { _energyPoints = energyPoints; }

void		ClapTrap::setAttackDamage(int attackDamage) { _attackDamage = attackDamage; }

void		ClapTrap::printStatus(std::string trap) const {
	std::cout << std::endl;

	std::cout << trap << "[" << _name << "] STATUS" << std::endl;
	std::cout << "HP: " << _hitPoints << std::endl;
	std::cout << "EP: " << _energyPoints << std::endl;
	std::cout << "AD: " << _attackDamage << std::endl;

	if (_hitPoints <= 0)
		std::cout << trap << _name << " is dead" << std::endl;
	if (_hitPoints > MAX_HP)
		std::cout << trap << _name << "'s HP is full" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ct) {
	if (this != &ct) {
		_name = ct.getName();
		_hitPoints = ct.getHitPoints();
		_energyPoints = ct.getEnergyPoints();
		_attackDamage = ct.getAttackDamage();
	}

	return (*this);
}

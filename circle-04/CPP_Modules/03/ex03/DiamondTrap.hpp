#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

# define DT	"[DiamondTrap] "

class	DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &dt);
		virtual		~DiamondTrap(void);
		std::string	getName(void) const;
		void		whoAmI(void);
		void		attack(const std::string &target);
		DiamondTrap	&operator=(const DiamondTrap &dt);
};

#endif

#ifndef __SCAVTRAP_HPP__
# define __SCAVTRAP_HPP__

# include "./ClapTrap.hpp"

# define ST		"[ScavTrap] "
# define S_HP	100
# define S_EP	50
# define S_AD	20

class	ScavTrap : public virtual ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &st);
		virtual		 ~ScavTrap(void);
		void		attack(std::string const &target);
		void		guardGate(void);
		ScavTrap	&operator=(const ScavTrap &st);

};

#endif

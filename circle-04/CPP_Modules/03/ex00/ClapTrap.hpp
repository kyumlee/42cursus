#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>
# include <iomanip>

# define DF	"DEFAULT"
# define CT "[ClapTrap] "
# define AT " attacked "
# define TD " is damaged by "
# define RP " is repaired by "
# define MAX_HP 100
# define HP 10
# define EP 10
# define AD 0

class	ClapTrap {

	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ct);
		~ClapTrap(void);
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(std::string name);
		void		setHitPoints(int hitPoints);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);
		void		attack(std::string const &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		printStatus(void) const;
		ClapTrap	&operator=(const ClapTrap &ct);

};

#endif

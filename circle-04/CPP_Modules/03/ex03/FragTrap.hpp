#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "./ClapTrap.hpp"

# define FT		"[FragTrap] "
# define F_HP	100
# define F_EP	100
# define F_AD	30

class	FragTrap : public virtual ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& ft);
		virtual		~FragTrap(void);
		void		highFivesGuys(void);
		FragTrap	&operator=(const FragTrap &ft);
};

#endif

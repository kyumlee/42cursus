#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

# include <iostream>

class	Zombie {

private:
	std::string	_name;

public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void		setName(std::string name, int i);
	void		announce(void);

};
Zombie			*zombieHorde(int N, std::string name);

#endif

#include "./Zombie.hpp"

Zombie		*zombieHorde(int N, std::string name) {
	Zombie	*newZombieHorde;
	
	newZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		newZombieHorde[i].setName(name, i);
	return (newZombieHorde);
}

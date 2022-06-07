#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

int	main(void) {

	const Animal*		meta	= new Animal();
	const Animal*		j		= new Dog();
	const Animal*		i		= new Cat();
	const WrongAnimal*	w		= new WrongCat();

	std::cout << std::endl;
	std::cout << "Type of j : " << j->getType() << std::endl;
	std::cout << "Type of i : " << i->getType() << std::endl;
	std::cout << "Type of w : " << w->getType() << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	w->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete (w);
	delete (i);
	delete (j);
	delete (meta);

	return (0);
}

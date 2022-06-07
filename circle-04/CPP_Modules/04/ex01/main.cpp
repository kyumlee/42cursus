#include "./Animal.hpp"
#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"
#include "./Brain.hpp"
#include <ctime>
#include <iomanip>


std::string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) 
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

	return tmp_s;
}

void	print_ideas(Brain *br, int num, int len) {
	std::cout << "dog" << num << "'s brain: " << std::endl;
	for (int i = 0; i < len / 2; i++) {
		std::cout << "[" << i << "] " << br->getIdea(i) << "\t";
		std::cout << "[" << i + len / 2 << "] " << br->getIdea(i + len / 2) << std::endl;
	}
	std::cout << std::endl;
}

void	deep_copy_test(void) {
	Dog	dog1;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		dog1.getBrain()->setIdea(i, gen_random(5));
	print_ideas(dog1.getBrain(), 1, 100);

	Dog	dog2 = dog1;
	std::cout << std::endl;
	dog2.getBrain()->setIdea(99, "NEW!!");
	print_ideas(dog2.getBrain(), 2, 100);

	std::cout << "dog1's 99th idea: " << dog1.getBrain()->getIdea(99) << std::endl;
	std::cout << "dog2's 99th idea: " << dog2.getBrain()->getIdea(99) << std::endl;
	std::cout << std::endl;	
}

int	main(void) {
	Animal	*animal[10];
	size_t	i = 0;

	// half Dog
	for (; i < 5; i++)
		animal[i] = new Dog();
	std::cout << std::endl;

	// half Cat
	for (; i < 10; i++)
		animal[i] = new Cat();
	std::cout << std::endl;

	for (i = 0; i < 10; i++) {
		std::cout << "Type of [" << i << "]th animal: ";
		std::cout << animal[i]->getType() << std::endl;
	}
	std::cout << std::endl;

	// delete every Animal
	for (i = 0; i < 10; i++)
		delete animal[i];


	std::cout << std::endl << std::endl;


	srand((unsigned)time(NULL));
	deep_copy_test();
}

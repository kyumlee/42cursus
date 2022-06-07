#include "./Karen.hpp"

void	Karen::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I just love it!" << std::endl << std::endl;
}

void	Karen::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough!" << std::endl;
	std::cout << "If you did I would not have to ask for it!" << std::endl << std::endl;
}

void	Karen::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void	Karen::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

Karen::Karen(void) {}

Karen::~Karen(void) {}

void	Karen::complain(std::string level) {
	int			i;
	void		(Karen::*fptr[4])(void) = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error	};
	std::string	lvls[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int j = 0; j < 4; j++) {
		if (lvls[j] == level) {
			i = j;
			break ;
		}
		i = 4;
	}

	switch (i) {
		case 0: (this->*fptr[0])();
		case 1: (this->*fptr[1])();
		case 2: (this->*fptr[2])();
		case 3: (this->*fptr[3])(); 
				std::cout << std::endl;
				break ;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	};
}

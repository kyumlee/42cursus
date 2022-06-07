#include "./Phonebook.hpp"

int	main(void) {
	Phonebook	phonebook;
	std::string	input;

	std::cout << "=========THIS IS A SIMPLE PHONEBOOK==========" << std::endl;
	std::cout << std::endl;
	while (1) {
		std::cout << "ENTER AN INPUT [ADD / SEARCH / EXIT] : ";
		getline(std::cin, input);
		if (std::cin.eof()) break ;

		if (!input.compare("ADD")) {
			if (!phonebook.addContact()) break ;
		}
		else if (!input.compare("SEARCH")) {
			if (!phonebook.searchContact()) break ;
		}
		else if (!input.compare("EXIT")) break ;
		else if (input == "") continue ;
		else
			std::cout << "NOT A VALID INPUT!! TRY AGAIN..." << std::endl;
	}
	std::cout << std::endl << "EXITING PHONEBOOK..." << std::endl;
	return (0);
}

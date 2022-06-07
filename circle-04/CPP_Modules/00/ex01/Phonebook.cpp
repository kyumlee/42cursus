#include "./Phonebook.hpp"

Phonebook::Phonebook(void) {
	index = 0;
}

Phonebook::~Phonebook(void) {}

int	tryAgainMsg(std::string msg) {
	std::cout << msg << std::endl;
	return (0);
}

int	Phonebook::isValidName(std::string firstName, std::string lastName) const {
	char	c;

	for (int i = 0; i < index; i++) {
		if (firstName == contacts[i].getFirstName()
			&& lastName == contacts[i].getLastName()) {
			std::cout << "NAME ALREADY EXISTS!! (INDEX: " << i + 1 << ")"
				<< std::endl;
			do {
				std::cout << "ADD ANYWAYS? (y / n) ";
				std::cin >> c;
				std::cin.ignore(2, '\n');
				if (std::cin.eof()) return (2);
				if (c == 'y') return (1);
				else if (c == 'n') return (tryAgainMsg("TRY ANOTHER NAME"));
			} while (c != 'y' && c != 'n');
		}
	}
	return (1);
}

int	Phonebook::isValidNumber(std::string number, int isInput) const {
	char	c;

	for (int i = 0; i <= (int)number.length(); i++) {
		if (!isdigit(number[i]) && number[i])
			return (tryAgainMsg("INPUT HAS TO BE A NUMBER!! TRY AGAIN..."));
	}
	if (isInput) return (1);
	for (int i = 0; i < index; i++) {
		if (number == contacts[i].getNumber()) {
			std::cout << "NUMBER ALREADY EXISTS!! (INDEX: " << i + 1 << ")"
				<< std::endl;
			do {
				std::cout << "ADD ANYWAYS? (y / n) ";
				std::cin >> c;
				std::cin.ignore(2, '\n');
				if (std::cin.eof()) return (2);
				if (c == 'y') return (1);
				else if (c == 'n') return (tryAgainMsg("TRY ANOTHER NUMBER..."));
			} while (c != 'y' && c != 'n');
		}
	}
	return (1);
}

int	Phonebook::checkDuplicate(std::string firstName, std::string lastName,
		std::string number) {
	for (int i = 0; i < index; i++) {
		if (firstName == contacts[i].getFirstName()
			&& lastName == contacts[i].getLastName()
			&& number == contacts[i].getNumber()) {
			std::cout << "CONTACT ALREADY EXISTS!! TRY AGAIN..." << std::endl;
			std::cout << std::endl;
			return (1);
		}
	}
	return (0);
}

int	Phonebook::addContact(void) {
	int			exit = 0;
	std::string firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	std::cout << std::endl << "ADDING A CONTACT..." << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	do {
		do {
			std::cout << std::setw(22) << std::left << "ENTER FIRST NAME: ";
			getline(std::cin, firstName);
			if (std::cin.eof()) return (0);
		} while (firstName == "");
		do {
			std::cout << std::setw(22) << std::left << "ENTER LAST NAME: ";
			getline(std::cin, lastName);
			if (std::cin.eof()) return (0);
		} while (lastName == "");
	} while (!(exit = isValidName(firstName, lastName)));
	if (exit == 2) return (0);
	do {
		std::cout << std::setw(22) << std::left << "ENTER NICKNAME: ";
		getline(std::cin, nickname);
		if (std::cin.eof()) return (0);
	} while (nickname == "");
	do {
		std::cout << std::setw(22) << std::left << "ENTER PHONE NUMBER: ";
		getline(std::cin, number);
		if (std::cin.eof()) return (0);
	} while (!(exit = isValidNumber(number, 0)) || number == "");
	if (checkDuplicate(firstName, lastName, number)) return (1);
	do {
		std::cout << "ENTER DARKEST SECRET: ";
		getline(std::cin, secret);
		if (std::cin.eof()) return (0);
	} while (secret == "");
	contacts[index % 8] = Contact(firstName, lastName, nickname, number, secret);
	index++;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	return (1);
}

int	Phonebook::displayContacts(void) const {
	int	end;

	if (!index) {
		std::cout << std::endl;
		std::cout << "PHONEBOOK IS EMPTY!! ADD A CONTACT FIRST..." << std::endl;
		std::cout << std::endl;
		return (0);
	}
	if (index < 8) end = index;
	else end = 8;
	std::cout << std::endl;
	std::cout << "==============LIST OF CONTACTS===============" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "INDEX" << "|";
	std::cout << std::setw(10) << std::right << "FIRST NAME" << "|";
	std::cout << std::setw(10) << std::right << "LAST NAME" << "|";
	std::cout << std::setw(10) << std::right << "NICKNAME" << "|";
	std::cout << std::endl;
	for (int i = 0; i < end; i++) {
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		if (contacts[i].getFirstName().length() > 10)
			std::cout << std::setw(9) << contacts[i].getFirstName().substr(0, 9)
				<< ".|";
		else
			std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		if (contacts[i].getLastName().length() > 10)
			std::cout << std::setw(9) << contacts[i].getLastName().substr(0, 9)
				<< ".|";
		else
			std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		if (contacts[i].getNickname().length() > 10)
			std::cout << std::setw(9) << contacts[i].getNickname().substr(0, 9)
				<< ".|" << std::endl;
		else
			std::cout << std::setw(10) << contacts[i].getNickname()
				<< "|" << std::endl;
	}
	std::cout << "=============================================" << std::endl;
	return (1);
}

int	Phonebook::searchContact(void) const {
	int			i;
	std::string	s_i;

	if (!displayContacts()) return (1);
	std::cout << std::endl << "SEARCHING FOR A CONTACT INFO..." << std::endl;
	while (1) {
		std::cout << "ENTER AN INDEX: ";
		getline(std::cin, s_i);
		if (std::cin.eof()) return (0);
		else if (!isValidNumber(s_i, 1)) continue ;
		else if (s_i == "") continue ;
		else {
			i = stoi(s_i);
			if (i > index || i <= 0)
				std::cout << "NOT A VALID INDEX!! TRY AGAIN..." << std::endl;
			else break ;
		}
	}
	std::cout << std::endl;
	std::cout << "----------------CONTACT INFO-----------------" << std::endl;
	std::cout << std::setw(17) << "FIRST NAME: "
		<< contacts[i - 1].getFirstName() << std::endl;
	std::cout << std::setw(17) << "LAST NAME: "
		<< contacts[i - 1].getLastName() << std::endl;
	std::cout << std::setw(17) << "NICKNAME: "
		<< contacts[i - 1].getNickname() << std::endl;
	std::cout << std::setw(17) << "PHONE NUMBER: "
		<< contacts[i - 1].getNumber() << std::endl;
	std::cout << std::setw(17) << "DARKEST SECRET: "
		<< contacts[i - 1].getSecret() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
	return (1);
}

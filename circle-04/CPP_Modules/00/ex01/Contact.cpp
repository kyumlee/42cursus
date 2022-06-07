#include "./Contact.hpp"

Contact::Contact(void) {
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_number = "";
	_secret = "";
}

Contact::Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string number, std::string secret) {
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_number = number;
	_secret = secret;
}

Contact::~Contact() {}

std::string	Contact::getFirstName(void) const { return (_firstName); }
std::string	Contact::getLastName(void) const { return (_lastName); }
std::string	Contact::getNickname(void) const { return (_nickname); }
std::string Contact::getNumber(void) const { return (_number); }
std::string	Contact::getSecret(void) const { return (_secret); }

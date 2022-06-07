#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <iostream>
# include <string>
# include <iomanip>

class	Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;

public:
	Contact(void);
	Contact(std::string firstName, std::string lastName,
		std::string nickname, std::string number, std::string secret);
	~Contact(void);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getNumber(void) const;
	std::string	getSecret(void) const;

};

#endif

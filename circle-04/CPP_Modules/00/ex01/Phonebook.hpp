#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "./Contact.hpp"

class	Phonebook {

	private:
		int		index;
		Contact contacts[8];

	public:
		Phonebook(void);
		~Phonebook(void);
		int		isValidName(std::string firstName, std::string lastName) const;
		int		isValidNumber(std::string number, int isInput) const;
		int		checkDuplicate(std::string firstName, std::string lastName,
				std::string number);
		int		addContact(void);
		int		displayContacts(void) const;
		int		searchContact(void) const;

};

#endif

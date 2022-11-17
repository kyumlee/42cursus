#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

# include <iostream>

class	Warlock {
	private:
		std::string	_name;
		std::string	_title;

	public:
		const std::string&	getName() const;
		const std::string&	getTitle() const;
		void				setTitle(const std::string& title);
		Warlock(std::string name, std::string title);
		void				introduce() const;
		~Warlock();
};

#endif

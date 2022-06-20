#ifndef __LOCATION_HPP__
# define __LOCATION_HPP__

# include <iostream>
# include <vector>
# include <map>

/*
 * location optional_modifier location_match {
 * ...
 * }
 *
 * optional_modifier: (none), =, ~, ~*, ^~.
 * location_match: what Nginx should check the request URI against.
 */

class	Location {

	private:
		std::string	_mod;	// optional modifier
		std::string	_match;	// location match

	public:
		// constructor, destructor, assignment operator overload
		Location ();
		Location (std::string mod, std::string match);
		Location (const Location &lb);
		~Location ();
		Location	&operator= (const Location &lb);

		// getter
		std::string	getMod ();
		std::string	getMatch ();

		// setter
		void		setMod (std::string str);
		void		setMatch (std::string str);
};

#endif

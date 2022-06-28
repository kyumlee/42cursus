#ifndef __LOCATION_HPP__
# define __LOCATION_HPP__

# include "./Utils.hpp"

/*
 * location optional_modifier location_route {
 * ...
 * }
 *
 * optional_modifier: (none), =, ~, ~*, ^~.
 * location_route: what Nginx should check the request URI against.
 */

class	Location {

	private:
		std::string					_block;
		std::string					_mod;		// optional modifier
		std::string					_route;		// location match
		std::vector<std::string>	_methods;	// GET, POST, DELETE
		int							_redirect;	// if a response code is 302, inform to re-request to another [Location]
		bool						_dListing;	// autoindex on/off
		std::string					_default;	// if a request is a directory, return this file

	public:
		// constructor, destructor, assignment operator overload
		Location ();
		Location (const Location &lb);
		~Location ();
		Location	&operator= (const Location &lb);

		// getter
		std::string					getBlock ();
		std::string					getMod ();
		std::string					getRoute ();
		std::vector<std::string>	getMethods ();
		int							getRedirect ();
		bool						getDListing ();
		std::string					getDefault ();

		// setter
		void						setBlock (std::string block);
		void						setMod (std::string mod);
		void						setRoute (std::string route);
		void						setMethods (std::vector<std::string> methods);
		void						setRedirect (int redirection);
		void						setDListing (bool dListing);
		void						setDefault (std::string file);

		int							parseMethods ();
		int							parseDListing ();
		int							parseDefault ();
		void						parse ();
};

#endif

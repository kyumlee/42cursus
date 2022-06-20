#ifndef __SERVER_HPP__
# define __SERVER_HPP__

# include "./Location.hpp"

# define GET	0
# define POST	1
# define DELETE	2

class	Server {

	private:
		std::string					_address;	// address to listen to
		std::string					_servName;	// name of server
		std::map<int, std::string>	_errPages;	// there can be multiple error pages
		int							_clntSize;	// maximum size of client's body size
		std::string					_root;		// root directory of a server
		std::vector<Location>		_locations;	// location block to be used
		std::vector<std::string>	_methods;	// GET, POST, DELETE
		int							_redirect;	// if a response code is 302, inform to re-request to another [Location]
		bool						_dListing;	// autoindex on / off
		std::string					_default;	// if a request is a directory, return this file

	public:
		// constructor, destructor, assignment operator overload
		Server ();
		Server (const Server &srv);
		~Server ();
		Server						&operator= (const Server &srv);

		// getters
		std::string					getAddress ();
		std::string					getServName ();
		std::map<int, std::string>	getErrPages ();
		int							getClntSize ();
		std::string					getRoot ();
		std::vector<Location>		getLocations ();
		std::vector<std::string>	getMethods ();
		int							getRedirect ();
		bool						getDListing ();
		std::string					getDefault ();
		
		// setters
		void						setAddress (std::string address);
		void						setServName (std::string name);
		void						addErrPage (int errNo, std::string page);
		void						setClntSize (int size);
		void						setRoot (std::string root);
		void						addLocation (Location lc);
		void						addMethod (std::string method);
		void						setRedirect (int redirection);
		void						setDListing (bool dirListing);
		void						setDefault (std::string file);

};

# endif

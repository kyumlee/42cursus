#ifndef __SERVER_HPP__
# define __SERVER_HPP__

# include "./Location.hpp"

# define GET	0
# define POST	1
# define DELETE	2

class	Server {

	private:
		std::string					_block;
		std::string					_host;		// host to listen to
		std::string					_port;		// port to open
		std::string					_name;		// name of server
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
		Server (std::string block);
		Server (const Server &srv);
		~Server ();
		Server						&operator= (const Server &srv);

		// getters
		std::string					getBlock ();
		std::string					getHost ();
		std::string					getPort ();
		std::string					getName ();
		std::map<int, std::string>	getErrPages ();
		int							getClntSize ();
		std::string					getRoot ();
		std::vector<Location>		getLocations ();
		std::vector<std::string>	getMethods ();
		int							getRedirect ();
		bool						getDListing ();
		std::string					getDefault ();
		
		// setters
		void						setBlock (std::string block);
		void						setHost (std::string host);
		void						setPort (std::string port);
		void						setName (std::string name);
		void						addErrPage (int errNo, std::string page);
		void						setClntSize (int size);
		void						setRoot (std::string root);
		void						addLocation (Location lc);
		void						addMethod (std::string method);
		void						setRedirect (int redirection);
		void						setDListing (bool dirListing);
		void						setDefault (std::string file);

		Location					selectLocation ();

};

# endif

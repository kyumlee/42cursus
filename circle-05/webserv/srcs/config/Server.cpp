#include "./../../includes/Server.hpp"

// constructor, destructor, assignment operator overload
Server::Server ()
	: _address("0.0.0.0:80"),
	_servName("default_server"),
	_clntSize(1024),
	_root("./../../tmp/www"),
	_locations(),
	_methods(),
	_redirect(1),
	_dListing(true),
	_default("./../../tmp/www/default")
{}

Server::Server (const Server &srv)
	: _address(srv._address),
	_servName(srv._servName),
	_errPages(srv._errPages),
	_clntSize(srv._clntSize),
	_root(srv._root),
	_locations(srv._locations),
	_methods(srv._methods),
	_redirect(srv._redirect),
	_dListing(srv._dListing),
	_default(srv._default)
{}

Server::~Server () {}

Server				&Server::operator= (const Server &srv) {
	_address = srv._address;
	_servName = srv._servName;
	_errPages = srv._errPages;
	_clntSize = srv._clntSize;
	_root = srv._root;
	_locations = srv._locations;
	_methods = srv._methods;
	_redirect = srv._redirect;
	_dListing = srv._dListing;
	_default = srv._default;

	return (*this);
}

// Server::getters
std::string					Server::getAddress () { return (_address); }

std::string					Server::getServName () { return (_servName); }

std::map<int, std::string>	Server::getErrPages () { return (_errPages); }

int							Server::getClntSize () { return (_clntSize); }

std::string					Server::getRoot () { return (_root); }

std::vector<Location>		Server::getLocations () { return (_locations); }

std::vector<std::string>	Server::getMethods () { return (_methods); }

int							Server::getRedirect () { return (_redirect); }

bool						Server::getDListing () { return (_dListing); }

std::string					Server::getDefault () { return (_default); }

// Server::setters
void						Server::setAddress (std::string address) { _address = address; }

void						Server::setServName (std::string name) { _servName = name; }

void						Server::addErrPage (int errNo, std::string page) { _errPages[errNo] = page; }

void						Server::setClntSize (int size) { _clntSize = size; }

void						Server::setRoot (std::string root) { _root = root; }

void						Server::addLocation (Location lc) { _locations.push_back(lc); }

// TODO: if [method] is not GET, POST, nor DELETE, to something else
void						Server::addMethod (std::string method) { _methods.push_back(method); }

void						Server::setRedirect (int redirect) { _redirect = redirect; }

void						Server::setDListing (bool dListing) { _dListing = dListing; }

void						Server::setDefault (std::string file) { _default = file; }

#include "./../../includes/Server.hpp"

// constructor, destructor, assignment operator overload
Server::Server ()
	: _block(),
	_host("0.0.0.0"),
	_port("80"),
	_name("default_server"),
	_clntSize(1024),
	_root("./../../tmp/www"),
	_locations(),
	_methods(),
	_redirect(1),
	_dListing(true),
	_default("./../../tmp/www/default")
{}

Server::Server (std::string block)
	: _block(block),
	_host("0.0.0.0"),
	_port("80"),
	_name("default_server"),
	_clntSize(1024),
	_root("./../../tmp/www"),
	_locations(),
	_methods(),
	_redirect(1),
	_dListing(true),
	_default("./../../tmp/www/default")
{}

Server::Server (const Server &srv)
	: _block(srv._block),
	_host(srv._host),
	_port(srv._port),
	_name(srv._name),
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
	_block = srv._block;
	_host = srv._host;
	_port = srv._port;
	_name = srv._name;
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
std::string					Server::getBlock() { return (_block); }
std::string					Server::getHost () { return (_host); }
std::string					Server::getPort () { return (_port); }
std::string					Server::getName () { return (_name); }
std::map<int, std::string>	Server::getErrPages () { return (_errPages); }
int							Server::getClntSize () { return (_clntSize); }
std::string					Server::getRoot () { return (_root); }
std::vector<Location>		Server::getLocations () { return (_locations); }
std::vector<std::string>	Server::getMethods () { return (_methods); }
int							Server::getRedirect () { return (_redirect); }
bool						Server::getDListing () { return (_dListing); }
std::string					Server::getDefault () { return (_default); }

// Server::setters
void						Server::setBlock(std::string block) { _block = block; }
void						Server::setHost (std::string host) { _host = host; }
void						Server::setPort (std::string port) { _port = port; }
void						Server::setName (std::string name) { _name = name; }
void						Server::addErrPage (int errNo, std::string page) { _errPages[errNo] = page; }
void						Server::setClntSize (int size) { _clntSize = size; }
void						Server::setRoot (std::string root) { _root = root; }
void						Server::addLocation (Location lc) { _locations.push_back(lc); }
// TODO: if [method] is not GET, POST, nor DELETE, to something else
void						Server::addMethod (std::string method) { _methods.push_back(method); }
void						Server::setRedirect (int redirect) { _redirect = redirect; }
void						Server::setDListing (bool dListing) { _dListing = dListing; }
void						Server::setDefault (std::string file) { _default = file; }

size_t						searchAndSkipWord (std::string line, std::string str) {
	size_t	pos = line.find(str, 0);
	size_t	scPos = line.find(";", pos);
	size_t	nlPos = line.find("\n", pos);

	if (pos == std::string::npos)
		return (1);
	if (scPos == std::string::npos || nlPos == std::string::npos || scPos > nlPos) {
		printErr("invalid server block");
		return (0);
	}

	pos += str.length();
	while (std::isspace(line[pos]))
		pos++;
	return (pos);
}

int							Server::setAddress () {
	size_t		pos = 0, scPos = 0;
	std::string	address;

	pos = searchAndSkipWord(_block, "listen");
	if (pos == 0 || pos == 1)
		return (1);
	scPos = _block.find(";", pos);
	address = _block.substr(pos, scPos - pos);

	std::vector<std::string>	addr = split(address, ':');

	if (addr.size() == 1) {
		if (address.find(".", 0) == std::string::npos) {
			setHost("0.0.0.0");
			setPort(address);
		}
		else {
			setHost(address);
			setPort("80");
		}
	}
	else {
		setHost(addr[0]);
		setPort(addr[1]);
	}

	return (0);
}

bool						isNumber (std::string str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

int							Server::setErrorPages () {
	size_t		pos = 0, scPos = 0;
	std::string	errPages;

	pos = searchAndSkipWord(_block, "error_page");
	if (pos == 0 || pos == 1)
		return (1);
	scPos = _block.find(";", pos);
	errPages = _block.substr(pos, scPos - pos);

	std::vector<std::string>	errPagesVec = split(errPages, ' ');
	for (size_t i = 0; i < errPagesVec.size(); i += 2) {
		if (!isNumber(errPagesVec[i])) {
			printErr("error code must be a number");
			return (0);
		}
		std::stringstream	ssInt(errPagesVec[i]);
		int	errNo;
		ssInt >> errNo;
		_errPages.insert(std::make_pair(errNo, errPagesVec[i + 1]));
	}
	return (0);
}

int							Server::setClntSize () {
	return (1);
}

int							Server::setMethods () {
	return (1);
}

int							Server::setDListing () {
	return (1);
}

int							Server::setDefault () {
	return (1);
}

int							Server::parse () {
	if (setAddress())
		return (1);
	if (setErrorPages())
		return (1);

	return (0);
}

// TODO
Location					Server::selectLocation () { return (_locations[0]); }

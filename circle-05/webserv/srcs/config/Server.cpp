#include "./../../includes/Server.hpp"

// constructor, destructor, assignment operator overload
Server::Server ()
	: _block(),
	_host("0.0.0.0"),
	_port("80"),
	_name(""),
	_clntSize(1024),
	_root("./../../tmp/www"),
	_locations(),
	_methods(),
	_redirect(1),
	_dListing(true),
	_default("./../../tmp/www/default")
{
	_errPages.insert(std::make_pair(404, "./tmp/www/error.html"));
}

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
{
	_errPages.insert(std::make_pair(404, "./tmp/www/error.html"));
}

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
int							Server::setErrPages (std::vector<std::string> pages) {
	if (pages.size() % 2) {
		printErr("error must be a pair of err_code and err_page");
		return (1);
	}

	for (size_t i = 0; i < pages.size(); i += 2) {
		if (!isNumber(pages[i])) {
			printErr("error code must be a number");
			return (1);
		}
		std::stringstream	ssInt(pages[i]);
		int	errNo;
		ssInt >> errNo;
		_errPages.insert(std::make_pair(errNo, pages[i + 1]));
	}

	return (0);
}
int							Server::setClntSize (int size) {
	if (size < 1) {
		printErr("size should be greater than 0");
		return (1);
	}

	_clntSize = size;
	return (0);
}
void						Server::setRoot (std::string root) { _root = root; }
void						Server::addLocation (Location lc) { _locations.push_back(lc); }
int							Server::setMethods (std::vector<std::string> methods) {
	if (methods.empty()) {
		printErr("there are no methods");
		return (1);
	}

	for (size_t i = 0; i < methods.size(); i++) {
		if (methods[i] != "GET" && methods[i] != "POST" && methods[i] != "DELETE")
			return (1);
		_methods.push_back(methods[i]);
	}
	return (0);
}
void						Server::setRedirect (int redirect) { _redirect = redirect; }
int							Server::setDListing (bool dListing) {
	_dListing = dListing;
	return (0);
}
void						Server::setDefault (std::string file) { _default = file; }

int							Server::parseAddress () {
	std::string					address;
	std::vector<std::string>	addressVec;
	std::pair<bool, size_t>		res = skipKey(_block, "listen");

	if (res.first == false)
		return (1);

	address = parseValue(_block, res.second);
	addressVec = split(address, ':');

	if (addressVec.size() == 1) {
		if (address.find(".", 0) == std::string::npos) {
			setHost("0.0.0.0");
			setPort(address);
		}
		else {
			setHost(address);
			setPort("80");
		}
	}
	else if (addressVec.size() == 2) {
		setHost(addressVec[0]);
		setPort(addressVec[1]);
	}
	else
		return (1);

	return (0);
}

int							Server::parseName () {
	std::string				name;
	std::pair<bool, size_t>	res = skipKey(_block, "server_name");

	if (res.first == false)
		return (1);

	name = parseValue(_block, res.second);
	setName(name);

	return (0);
}

int							Server::parseRoot () {
	std::string				root;
	std::pair<bool, size_t>	res = skipKey(_block, "root");

	if (res.first == false)
		return (1);
	root = parseValue(_block, res.second);
	setRoot(root);

	return (0);
}

int							Server::parseErrPages () {
	std::string					errPages;
	std::vector<std::string>	errPagesVec;
	std::pair<bool, size_t>		res = skipKey(_block, "error_page");

	if (res.first == false)
		return (1);

	errPages = parseValue(_block, res.second);
	errPagesVec = split(errPages, ' ');

	return (setErrPages(errPagesVec));
}

int							Server::parseClntSize () {
	int						clntBodySize;
	std::pair<bool, size_t>	res = skipKey(_block, "client_body_size");

	if (res.first == false)
		return (1);

	std::stringstream		ssClntBodySize(parseValue(_block, res.second));
	ssClntBodySize >> clntBodySize;

	return (setClntSize(clntBodySize));
}

int							Server::parseMethods () {
	std::string					methods;
	std::vector<std::string>	methodsVec;
	std::pair<bool, size_t>		res = skipKey(_block, "accepted_methods");

	if (res.first == false)
		return (1);

	methods = parseValue(_block, res.second);
	methodsVec = split(methods, ' ');

	return (setMethods(methodsVec));
}

int							Server::parseDListing () {
	std::string				is;
	std::pair<bool, size_t>	res = skipKey(_block, "directory_listing");

	if (res.first == false)
		return (1);

	is = parseValue(_block, res.second);
	if (is == "on")
		return (setDListing(true));
	else if (is == "off")
		return (setDListing(false));

	return (1);
}

int							Server::parseDefault () {
	std::string				file;
	std::pair<bool, size_t>	res = skipKey(_block, "default_file");

	if (res.first == false)
		return (1);

	file = parseValue(_block, res.second);
	setDefault(file);

	return (0);
}

void						Server::parse () {
	if (parseAddress() || parseName() || parseErrPages() || parseRoot()
		|| parseClntSize() || parseMethods() || parseDListing() || parseDefault())
		return ;
}

// TODO
Location					Server::selectLocation () { return (_locations[0]); }

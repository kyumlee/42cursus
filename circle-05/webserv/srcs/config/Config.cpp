#include "./../../includes/Config.hpp"

Config::Config () {}

Config::Config (Config &conf) { _server = conf._server; }

Config::~Config () {}

Config						&Config::operator= (Config &conf) { _server = conf._server; return (*this); }

void						Config::addServer (Server serv) { _server.push_back(serv); }

void						Config::parse (std::string file) {
	std::string	buf;
	std::cout << "configuration file: " << file << std::endl;

	std::ifstream	f(file);
	if (!f) {
		printErr("wrong configuration file");
		return ;
	}
	std::ostringstream	ss;
	ss << f.rdbuf();
	buf = ss.str();

	std::vector<std::string>	blocks = splitBlocks(buf);

	for (size_t i = 0; i < blocks.size(); i++) {
		addServer(Server(blocks[i]));
		_server[i].parse();

/*		std::cout << "address: " << _server[i].getHost() << ":" << _server[i].getPort() << std::endl;
		std::cout << "server name: " << _server[i].getName() << std::endl;
		std::cout << "error pages: " << std::endl;
		std::map<int,std::string>	map = _server[i].getErrPages();
		for (std::map<int,std::string>::iterator it = map.begin(); it != map.end(); it++)
			std::cout << " code: " << it->first << ", page: " << it->second << std::endl;
		std::cout << "client's body size: " << _server[i].getClntSize() << std::endl;
		std::cout << "root: " << _server[i].getRoot() << std::endl;
		std::cout << "accepted methods: ";
		for (size_t i = 0; i < _server[i].getMethods().size(); i++)
			std::cout << "[" << _server[i].getMethods()[i] << "] ";
		std::cout << std::endl;
		std::cout << "directory listing: " << _server[i].getDListing() << std::endl;
		std::cout << "default file: " << _server[i].getDefault() << std::endl;
		std::cout << std::endl;*/

	}
}

std::vector<Server>			Config::findMatchingServers (std::string request, std::string *host, std::string *port) {
	std::vector<Server>			ret;
	std::vector<std::string>	addr = split(request, ':');

	*host = addr[0];
	*port = "80";
	if (addr.size() == 2)
		*port = addr[1];

	for (size_t i = 0; i < _server.size(); i++) {
		if (_server[i].getPort() == *port)
			ret.push_back(_server[i]);
	}

	return (ret);
}

Server						Config::selectServer (std::string request) {
	std::string					host, port;
	std::vector<Server>			ret = findMatchingServers(request, &host, &port);

	if (ret.size() == 1)
		return (ret[0]);

	for (size_t i = 0; i < ret.size(); i++) {
		if (ret[i].getName() == host)
			return (ret[i]);
	}

	for (size_t i = 0; i < ret.size(); i++) {
		if (ret[i].getName() == "default_server")
			return (ret[i]);
	}
	return (Server());
}

#include "./../../includes/Config.hpp"

Config::Config () {}

Config::Config (Config &conf) { _server = conf._server; }

Config::~Config () {}

Config	&Config::operator= (Config &conf) { _server = conf._server; return (*this); }

Server	Config::getServerByAddr (std::string address) {
	for (std::vector<Server>::iterator it = _server.begin(); it != _server.end(); it++) {
		if (it->getAddress() == address)
			return (*it);
	}
	return (*_server.end()--);
}

Server	Config::getServerByName (std::string name) {
	for (std::vector<Server>::iterator it = _server.begin(); it != _server.end(); it++) {
		if (it->getServName() == name)
			return (*it);
	}
	return (*_server.end()--);
}

void	Config::addServer (Server serv) { _server.push_back(serv); }

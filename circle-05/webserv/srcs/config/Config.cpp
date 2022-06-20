#include "./../../includes/Config.hpp"

Config::Config () {}

Config::Config (Config &conf) { _server = conf._server; }

Config::~Config () {}

Config	&Config::operator= (Config &conf) { _server = conf._server; return (*this); }

void	Config::addServer (Server serv) { _server.push_back(serv); }

Server	Config::selectServer () { return (_server[0]); }

void	Config::parse (std::string file) {
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

	// TODO: count how many server blocks there are.
	// while loop, pass the server block (content inside the brackets) to Server::parseServer() function. Do the parsing there.
	
	// TODO: parse

	// TODO: select an appropriate server

}

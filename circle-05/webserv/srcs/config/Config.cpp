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
	}

	// TODO: parse

	// TODO: select an appropriate server

}

Server						Config::selectServer () { return (_server[0]); }

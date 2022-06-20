#include "./../../includes/Config.hpp"

Config::Config () {}

Config::Config (Config &conf) { _server = conf._server; }

Config::~Config () {}

Config	&Config::operator= (Config &conf) { _server = conf._server; return (*this); }

void	Config::addServer (Server serv) { _server.push_back(serv); }

// TODO
Server	Config::selectServer () { return (_server[0]); }

void	Config::parseServerBlock (std::string buf) {
	std::vector<std::string>	lines = split(buf);

	for (size_t i = 0; i < lines.size(); i++) {
		size_t	pos = lines[i].find("server", 0, 6);
		if (pos != std::string::npos && lines[i][pos + 6] == '{') {
			Server	serv;
		}
	}
}

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
	
	std::cout << buf << std::endl << std::endl;

	parseServerBlock (buf);

	// TODO: parse

	// TODO: select an appropriate server

}

#include "./includes/webserv.hpp"

int	main(int argc, char **argv) {
	if (argc > 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	Config	conf;
	std::string	confFile = (argc == 1) ? "./conf/default.conf" : argv[1];

	std::cout << "configuration file: " << confFile << std::endl;
}

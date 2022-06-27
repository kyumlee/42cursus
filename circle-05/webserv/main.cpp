#include "./includes/Config.hpp"

int	main(int argc, char **argv) {
	if (argc > 2) {
		printErr("Wrong number of arguments");
		return (1);
	}

	std::string	confFile = (argc == 1) ? DEFAULT_CONF : argv[1];

	Config	conf;

	conf.parse(confFile);

	Server srv = conf.selectServer("test.com");

	std::cout << "server name: " << srv.getName() << std::endl;
}

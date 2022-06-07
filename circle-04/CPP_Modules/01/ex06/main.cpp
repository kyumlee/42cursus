#include "./Karen.hpp"

int	printUsage(void) {
	std::cerr << "USAGE: ./karenFilter [LEVEL]" << std::endl;
	return (1);
}

int	main(int argc, char **argv) {
	Karen	karen;

	if (argc != 2) return (printUsage());

	karen.complain(argv[1]);

	return (0);
}

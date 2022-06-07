#include "./Karen.hpp"

void	printUsage(void) {
	std::cerr << "USAGE: ./karen [LEVEL]" << std::endl;
   	std::cerr << " -> LEVEL: DEBUG / INFO / WARNING / ERROR" << std::endl;
}

int	main(int argc, char **argv) {
	Karen	karen;

	if (argc != 2) {
		printUsage();
		return (1);
	}

	karen.complain(argv[1]);

	return (0);
}

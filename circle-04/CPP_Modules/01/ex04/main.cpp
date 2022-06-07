#include "./Replace.hpp"

int	printUsage() {
	std::cerr << "Usage: ./replace [FILENAME] [STRING_TO_BE_REPLACED] [STRING_TO_REPLACE]";
	std::cerr << std::endl;
	return (1);
}

int	main(int argc, char **argv) {
	if (argc != 4) return (printUsage());

	if (!replace(argv[1], argv[2], argv[3])) return (1);

	std::cout << std::endl;

	return (0);
}


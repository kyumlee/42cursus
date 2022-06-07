#include "./vector_test.hpp"
#include "./map_test.hpp"
#include "./stack_test.hpp"
#include "./set_test.hpp"

int	is_cntr (char* s) {
	if (!s)
		return (-1);

	std::string	name = s;
	if (name == "vector")
		return (1);
	if (name == "map")
		return (2);
	if (name == "stack")
 		return (3);
	if (name == "set")
		return (4);

	return (0);
}

int	main(int argc, char **argv) {
	if (argc > 2 || !is_cntr(argv[1])) {
		std::cerr << "Usage: ./a.out [container]" << std::endl;
		return (1);
	}

	if (is_cntr(argv[1]) == 1 || argc == 1)
		vector_test();
	if (is_cntr(argv[1]) == 2 || argc == 1)
		map_test();
	if (is_cntr(argv[1]) == 3 || argc == 1)
		stack_test();
	if (is_cntr(argv[1]) == 4 || argc == 1)
		set_test();

	if (argc == 2)
		system("leaks a.out");
}

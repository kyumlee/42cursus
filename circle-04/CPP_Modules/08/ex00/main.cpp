#include "./easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

const char	*NotFoundException::what(void) const throw() {
	return ("not found");
}

int			main(void) {
	std::vector<int>	vec;
	std::deque<int>		deq;
	std::list<int>		lst;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	deq.push_back(10);
	deq.push_back(20);
	deq.push_back(30);
	deq.push_back(40);
	deq.push_back(50);

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	int	a = 0;
	try {
		 ::easyfind(vec, a);
		 std::cout << a << " found" << std::endl;
	} catch (std::exception &e) {
		std::cerr << a;
		std::cerr << " " << e.what() << std::endl;
	}

	a = 10;
	try {
		 ::easyfind(deq, a);
		 std::cout << a << " found" << std::endl;
	} catch (std::exception &e) {
		std::cerr << a;
		std::cerr << " " << e.what() << std::endl;
	}

	a = 0;
	try {
		 ::easyfind(lst, a);
		 std::cout << a << " found" << std::endl;
	} catch (std::exception &e) {
		std::cerr << a;
		std::cerr << " " << e.what() << std::endl;
	}
}

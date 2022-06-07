#include "./set_test.hpp"

void	print_set (Set& set, std::string name) {
	std::cout << "[" << name << "]" << std::endl;
	std::cout << "  size: " << set.size() << std::endl;
	std::cout << "  max_size: " << set.max_size() << std::endl;
	if (set.empty())
		std::cout << "  is empty!!!" << std::endl;
	else {
		for (set_iterator it = set.begin(); it != set.end(); it++)
			std::cout << "key: " << *it << std::endl;
	}
	std::cout << std::endl;
}

void	set_test () {
	std::cout << "=============== SET ==============" << std::endl << std::endl << std::endl;

	std::cout << "---------- CONSTRUCTORS ----------" << std::endl << std::endl;
	std::cout << "-- default constructor" << std::endl;
	Set	set;
	print_set(set, "set");

	std::cout << "-- insert one element" << std::endl;
	std::cout << "inserting '1': " << set.insert(1).second << std::endl;
	std::cout << "inserting '3': " << set.insert(3).second << std::endl;
	std::cout << "inserting '5': " << set.insert(5).second << std::endl;
	std::cout << "inserting '4': " << set.insert(4).second << std::endl;
	print_set(set, "set");
	std::cout << "-- insert already-existing element" << std::endl;
	std::cout << "inserting '3': " << set.insert(3).second << std::endl;
	print_set(set, "set");

	std::cout << "-- insert with hint" << std::endl;
	std::cout << "inserting '2' at begin(): " << std::endl;
	set.insert(set.begin(), 2);
	print_set(set, "set");

	std::cout << "-- insert range (++set.begin() ~ --set.end() to a new set2)" << std::endl;
	Set	set2;
	set2.insert(++set.begin(), --set.end());
	print_set(set2, "set2");

	std::cout << "-- range constructor" << std::endl;
	Set	set3(++set.begin(), --set.end());
	print_set(set3, "set3");

	std::cout << "-- assignment operator overload" << std::endl;
	Set	set4 = set;
	print_set(set4, "set4");

	std::cout << "set == set4: " << (set == set4) << std::endl;
	std::cout << "set2 != set3: " << (set2 != set3) << std::endl << std::endl;

	std::cout << "-- copy constructor" << std::endl;
	Set	set5(set2);
	print_set(set5, "set5");

	std::cout << "-- erase one element" << std::endl;
	std::cout << "[set] before erase:" << std::endl;
	print_set(set, "set");
	std::cout << "erasing element '3': " << set.erase(3) << std::endl;
	std::cout << "erasing element at set.begin()" << std::endl;
	set.erase(set.begin());
	std::cout << "erasing elements --(--set.end()) ~ set.end()" << std::endl;
	set.erase(--(--set.end()), set.end());
	print_set(set, "set");

	std::cout << "[set2] before swap with [set]:" << std::endl;
	print_set(set2, "set2");
	set2.swap(set);
	std::cout << "[set2] and [set] after swap:" << std::endl;
	print_set(set, "set");
	print_set(set2, "set2");

	std::cout << "-- clear" << std::endl;
	set.clear();
	std::cout << "[set] after clear:" << std::endl;
	print_set(set, "set");

	std::cout << "-- find" << std::endl;
	print_set(set3, "set3");

	std::cout << "find an element '1' in [set3]: ";
	std::cout << (*set3.find(1)) << std::endl;
	std::cout << "find an element '3' in [set3]: ";
	std::cout << *(set3.find(3)) << std::endl;

	std::cout << "-- count (set.count('a')): " << set.count(1) << std::endl;
	std::cout << "-- count (set3.count('c')): " << set3.count(3) << std::endl << std::endl;

	print_set(set4, "set4");
	std::cout << "-- lower & upper bounds" << std::endl;
	std::cout << "lower bound (set4 3): ";
	std::cout << *(set4.lower_bound(3)) << std::endl;

	std::cout << "lower bound (set4 9): ";
	std::cout << *(set4.lower_bound(9)) << std::endl;
	std::cout << "upper bound (set4 3): ";
	std::cout << *(set4.upper_bound(3)) << std::endl;

	std::cout << "upper bound (set4 9): ";
	std::cout << *(set4.upper_bound(9)) << std::endl;
	std::cout << "equal range (first): ";
	std::cout << *(set4.equal_range(4).first) << std::endl;
	std::cout << "equal range (second): ";
	std::cout << *(set4.equal_range(4).second) << std::endl;
}

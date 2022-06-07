#include "./map_test.hpp"

void	print_pair (NAMESPACE::pair<T_MAP1,T_MAP2> pr) {
	std::cout << "  key: [" << pr.first << "] | value: [" << pr.second << "]" << std::endl;
}

void	print_map (Map& map, std::string name) {
	std::cout << "[" << name << "]" << std::endl;
	std::cout << "  size: " << map.size() << std::endl;
	std::cout << "  max_size: " << map.max_size() << std::endl;
	if (map.empty())
		std::cout << "  is empty!!!" << std::endl;
	else {
		for (map_iterator it = map.begin(); it != map.end(); it++)
			print_pair(*it);
	}
	std::cout << std::endl;
}

void	map_test () {
	std::cout << "============== MAP ===============" << std::endl << std::endl << std::endl;

	std::cout << "---------- CONSTRUCTORS ----------" << std::endl << std::endl;
	std::cout << "-- default constructor" << std::endl;
	Map	map;
	print_map(map, "map");

	std::cout << "-- insert one pair" << std::endl;
	std::cout << "inserting ['c',\"de\"]: " << map.insert(NAMESPACE::make_pair('c', "de")).second << std::endl;
	std::cout << "inserting ['a',\"bc\"]: " << map.insert(NAMESPACE::make_pair('a', "bc")).second << std::endl;
	std::cout << "inserting ['d',\"ef\"]: " << map.insert(NAMESPACE::make_pair('d', "ef")).second << std::endl;
	std::cout << "inserting ['b',\"cd\"]: " << map.insert(NAMESPACE::make_pair('b', "cd")).second << std::endl;
	print_map(map, "map");
	std::cout << "-- insert a pair with already-existing key" << std::endl;
	std::cout << "inserting ['a',\"bc\"]: " << (map.insert(NAMESPACE::make_pair('a', "bc"))).second << std::endl;
	print_map(map, "map");

	std::cout << "-- operator[]" << std::endl;
	std::cout << "inserting ['e',\"fg\"]: " << (map['e'] = "fg") << std::endl;
	print_map(map, "map");
	std::cout << "inserting ['e',\"fg\"]: " << (map['e'] = "fg") << std::endl;
	print_map(map, "map");

	std::cout << "-- insert with hint" << std::endl;
	std::cout << "inserting ['f',\"gh\"] at begin(): " << std::endl;
	map.insert(map.begin(), NAMESPACE::make_pair('f', "gh"));
	print_map(map, "map");

	std::cout << "-- insert range (++map.begin() ~ --map.end() to a new map2)" << std::endl;
	Map	map2;
	map2.insert(++map.begin(), --map.end());
	print_map(map2, "map2");

	std::cout << "-- range constructor" << std::endl;
	Map	map3(++map.begin(), --map.end());
	print_map(map3, "map3");

	std::cout << "-- assignment operator overload" << std::endl;
	Map	map4 = map;
	print_map(map4, "map4");

	std::cout << "map == map4: " << (map == map4) << std::endl;
	std::cout << "map2 != map3: " << (map2 != map3) << std::endl << std::endl;

	std::cout << "-- copy constructor" << std::endl;
	Map	map5(map2);
	print_map(map5, "map5");

	std::cout << "-- erase one pair" << std::endl;
	std::cout << "[map] before erase:" << std::endl;
	print_map(map, "map");
	std::cout << "erasing pair with key 'b': " << map.erase('b') << std::endl;
	std::cout << "erasing pair at map.begin()" << std::endl;
	map.erase(map.begin());
	std::cout << "erasing pair --(--map.end()) ~ map.end()" << std::endl;
	map.erase(--(--map.end()), map.end());
	print_map(map, "map");

	std::cout << "[map2] before swap with [map]:" << std::endl;
	print_map(map2, "map2");
	map2.swap(map);
	std::cout << "[map2] and [map] after swap:" << std::endl;
	print_map(map, "map");
	print_map(map2, "map2");

	std::cout << "-- clear" << std::endl;
	map.clear();
	std::cout << "[map] after clear:" << std::endl;
	print_map(map, "map");

	std::cout << "-- find" << std::endl;
	print_map(map3, "map3");
	std::cout << "find a pair with key 'a' in [map3]: ";
	print_pair(*(map3.find('a'))); std::cout << std::endl;
	std::cout << "find a pair with key 'c' in [map3]: ";
	print_pair(*(map3.find('c'))); std::cout << std::endl;

	std::cout << "-- count (map.count('a')): " << map.count('a') << std::endl;
	std::cout << "-- count (map3.count('c')): " << map3.count('c') << std::endl << std::endl;

	print_map(map4, "map4");
	std::cout << "-- lower & upper bounds" << std::endl;
	std::cout << "lower bound (map4 'c'): ";
	print_pair(*(map4.lower_bound('c')));
	std::cout << "lower bound (map4 'z'): ";
	print_pair(*(map4.lower_bound('z')));
	std::cout << "upper bound (map4 'c'): ";
	print_pair(*(map4.upper_bound('c')));
	std::cout << "upper bound (map4 'z'): ";
	print_pair(*(map4.upper_bound('z')));
	std::cout << "equal range (first): ";
	print_pair(*(map4.equal_range('f').first));
	std::cout << "equal range (second): ";
	print_pair(*(map4.equal_range('f').second));
}

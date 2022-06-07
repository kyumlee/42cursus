#ifndef __MAP_TEST_HPP__
# define __MAP_TEST_HPP__

# include <iostream>
# include <map>
# include "./../map.hpp"

# if !defined(USING_STD)
#  define NAMESPACE	ft
# else
#  define NAMESPACE	std
# endif

# define T_MAP1	char
# define T_MAP2	std::string

typedef NAMESPACE::map<T_MAP1,T_MAP2>	Map;
typedef	Map::iterator					map_iterator;
typedef	Map::reverse_iterator			map_rev_iterator;

void	print_pair (NAMESPACE::pair<T_MAP1,T_MAP2> pr);
void	print_map (Map& map, std::string name);
void	map_test ();

#endif

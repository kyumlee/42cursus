#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <iostream>
# include <vector>
# include <map>
# include <fstream>
# include <sstream>
# include <string>

# define DEFAULT_CONF	"./conf/default.conf"

void						printErr (std::string errMsg);
std::vector<std::string>	split (std::string str, char delimiter = '\n');

#endif

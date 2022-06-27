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
std::vector<std::string>	splitBlocks (std::string str);
std::pair<bool, size_t>		skipKey (std::string line, std::string str);
bool						isNumber (std::string str);
std::string					parseValue (std::string line, size_t pos);

#endif

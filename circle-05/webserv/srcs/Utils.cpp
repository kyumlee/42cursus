#include "./../includes/Utils.hpp"

void						printErr (std::string errMsg) {
	std::cerr << "Error: " << errMsg << std::endl;
}

std::vector<std::string>	split (std::string str, char delimiter) {
	size_t						pos_start = 0, pos_end;
	std::vector<std::string>	ret;
	std::string					token;

	while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos) {
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + 1;
		ret.push_back(token);
	}
//	ret.push_back(str.substr(pos_start));
	return (ret);
}

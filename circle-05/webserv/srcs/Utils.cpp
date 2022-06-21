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
	ret.push_back(str.substr(pos_start));
	return (ret);
}

std::vector<std::string>	splitBlocks (std::string str) {
	std::vector<std::string>	ret;

	size_t	openBracketPos = 0, closeBracketPos = 0;
	while (1) {
		openBracketPos = str.find("{", openBracketPos);
		closeBracketPos = str.find("}", openBracketPos);

		if (openBracketPos == std::string::npos)
			break ;
		if (openBracketPos > closeBracketPos)
			break ;

		if (str.substr(openBracketPos, closeBracketPos - openBracketPos).find("location") != std::string::npos)
			closeBracketPos = str.find("}", closeBracketPos + 1);

		ret.push_back(str.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1));

		openBracketPos = closeBracketPos + 1;
	}

	for (size_t i = 0; i < ret.size(); i++)
		ret[i].erase(std::remove(ret[i].begin(), ret[i].end(), '\t'), ret[i].end());

	return (ret);
}

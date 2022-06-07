#include "./Replace.hpp"
#include <string>

int	printError(std::string errMsg) {
	std::cerr << errMsg << std::endl;
	return (0);
}

std::string	readFile(std::string filename) {
	std::ifstream	in;
	std::string		buffer;
	int				size;

	in.open(filename);
	in.seekg(0, std::ios::end);
	size = in.tellg();
	buffer.resize(size);
	in.seekg(0, std::ios::beg);
	in.read(&buffer[0], size);
	return (buffer);
}

std::string	doReplace(std::string filename, std::string s1, std::string s2) {
	int			s1Pos = 0;
	std::string	content = readFile(filename);
	std::string	before;
	std::string	after;

	while (1) {
		s1Pos = content.find(s1, s1Pos);
		if (s1Pos == (int)std::string::npos) break ;
		before = content.substr(0, s1Pos);
		after = content.substr(s1Pos + s1.length(),
			content.length() - before.length());
		content = before + s2 + after;
		s1Pos += s2.length();
	};
	return (content);
}

int	replace(std::string filename, std::string s1, std::string s2) {
	std::ifstream	in(filename);
	std::string		content;

	if (filename.empty()) return (printError("FILENAME IS EMPTY"));
	if (s1.empty()) return (printError("S1 IS EMPTY"));
	if (!in.is_open()) return (printError("NO SUCH FILE"));
	content = doReplace(filename, s1, s2);
	
	std::ofstream	out(filename + ".replace");
	out << content;
	return (1);
}

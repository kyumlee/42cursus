#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "address in memory of the string:" << std::endl;
	std::cout << " -> " << &str << std::endl;

	std::cout << std::endl;
	std::cout << "address of the string by using strPTR:" << std::endl;
	std::cout << " -> " << strPTR << std::endl;
	std::cout << "address of the string by using strREF:" << std::endl;
	std::cout << " -> " << &strREF << std::endl;

	std::cout << std::endl;
	std::cout << "string using strPTR:" << std::endl;
	std::cout << " -> " << *strPTR << std::endl;
	std::cout << "string using strREF:" << std::endl;
	std::cout << " -> " << strREF << std::endl;
	std::cout << std::endl;
}

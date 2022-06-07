#include "./span.hpp"

int	main(void) {

	// Deep copy
	{
		std::cout << "----------- DEEP COPY -----------" << std::endl;

		Span	sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

//		Span	sp2(sp);

		Span	sp2(5);
		sp2.addRandomNumbers();

		sp2 = sp;
		sp2.deleteNumber();
		sp2.addNumber(12);

		std::cout << "sp address: " << &sp << std::endl;
		std::cout << sp << std::endl;

		std::cout << "sp2 address: " << &sp2 << std::endl;
		std::cout << sp2 << std::endl;
		std::cout << "----------- DEEP COPY -----------" << std::endl << std::endl;
	}

	// empty or one element in span
	{
		std::cout << "---------- ZERO OR ONE ----------" << std::endl;

		Span	sp = Span(5);
		std::cout << sp << std::endl;

		try {
			std::cout << "shortest span of sp: " << sp.shortestSpan() << std::endl;
			std::cout << " longest span of sp: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		} std::cout << std::endl;

		sp.addNumber(0);
		std::cout << sp << std::endl;

		try {
			std::cout << "shortest span of sp: " << sp.shortestSpan() << std::endl;
			std::cout << " longest span of sp: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "---------- ZERO OR ONE ----------" << std::endl << std::endl;
	}

	// random numbers
	{
		std::cout << "------------- NORMAL ------------" << std::endl;

		Span	sp = Span(5);
		sp.addRandomNumbers();
		std::cout << sp << std::endl;

		std::cout << "shortest span of sp: " << sp.shortestSpan() << std::endl;
		std::cout << " longest span of sp: " << sp.longestSpan() << std::endl;
		std::cout << "------------- NORMAL ------------" << std::endl << std::endl;

		// adding to full object
		std::cout << "----------- FULL OBJECT ---------" << std::endl;
		try {
			sp.addNumber(42);
		} catch (std::exception &e) {
			std::cerr << "  " << e.what() << std::endl;
		}
		std::cout << "----------- FULL OBJECT ---------" << std::endl << std::endl;
	}

	// int overflow
	{
		std::cout << "----------- INT MAX/MIN ---------" << std::endl;

		Span	sp = Span(5);
		sp.addNumber(INT_MAX);
		sp.addNumber(-1);
		sp.addNumber(1);
		sp.addNumber(INT_MIN);
		sp.addNumber(0);
		std::cout << sp << std::endl;

		try {
			std::cout << "shortest span of sp: " << sp.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << " longest span of sp: " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "----------- INT MAX/MIN ---------" << std::endl << std::endl;
	}
}

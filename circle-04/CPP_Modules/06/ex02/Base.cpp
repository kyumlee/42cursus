#include "./Base.hpp"
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"

Base::~Base(void) {}

Base	*generate(void) {
	std::srand(time(NULL));
	int	i = std::rand() % 3;

	switch (i) {
		case 0:	return (new A());
		case 1:	return (new B());
		case 2:	break ;
	}
	return (new C());
}

void	identify(Base *p) {
	std::cout << "type (*p): ";

/*	std::cout << std::endl << "Base: " <<  p << std::endl;

	std::cout << "A: " << dynamic_cast<A *>(p) << std::endl;
	std::cout << "B: " << dynamic_cast<B *>(p) << std::endl;
	std::cout << "C: " << dynamic_cast<C *>(p) << std::endl;*/

	if (dynamic_cast<A *>(p))	std::cout << "A";
	if (dynamic_cast<B *>(p))	std::cout << "B";
	if (dynamic_cast<C *>(p))	std::cout << "C";

	std::cout << std::endl;
}

void	identify(Base &p) {
	std::cout << "type (&p): ";

/*	std::cout << std::endl << "Base: " <<  &p << std::endl;

	std::cout << std::endl << "A: " << &dynamic_cast<A &>(p) << std::endl;
	std::cout << std::endl << "B: " << &dynamic_cast<B &>(p) << std::endl;
	std::cout << std::endl << "C: " << &dynamic_cast<C &>(p) << std::endl;*/

	try {
		A	&a = dynamic_cast<A &>(p);
		(void)a;
//		std::cout << "A: " <<  &a << std::endl;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		B	&b = dynamic_cast<B &>(p);
		(void)b;
//		std::cout << "B: " <<  &b << std::endl;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		C	&c = dynamic_cast<C &>(p);
		(void)c;
//		std::cout << "C: " <<  &c << std::endl;
		std::cout << "C" << std::endl;
	} catch (std::exception &e) {}
}

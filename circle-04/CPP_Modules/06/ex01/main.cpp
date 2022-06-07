#include "./Data.hpp"

int	main(void) {
	Data		*d = new Data;
	uintptr_t	p;

	d->c = 'a';
	d->i = 0;
	d->f = 1.2f;
	d->d = 3.4;
	std::cout << "original address of d: " << std::endl;
	std::cout << "--> " << d << std::endl;
	p = serialize(d);
	std::cout << "serialized object: " << std::endl;
	std::cout << "--> " << p << std::endl;
	d = deserialize(p);
	std::cout << "address of d after deserialization: " << std::endl;
	std::cout << "--> " << d << std::endl;
}

#include "./Fixed.hpp"
#include "./Point.hpp"

int	main(void) {
	Point	points[4];
/*	Point	a(0, 0);
	Point	b(10, 30);
	Point	c(20, 0);
	Point	p(10, 15);
	Point	p2(30, 15);*/
	bool	inside;
	int	x, y;

	for (int i = 0; i < 4; i++) {
		std::cout << "Enter x for ";
		if (i != 3) std::cout << "V" << i + 1 << ": ";
		else std::cout << "Point: ";
		std::cin >> x;
		std::cout << "Enter y for ";
		if (i != 3) std::cout << "V" << i + 1 << ": ";
		else std::cout << "Point: ";
		std::cin >> y;
		points[i] = Point(x, y);
		std::cout << std::endl;
	}

	inside = bsp(points[0], points[1], points[2], points[3]);
//	inside = bsp(a, b, c, p);

	std::cout << std::endl;
	std::cout << "Therefore, the point is ";
	if (inside) std::cout << "INSIDE";
	else std::cout << "OUTSIDE";
	std::cout << " the triangle." << std::endl;

	return (0);
}

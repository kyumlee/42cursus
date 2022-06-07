#include "./Point.hpp"

Fixed	getArea(Point const a, Point const b, Point const c) {
	Fixed	area;

	area = (((Fixed)a.getX() * ((Fixed)b.getY() - (Fixed)c.getY())) +
		((Fixed)b.getX() * ((Fixed)c.getY() - (Fixed)a.getY())) +
		((Fixed)c.getX() * ((Fixed)a.getY() - (Fixed)b.getY()))) / 2;

	if (area < 0) area = area * -1;

	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	abc;
	Fixed	pab;
	Fixed	pbc;
	Fixed	pca;
	Fixed	sum;
	bool	result;

	std::cout << "V1: " << a << std::endl;
	std::cout << "V2: " << b << std::endl;
	std::cout << "V3: " << c << std::endl;
	std::cout << "Point: " << point << std::endl;
	
	abc = getArea(a, b, c);
	pab = getArea(point, a, b);
	pbc = getArea(point, b, c);
	pca = getArea(point, c, a);

	std::cout << std::endl;
	std::cout << "If the sum of the areas of triangles(two V's and a point) is equal to the area of the triangle(" << abc << "), the point is inside that triangle." << std::endl;

	std::cout << std::endl;
	std::cout << "PAB(" << pab << ") + PBC(" << pbc << ") + PCA(" << pca << ") = " << (sum = pab + pbc + pca) << std::endl;

	result = sum == abc;

	std::cout << std::endl;
	std::cout << "The sum of the areas of PAB, PBC, PCA is ";
	if (result)
		std::cout << "EQUAL";
	else std::cout << "NOT EQUAL";
	std::cout << " to the area of ABC." << std::endl;
	return (result ? true : false);
}

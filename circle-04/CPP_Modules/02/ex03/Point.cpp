#include "./Point.hpp"

Point::Point(void): x(0), y(0) {};

Point::~Point(void) {}

Point::Point(const Point &p): x(p.x), y(p.y) {}

Point::Point(const Fixed _x, const Fixed _y): x(_x), y(_y) {}

Point			&Point::operator=(const Point &p) {
	if (this != &p) {
		(Fixed &)x = p.getX();
		(Fixed &)y = p.getY();
	}
	return (*this);
}

const Fixed		&Point::getX(void) const { return (x); }

const Fixed		&Point::getY(void) const { return (y); }

std::ostream	&operator<<(std::ostream &os, const Point &p) {
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return (os);
}

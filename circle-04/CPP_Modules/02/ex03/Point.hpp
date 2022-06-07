#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "./Fixed.hpp"

class	Point {

	private:
		Fixed const	x;
		Fixed const y;

	public:
		Point(void);
		~Point(void);
		Point(const Point &p);
		Point(const Fixed _x, const Fixed _y);
		Point		&operator=(const Point &p);
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;
};

bool				bsp(Point const a, Point const b, Point const c, Point const point);

std::ostream		&operator<<(std::ostream &os, const Point &p);

#endif

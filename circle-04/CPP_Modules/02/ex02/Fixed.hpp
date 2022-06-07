#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath>

class	Fixed {

	private:
		int					fixedPointValue;
		static const int	FRACTIONAL_BITS = 8;

	public:
		Fixed(void);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &f);
		~Fixed(void);
		Fixed				&operator=(const Fixed &f);
		bool				operator>(const Fixed &f);
		bool				operator<(const Fixed &f);
		bool				operator>=(const Fixed &f);
		bool				operator<=(const Fixed &f);
		bool				operator==(const Fixed &f);
		bool				operator!=(const Fixed &f);
		Fixed				operator+(const Fixed &f);
		Fixed				operator-(const Fixed &f);
		Fixed				operator*(const Fixed &f);
		Fixed				operator/(const Fixed &f);
		Fixed				&operator++(void);
		Fixed				&operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static const Fixed 	&min(const Fixed &f1, const Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

};

std::ostream	&operator<<(std::ostream &os, const Fixed &f);

#endif

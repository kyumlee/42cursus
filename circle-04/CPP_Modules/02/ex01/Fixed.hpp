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
		Fixed	&operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &os, const Fixed &f);

#endif

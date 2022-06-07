#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class	Fixed {

	private:
		int					fixedPointValue;
		static const int	FRACTIONAL_BITS = 8;

	public:
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
		Fixed	&operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif

#ifndef __CONVERT_HPP__
# define __CONVERT_HPP__

# include <iostream>
# include <iomanip>
# include <limits>

# define CHAR	1
# define INT	2
# define FLOAT	3
# define DOUBLE	4
# define PSEUDO	5
# define ERROR	-1

class	Convert {

	private:
		std::string		_input;
		int				_type;
		char			_c;
		int				_i;
		float			_f;
		double			_d;

	public:
		Convert(void);
		Convert(const std::string &input);
		Convert(const Convert &cvt);
		~Convert(void);

		Convert			&operator=(const Convert &cvt);
		
		std::string		getInput(void) const;
		int				getType(void) const;
		char			getC(void) const;
		int				getI(void) const;
		float			getF(void) const;
		double			getD(void) const;

		bool			isPseudo(void) const;
		bool			isChar(void) const;
		bool			isInt(void) const;
		bool			isFloat(void) const;
		bool			isDouble(void) const;

		bool			isInIntRange(void) const;

		void			detectType(void);
		void			convert(void);

		void			printChar(std::ostream &os) const;
		void			printInt(std::ostream &os) const;
		void			printFloat(std::ostream &os) const;
		void			printDouble(std::ostream &os) const;

		class			NoParameterException : public std::exception {
			const char	*what(void) const throw();
		};

};

std::ostream			&operator<<(std::ostream &os, const Convert &cvt);

#endif

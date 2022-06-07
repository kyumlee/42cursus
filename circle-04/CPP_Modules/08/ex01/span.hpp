#ifndef __SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <vector>
# include <algorithm>

class	Span {

	private:
		std::vector<int>	_vec;
		size_t				_size;

	public:
		Span(void);
		Span(unsigned int num);
		Span(const Span &sp);
		Span				&operator=(const Span &sp);
		~Span(void);

		void				addNumber(int num);
		unsigned int		shortestSpan(void) const;
		unsigned int		longestSpan(void) const;

		std::vector<int>	getVec(void) const;
		size_t				getSize(void) const;
		int					getElem(int i) const;
		void				deleteNumber(void);
		void				addRandomNumbers(void);

		class				EmptySpanException : public std::exception {
			const char		*what(void) const throw();
		};

		class				ObjectIsFullException : public std::exception {
			const char		*what(void) const throw();
		};

		class				NotEnoughNumbersException : public std::exception {
			const char		*what(void) const throw();
		};

		class				IntOverflowException : public std::exception {
			const char		*what(void) const throw();
		};

};

std::ostream				&operator<<(std::ostream &os, const Span &sp);

#endif

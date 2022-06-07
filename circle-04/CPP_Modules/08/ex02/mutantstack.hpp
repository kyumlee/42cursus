#ifndef __MUTANT_STACK_HPP__
# define __MUTANT_STACK_HPP__

# include <iostream>
# include <stack>
# include <list>
# include <algorithm>

template < typename T>
class	MutantStack : public std::stack<T> {

	public:

		typedef typename std::stack<T>::container_type::iterator			iterator;

		MutantStack(void) : std::stack<T>() {}
		MutantStack(const MutantStack &ms) : std::stack<T>(ms) {}
		~MutantStack(void) {}
		MutantStack			&operator=(const MutantStack &ms) {
			this->c = ms.c;
			return (*this);
		}

		iterator			begin(void) { return (this->c.begin()); }
		iterator			end(void) { return (this->c.end()); }

};

#endif

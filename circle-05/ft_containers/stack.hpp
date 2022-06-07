#ifndef __STACK_HPP__
# define __STACK_HPP__

#include "./vector.hpp"

namespace	ft {

	template< class T, class Container = ft::vector<T> >
	class	stack {
		public:
			typedef				Container						container_type;
			typedef	typename	container_type::value_type		value_type;
			typedef	typename	container_type::size_type		size_type;
			typedef	typename	container_type::reference		reference;
			typedef	typename	container_type::const_reference	const_reference;

			explicit	stack (const container_type& ctnr = container_type()) : c(ctnr) {}
			~stack () {}

			stack& 				operator= (const stack& other) {
			   c = other.c;
			   return (*this);
			}

			bool				empty () const { return (c.empty()); }
			size_type			size () const { return (c.size()); }

			value_type&			top () { return (c.back()); }
			const value_type&	top () const { return (c.back()); }

			void				push (const value_type& val) { c.push_back(val); }
			void				pop () { c.pop_back(); }

		protected:
			container_type	c;

		template< class U, class Cont >
		friend bool	operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
		template< class U, class Cont >
		friend bool	operator<  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs);
	};

	template< class U, class Cont >
	bool	operator== (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (lhs.c == rhs.c); }
	template< class U, class Cont >
	bool	operator!= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (!(lhs == rhs)); }
	template< class U, class Cont >
	bool	operator<  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (lhs.c < rhs.c); }
	template< class U, class Cont >
	bool	operator<= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (!(rhs < lhs)); }
	template< class U, class Cont >
	bool	operator>  (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (rhs < lhs); }
	template< class U, class Cont >
	bool	operator>= (const stack<U,Cont>& lhs, const stack<U,Cont>& rhs) { return (!(lhs < rhs)); }
}

#endif

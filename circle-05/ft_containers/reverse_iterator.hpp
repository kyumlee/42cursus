#ifndef __REVERSE_ITERATOR_HPP__
# define __REVERSE_ITERATOR_HPP__

# include "./iterator.hpp"

namespace	ft {

	template< class Iterator >
	class	reverse_iterator {
		public:
			typedef				Iterator							iterator_type;
			typedef	typename	ft::iterator_traits<iterator_type>	iterator_traits;
			typedef	typename	iterator_traits::iterator_category	iterator_category;
			typedef	typename	iterator_traits::value_type			value_type;
			typedef	typename	iterator_traits::difference_type	difference_type;
			typedef	typename	iterator_traits::pointer			pointer;
			typedef	typename	iterator_traits::reference			reference;

			reverse_iterator () : current() {}
			explicit		reverse_iterator (iterator_type it) : current(it) {}
			template< class Iter >
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {}

			template< class Iter >
			reverse_iterator&	operator=  (const reverse_iterator<Iter>& other) {
				current = other.base();
				return (*this);
			}
			~reverse_iterator () {}

			iterator_type		base () const { return (current); }

			reference			operator*  () const {
				iterator_type	tmp = current;
				return (*(--tmp));
			}
			pointer				operator-> () const { return (&(operator*())); }

			reference			operator[] (difference_type n) const { return (base()[-n - 1]); }

			reverse_iterator&	operator++ () {
				current--;
				return (*this);
			}
			reverse_iterator&	operator-- () {
				current++;
			return (*this);
			}
			reverse_iterator	operator++ (int) {
				reverse_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}
			reverse_iterator	operator-- (int) {
				reverse_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}
			reverse_iterator	operator+  (difference_type n) { return (reverse_iterator(base() - n)); }
			reverse_iterator	operator-  (difference_type n) { return (reverse_iterator(base() + n)); }
			reverse_iterator&	operator+= (difference_type n) {
				current -= n;
				return (*this);
			}
			reverse_iterator&	operator-= (difference_type n) {
				current += n;
				return (*this);
			}

		protected:
			iterator_type	current;
	};

	template< class Iterator1, class Iterator2 >
	bool						operator== (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() == rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool						operator!= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool						operator<  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() > rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool						operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() >= rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool						operator>  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() < rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool						operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return (lhs.base() <= rhs.base()); }

	template< class Iter >
	ft::reverse_iterator<Iter>	operator+  (typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& it) { return (ft::reverse_iterator<Iter>(it.base() - n)); }

	template< class Iter >
	typename ft::reverse_iterator<Iter>::difference_type	operator-  (const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs) { return (rhs.base() - lhs.base()); }
	template< class Iter, class Iter2 >
	typename ft::reverse_iterator<Iter>::difference_type	operator-  (const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter2>& rhs) { return (rhs.base() - lhs.base()); }

}

#endif

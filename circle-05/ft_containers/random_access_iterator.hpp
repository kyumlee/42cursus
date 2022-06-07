#ifndef __RANDOM_ACCESS_ITERATOR_HPP__
# define __RANDOM_ACCESS_ITERATOR_HPP__

# include "./utils.hpp"
# include "./iterator.hpp"

namespace	ft {

	template< typename T >
	class	random_access_iterator : ft::iterator< ft::random_access_iterator_tag, T > {
		public:
			typedef	typename	ft::iterator< ft::random_access_iterator_tag, T >	iterator_type;
			typedef	typename	iterator_type::difference_type						difference_type;
			typedef	typename	iterator_type::iterator_category					iterator_category;
			typedef				T													value_type;
			typedef				T*													pointer;
			typedef				T&													reference;
			typedef				const T*											const_pointer;
			typedef 			const T&											const_reference;
			
			random_access_iterator () : _ptr(nullPtr) {}
			random_access_iterator (pointer ptr) : _ptr(ptr) {}
			random_access_iterator (const random_access_iterator& it) : _ptr(it.base()) {}
			random_access_iterator&	operator=  (const random_access_iterator& it) {
				_ptr = it.base();
				return (*this);
			}
			~random_access_iterator () {}
			operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(base())); }

			reference				operator*  () const { return (*_ptr); }
			pointer					operator-> () const { return (_ptr); }
			pointer					base () const { return (_ptr); }

			random_access_iterator&	operator++ () {
				_ptr++;
				return (*this);
			}
			random_access_iterator	operator++ (int) {
				random_access_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			random_access_iterator&	operator-- () {
				_ptr--;
				return (*this);
			}
			random_access_iterator	operator-- (int) {
				random_access_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			bool					operator== (const random_access_iterator& rhs) const { return (base() == rhs.base()); }
			bool					operator!= (const random_access_iterator& rhs) const { return (base() != rhs.base()); }

			random_access_iterator	operator+  (int index) { return (_ptr + index); }
			random_access_iterator	operator-  (int index) { return (_ptr - index); }

			bool					operator<  (const random_access_iterator& rhs) const { return (base() < rhs.base()); }
			bool					operator>  (const random_access_iterator& rhs) const { return (base() > rhs.base()); }
			bool					operator<= (const random_access_iterator& rhs) const { return (base() <= rhs.base()); }
			bool					operator>= (const random_access_iterator& rhs) const { return (base() >= rhs.base()); }

			random_access_iterator&	operator+= (int index) {
				_ptr += index;
				return (*this);
			}
			random_access_iterator&	operator-= (int index) {
				_ptr -= index;
				return (*this);
			}

			reference				operator[] (int index) { return (*(_ptr + index)); }

		private:
			pointer				_ptr;
	};

	template< typename T >
	bool	operator== (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() == rhs.base()); }
	template< typename T, typename U >
	bool	operator== (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() == rhs.base()); }

	template< typename T >
	bool	operator!= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() != rhs.base()); }
	template< typename T, typename U >
	bool	operator!= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() != rhs.base()); }

	template< typename T >
	bool	operator<  (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() < rhs.base()); }
	template< typename T, typename U >
	bool	operator<  (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() < rhs.base()); }

	template< typename T >
	bool	operator>  (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() > rhs.base()); }
	template< typename T, typename U >
	bool	operator>  (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() > rhs.base()); }

	template< typename T >
	bool	operator<= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() <= rhs.base()); }
	template< typename T, typename U >
	bool	operator<= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() <= rhs.base()); }

	template< typename T >
	bool	operator>= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs) { return (lhs.base() >= rhs.base()); }
	template< typename T, typename U >
	bool	operator>= (const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<U> rhs) { return (lhs.base() >= rhs.base()); }

	template< typename T >
	ft::random_access_iterator<T>	operator+ (typename ft::random_access_iterator<T>::difference_type n, const ft::random_access_iterator<T>& it) { return (ft::random_access_iterator<T>(it.base() + n)); }

	template< typename T >
	typename ft::random_access_iterator<T>::difference_type	operator- (const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<T>& rhs) { return (lhs.base() - rhs.base()); }
	template< typename T, typename U >
	typename ft::random_access_iterator<T>::difference_type	operator- (const ft::random_access_iterator<T>& lhs, const ft::random_access_iterator<U>& rhs) { return (lhs.base() - rhs.base()); }

}

#endif

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <memory>

# define BLACK	0
# define RED	1

namespace	ft {

	const class	nullptr_t {
		public:
			template< typename T >
			operator	T* () const { return (0); }

			template< typename T, typename U >
			operator	T U::* () const { return (0); }

		private:
			void		operator& () const;

	} nullPtr = {};

	template< bool B, class T = void >
	struct	enable_if {};

	template< class T >
	struct	enable_if<true, T> { typedef T type; };

	template< class T, T v >
	struct	integral_constant {
		typedef	T						value_type;
		typedef	integral_constant<T,v>	type;
		static const value_type			value = v;
	};

	template< typename >
	struct	check_type : public integral_constant<bool, false> {};

	template<>
	struct	check_type<bool> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<char> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<char16_t> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<char32_t> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<wchar_t> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<signed char> : public integral_constant<bool, true> {};

	template<>
	struct	check_type<short int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<long int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<long long int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<unsigned char> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<unsigned short int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<unsigned int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<unsigned long int> : public integral_constant<bool, true> {};
	
	template<>
	struct	check_type<unsigned long long int> : public integral_constant<bool, true> {};

	template< class T >
	struct	is_integral : public check_type<T> {};

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template< class InputIt1, class InputIt2 >
	bool	pred (const InputIt1 &a, const InputIt2 &b) {
		return (*a == *b ? true : false);
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template< class InputIt1, class InputIt2 >
	bool	cmp (const InputIt1 &a, const InputIt2 &b) {
		return (a < b ? true : false);
	}

	template< class InputIt1, class InputIt2 >
	bool	lexicographical_compare (InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool	lexicographical_compare (InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template< typename T >
	class	Node {
		public:
			typedef	T	value_type;

			value_type	_data;
			Node*		_parent;
			Node*		_left;
			Node*		_right;
			bool		_color;

			Node ()
				: _data(), _parent(nullPtr), _left(nullPtr), _right(nullPtr), _color(BLACK) {}
			Node (const value_type& data, Node* parent = nullPtr, Node* left = nullPtr, Node* right = nullPtr, bool color = RED)
				: _data(data), _parent(parent), _left(left), _right(right), _color(color) {}
			Node (const Node& other)
				: _data(other._data), _parent(other._parent), _left(other._left), _right(other._right), _color(other._color) {}
			~Node () {}
			Node&	operator= (const Node& rhs) {
				_data = rhs._data;
				_parent = rhs._parent;
				_left = rhs._left;
				_right = rhs._right;
				_color = rhs._color;

				return (*this);
			}
	};

	template< class T1, class T2 >
	struct	pair {
		public:
			typedef	T1	first_type;
			typedef	T2	second_type;

			first_type	first;
			second_type	second;

			pair () : first(), second() {}
			template< class U, class V >
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}
			pair (const first_type& a, const second_type& b) : first(a), second(b) {}

			pair&	operator= (const pair& pr) {
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	};

	template< class T1, class T2 >
	bool	operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
	template< class T1, class T2 >
	bool	operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (!(lhs == rhs)); }
	template< class T1, class T2 >
	bool	operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }
	template< class T1, class T2 >
	bool	operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (!(rhs < lhs)); }
	template< class T1, class T2 >
	bool	operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (rhs < lhs); }
	template< class T1, class T2 >
	bool	operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return (!(lhs < rhs)); }

	template< class T1, class T2 >
	ft::pair<T1,T2>	make_pair (T1 x, T2 y) { return (ft::pair<T1,T2>(x, y)); }

	template< class Arg1, class Arg2, class Result >
	struct	binary_function {
		typedef	Arg1	first_argument_type;
		typedef	Arg2	second_argument_type;
		typedef	Result	result_type;
	};

	template< class T >
	struct	less : binary_function<T,T,bool> {
		bool	operator () (const T& x, const T& y) const { return (x < y); }
	};

	template< bool flag, class IsTrue, class IsFalse >
	struct	choose;
	template< class IsTrue, class IsFalse >
	struct	choose<true, IsTrue, IsFalse> {
	   typedef	IsTrue	type;
	};
	template< class IsTrue, class IsFalse >
	struct	choose<false, IsTrue, IsFalse> {
	   typedef	IsFalse	type;
	};

}

#endif

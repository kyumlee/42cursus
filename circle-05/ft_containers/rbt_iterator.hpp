#ifndef __RBT_ITERATOR_HPP__
# define __RBT_ITERATOR_HPP__

# include "./utils.hpp"
# include "./iterator.hpp"

namespace	ft {

	template< typename T, bool B, class Compare = ft::less<T> >
	class	rbt_iterator : ft::iterator< bidirectional_iterator_tag, T > {
		public:
			typedef	typename	ft::iterator< ft::bidirectional_iterator_tag, T >	iterator_type;
			typedef				T													value_type;
			typedef	typename	choose<B, const T&, T&>::type						reference;
			typedef	typename	choose<B, const T*, T*>::type						pointer;
			typedef	typename	iterator_type::difference_type						difference_type;
			typedef	typename	iterator_type::iterator_category					iterator_category;
		private:
			typedef				ft::Node<value_type>								node;
			typedef				node*												node_pointer;

		public:
			rbt_iterator () : _ptr(nullPtr) {}
			rbt_iterator (node_pointer ptr) : _ptr(ptr) {}
			rbt_iterator (const rbt_iterator& it) : _ptr(it._ptr) {}
			rbt_iterator&	operator=  (const rbt_iterator& it) {
				_ptr = it._ptr;
				return (*this);
			}
			~rbt_iterator () {}
			operator	rbt_iterator<T, true> () const { return (rbt_iterator<T, true>(_ptr)); }

			reference		operator*  () const { return (_ptr->_data); }
			pointer			operator-> () const { return (&_ptr->_data); }
			node_pointer	base () const { return (_ptr); }

			rbt_iterator&	operator++ () {
				_ptr = _successor(_ptr);
				return (*this);
			}
			rbt_iterator	operator++ (int) {
				rbt_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			rbt_iterator&	operator-- () {
				_ptr = _predecessor(_ptr);
				return (*this);
			}
			rbt_iterator	operator-- (int) {
				rbt_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			bool			operator== (const rbt_iterator& rhs) const { return (_ptr == rhs._ptr); }
			bool			operator!= (const rbt_iterator& rhs) const { return (_ptr != rhs._ptr); }

		private:
			node_pointer	_ptr;

			bool			_isLeaf (node_pointer n) {
				if (n->_color == BLACK && n->_left == nullPtr && n->_right == nullPtr)
					return (true);
				return (false);
			}

			bool			_isStart (node_pointer n) {
				if (n->_parent == nullPtr && n->_left != nullPtr && n->_left == n->_right)
					return (true);
				return (false);
			}

			node_pointer	_minimum (node_pointer x) {
				while (!_isLeaf(x->_left))
					x = x->_left;
				return (x);
			}

			node_pointer	_maximum (node_pointer x) {
				while (!_isLeaf(x->_right))
					x = x->_right;
				return (x);
			}

			node_pointer	_successor (node_pointer x) {
				if (!_isLeaf(x->_right))
					return (_minimum(x->_right));

				node_pointer	y = x->_parent;
				while (!_isStart(y) && x == y->_right) {
					x = y;
					y = y->_parent;
				}
				return (y);
			}

			node_pointer	_predecessor (node_pointer x) {
				if (_isStart(x))
					return (_maximum(x->_right));

				if (!_isLeaf(x->_left))
					return (_maximum(x->_left));

				node_pointer	y = x->_parent;
				while (!_isStart(y) && x == y->_left) {
					x = y;
					y = y->_parent;
				}
				return (y);
			}
	};

	template< typename T >
	bool			operator== (const rbt_iterator<T,true>& lhs, const rbt_iterator<T,true>& rhs) { return (lhs.base() == rhs.base()); }
	template< typename T >
	bool			operator== (const rbt_iterator<T,false>& lhs, const rbt_iterator<T,false>& rhs) { return (lhs.base() == rhs.base()); }
	template< typename T >
	bool			operator!= (const rbt_iterator<T,true>& lhs, const rbt_iterator<T,true>& rhs) { return (lhs.base() != rhs.base()); }
	template< typename T >
	bool			operator!= (const rbt_iterator<T,false>& lhs, const rbt_iterator<T,false>& rhs) { return (lhs.base() != rhs.base()); }

}

#endif

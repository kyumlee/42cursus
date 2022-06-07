#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

# include "./rbt_iterator.hpp"
# include "./reverse_iterator.hpp"

namespace	ft {

	template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class	RedBlackTree {
		private:
			typedef				ft::Node<T>										node;
			typedef				node*											node_pointer;
			typedef				std::allocator<node>							node_allocator_type;
		public:
			typedef				T												value_type;
			typedef				Compare											value_compare;
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::rbt_iterator<value_type, false>				iterator;
			typedef	typename	ft::rbt_iterator<value_type, true>				const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename	std::ptrdiff_t									difference_type;
			typedef				std::size_t										size_type;

			RedBlackTree (const value_compare& comp,
				const allocator_type& alloc = allocator_type(),
				const node_allocator_type& nalloc = node_allocator_type())
			: _alloc(alloc), _nalloc(nalloc), _comp(comp), _start(_initNIL()), _NIL(_initNIL()), _size(0) {
			}
			RedBlackTree (const RedBlackTree& other)
			: _alloc(other.alloc), _nalloc(other.nalloc), _comp(other.comp), _start(other._start), _NIL(other._start), _size(0) {
				for (const_iterator tmp = other.cbegin(); tmp != other.cend(); tmp++)
					insert(*tmp);
			}
			~RedBlackTree () {
				clear();
				_nalloc.destroy(_NIL);
				_nalloc.deallocate(_NIL, 1);
				_nalloc.destroy(_start);
				_nalloc.deallocate(_start, 1);
			}
			RedBlackTree&			operator= (const RedBlackTree& rhs) {
				clear();
				for (const_iterator tmp = rhs.begin(); tmp != rhs.end(); tmp++)
					insert(*tmp);
				return (*this);
			}

			iterator				begin () { return (empty() ? iterator(_start) : iterator(_minimum(_getRoot()))); }
			const_iterator			begin () const { return (empty() ? const_iterator(_start) : const_iterator(_minimum(_getRoot()))); }

			iterator				end () { return (iterator(_start)); }
			const_iterator			end () const { return (const_iterator(_start)); }

			reverse_iterator		rbegin () { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin () const { return (const_reverse_iterator(end())); }

			reverse_iterator		rend () { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend () const { return (const_reverse_iterator(begin())); }

			bool					empty () const { return (!_size); }
			size_type				size () const { return (_size); }
			size_type				max_size () const { return (_nalloc.max_size()); }

			ft::pair<iterator,bool>	insert (const value_type& val) { return (_insert(val)); }

			size_type				erase (const value_type& val) { return (_delete(val)); }

			void					swap (RedBlackTree& x) {
				_swap(_alloc, x._alloc);
				_swap(_comp, x._comp);
				_swap(_nalloc, x._nalloc);
				_swap(_start, x._start);
				_swap(_NIL, x._NIL);
				_swap(_size, x._size);
			}

			void					clear () {
				while (size())
					erase(*begin());
				_setRoot(nullPtr);
			}

			iterator				search (const value_type& val) {
				if (_getRoot() == nullPtr) return (end());

				node_pointer	ret = _search(_getRoot(), val);

				if (ret == _NIL) return (end());
				return (iterator(ret));
			}
			const_iterator			search (const value_type& val) const {
				if (_getRoot() == nullPtr) return (end());

				node_pointer		ret = _search(_getRoot(), val);

				if (ret == _NIL || ret == nullPtr) return (end());
				return (const_iterator(ret));
			}

			size_type				count (const value_type& val) const { return (search(val) == end() ? 0 : 1); }

			iterator				lower_bound (const value_type& val) {
				iterator			ret = begin();

				while (_comp(*ret, val) && ret != end())
					ret++;
				return (ret);
			}
			const_iterator			lower_bound (const value_type& val) const {
				const_iterator		ret = begin();

				while (_comp(*ret, val) && ret != end())
					ret++;
				return (ret);
			}

			iterator				upper_bound (const value_type& val) {
				iterator			ret = begin();

				while (!_comp(val, *ret) && ret != end())
					ret++;
				return (ret);
			}
			const_iterator			upper_bound (const value_type& val) const {
				const_iterator		ret = begin();

				while (!_comp(val, *ret) && ret != end())
					ret++;
				return (ret);
			}

		private:
			allocator_type			_alloc;
			node_allocator_type		_nalloc;
			value_compare			_comp;
			node_pointer			_start;
			node_pointer			_NIL;
			size_type				_size;

			node_pointer			_initNIL () {
				node_pointer	n = _nalloc.allocate(1);
				_nalloc.construct(n, node());
				return (n);
			}

			template< typename U >
			void					_swap (U& a, U& b) {
				U	tmp = a;
				a = b;
				b = tmp;
			}

			bool					_equal (const value_type& val1, const value_type& val2) const {
				if (!_comp(val1, val2) && !_comp(val2, val1)) return (true);
				return (false);
			}

			node_pointer			_getRoot () const { return (_start->_left); }
			void					_setRoot (node_pointer n) {
				if (n == _start) return ;
				if (n != nullPtr) {
					n->_parent = _start;
					n->_color = BLACK;
				}
				_start->_left = n;
				_start->_right = n;
			}

			bool					_isLeft (node_pointer n) const {
				if (n == n->_parent->_left) return (true);
				return (false);
			}
			bool					_isRight (node_pointer n) const { return (!_isLeft(n)); }

			node_pointer			_getGrandparent (node_pointer n) const {
				if (n != _NIL && n->_parent != nullPtr) return (n->_parent->_parent);
				return (nullPtr);
			}
			node_pointer			_getUncle (node_pointer n) const {
				node_pointer		g = _getGrandparent(n);

				if (g == nullPtr) return (nullPtr);
				if (_isLeft(n->_parent)) return (g->_right);
				return (g->_left);
			}
			node_pointer			_getSibling (node_pointer n) const { return (_isLeft(n) ? n->_parent->_right : n->_parent->_left); }

			node_pointer			_search (node_pointer n, const value_type& val) const {
				if (n == _NIL || _equal(n->_data, val)) return (n);
				if (_comp(val, n->_data)) return (_search(n->_left, val));
				return (_search(n->_right, val));
			}

			void					_rotateLeft (node_pointer n) {
				node_pointer		y = n->_right;

				n->_right = y->_left;
				if (y->_left != _NIL)
					y->_left->_parent = n;

				y->_parent = n->_parent;
				if (n->_parent == _start)
					_setRoot(y);
				else if (_isLeft(n))
					n->_parent->_left = y;
				else if (_isRight(n))
					n->_parent->_right = y;

				y->_left = n;
				n->_parent = y;
			}

			void					_rotateRight (node_pointer n) {
				node_pointer		y = n->_left;

				n->_left = y->_right;
				if (y->_right != _NIL)
					y->_right->_parent = n;

				y->_parent = n->_parent;
				if (n->_parent == _start)
					_setRoot(y);
				else if (_isRight(n))
					n->_parent->_right = y;
				else if (_isLeft(n))
					n->_parent->_left = y;

				y->_right = n;
				n->_parent = y;
			}

			void					_fixInsert (node_pointer n) {
				if (n == _getRoot() || n->_parent == _getRoot())
					return ;

				node_pointer		u;
				bool				isRight;

				while (n->_parent->_color == RED) {
					isRight = _isRight(n->_parent);
					u = _getUncle(n);
					if (u->_color == RED) {
						u->_color = BLACK;
						n->_parent->_color = BLACK;
						_getGrandparent(n)->_color = RED;
						n = _getGrandparent(n);
					}
					else {
						if (isRight && _isLeft(n)) {
							n = n->_parent;
							_rotateRight(n);
						}
						else if (!isRight && _isRight(n)) {
							n = n->_parent;
							_rotateLeft(n);
						}
						n->_parent->_color = BLACK;
						_getGrandparent(n)->_color = RED;
						if (isRight)
							_rotateLeft(_getGrandparent(n));
						else
							_rotateRight(_getGrandparent(n));
					}
					if (n == _getRoot()) break ;
				}
				_getRoot()->_color = BLACK;
			}

			ft::pair<iterator,bool>	_insert (const value_type& val) {
				node_pointer	n = _nalloc.allocate(1), x = _getRoot(), y = nullPtr;
				_nalloc.construct(n, node(val, nullPtr, _NIL, _NIL));

				if (x == nullPtr)
					_setRoot(n);
				else {
					while (x != _NIL) {
						y = x;
						if (_equal(n->_data, x->_data)) {
							_nalloc.destroy(n);
							_nalloc.deallocate(n, 1);
							return (ft::make_pair(iterator(x), false));
						}
						else if (_comp(n->_data, x->_data))
							x = x->_left;
						else if (_comp(x->_data, n->_data))
							x = x->_right;
					}
					n->_parent = y;
					if (_comp(n->_data, y->_data))
						y->_left = n;
					else if (_comp(y->_data, n->_data))
						y->_right = n;
				}
				_size++;
				_fixInsert(n);
				return (ft::make_pair(iterator(n), true));
			}

			void					_fixDelete (node_pointer n) {
				node_pointer		s;

				while (n != _getRoot() && n->_color == BLACK) {
					if (_isLeft(n)) {
						s = _getSibling(n);
						if (s->_color == RED) {
							s->_color = BLACK;
							n->_parent->_color = RED;
							_rotateLeft(n->_parent);
							s = _getSibling(n);
						}
						if (s->_left->_color == BLACK && s->_right->_color == BLACK) {
							s->_color = RED;
							n = n->_parent;
						}
						else {
							if (s->_right->_color == BLACK) {
								s->_left->_color = BLACK;
								s->_color = RED;
								_rotateRight(s);
								s = _getSibling(n);
							}
							s->_color = n->_parent->_color;
							n->_parent->_color = BLACK;
							s->_right->_color = BLACK;
							_rotateLeft(n->_parent);
							n = _getRoot();
						}
					}
					else {
						s = _getSibling(n);
						if (s->_color == RED) {
							s->_color = BLACK;
							n->_parent->_color = RED;
							_rotateRight(n->_parent);
							s = _getSibling(n);
						}
						if (s->_right->_color == BLACK && s->_left->_color == BLACK) {
							s->_color = RED;
							n = n->_parent;
						}
						else {
							if (s->_left->_color == BLACK) {
								s->_right->_color = BLACK;
								s->_color = RED;
								_rotateLeft(s);
								s = _getSibling(n);
							}
							s->_color = n->_parent->_color;
							n->_parent->_color = BLACK;
							s->_left->_color = BLACK;
							_rotateRight(n->_parent);
							n = _getRoot();
						}
					}
				}
				n->_color = BLACK;
			}

			void					_replace (node_pointer u, node_pointer v) {
				if (u->_parent == nullPtr)
					_setRoot(v);
				else if (_isLeft(u))
					u->_parent->_left = v;
				else if (_isRight(u))
					u->_parent->_right = v;
				v->_parent = u->_parent;
			}

			size_type				_delete (const value_type& val) {
				node_pointer		n = _search(_getRoot(), val), x, y;
				bool				yOriginalColor;

				if (n == _NIL) return (0);

				y = n;
				yOriginalColor = y->_color;

				if (n->_left == _NIL) {
					x = n->_right;
					_replace(n, n->_right);
				}
				else if (n->_right == _NIL) {
					x = n->_left;
					_replace(n, n->_left);
				}
				else {
					y = _successor(n);
					yOriginalColor = y->_color;

					x = y->_right;
					if (y->_parent == n)
						x->_parent = y;
					else {
						_replace(y, y->_right);
						y->_right = n->_right;
						y->_right->_parent = y;
					}
					_replace(n, y);
					y->_left = n->_left;
					y->_left->_parent = y;
					y->_color = n->_color;
				}
				_nalloc.destroy(n);
				_nalloc.deallocate(n, 1);
				_size--;

				if (yOriginalColor == BLACK)
					_fixDelete(x);

				return (1);
			}

			node_pointer			_minimum (node_pointer n) const {
				while (n->_left != _NIL)
					n = n->_left;
				return (n);
			}
			node_pointer			_maximum (node_pointer n) const {
				while (n->_right != _NIL)
					n = n->_right;
				return (n);
			}

			node_pointer			_successor (node_pointer n) const {
				if (n->_right != _NIL) return (_minimum(n->_right));

				node_pointer		y = n->_parent;
				while (y != _NIL && n == y->_right) {
					n = y;
					y = y->_parent;
				}
				return (y);
			}
			node_pointer			_predecessor (node_pointer n) const {
				if (n->_left != _NIL) return (_maximum(n->_right));

				node_pointer		y = n->_parent;
				while (y != _NIL && n == y->_left) {
					n = y;
					y = y->_parent;
				}
				return (y);
			}
	};

}

#endif

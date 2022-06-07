#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"

namespace	ft {

	template< class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef 			T												value_type;
			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef				ft::random_access_iterator<value_type>			iterator;
			typedef				ft::random_access_iterator<const value_type>	const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename	std::ptrdiff_t									difference_type;
			typedef				std::size_t										size_type;

			explicit	vector (const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _c(nullPtr), _size(0), _capacity(0) {}

			explicit	vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size(n), _capacity(n) {
				_c	= _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_c + i, val);
			}

			template< class InputIterator >
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullPtr)
				: _alloc(alloc), _size(0), _capacity(0) {
				_size		= ft::distance(first, last);
				_capacity	= _size;

				_c	= _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_c + i, *first++);
			}

			vector (const vector& x)
				: _alloc(x._alloc), _size(x._size), _capacity(x._capacity) {
				if (_capacity) {
					_c	= _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_c + i, *(x._c + i));
				}
				else
					_c = nullPtr;
			}

			~vector() {
				clear();
				_alloc.deallocate(_c, _capacity);
			};

			vector&					operator= (const vector& x) {
				clear();
				assign(x.begin(), x.end());
				return (*this);
			}

			iterator				begin () { return (iterator(_c)); }
			const_iterator			begin () const { return (const_iterator(_c)); }

			iterator				end () { return (empty() ? begin() : iterator(_c + _size)); }
			const_iterator			end () const { return (empty() ? begin() : const_iterator(_c + _size)); }

			reverse_iterator		rbegin () { return (reverse_iterator(_c + _size)); }
			const_reverse_iterator	rbegin () const { return (const_reverse_iterator(_c + _size)); }

			reverse_iterator		rend () { return (reverse_iterator(_c)); }
			const_reverse_iterator	rend () const { return (const_reverse_iterator(_c)); }

			size_type				size () const { return (_size); }
			size_type				max_size () const { return (_alloc.max_size()); }
			void					resize (size_type n, value_type val = value_type()) {
				if (n > max_size())
					throw (std::length_error("vector"));

				if (n < _size) {
					while (_size != n)
						pop_back();
				}
				else if (n > _size) {
					if (n > _capacity)
						reserve(n);
					while (_size != n)
						push_back(val);
				}
			}
			size_type				capacity () const { return (_capacity); }
			bool					empty () const { return (!_size); }
			void					reserve (size_type n) {
				if (n > max_size())
					throw (std::length_error("vector"));

				if (n <= _capacity)
					return ;

				if (n > _capacity) {
					pointer	new_c = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(new_c + i, *(_c + i));
						_alloc.destroy(_c + i);
					}
					_alloc.deallocate(_c, _capacity);
					_capacity = n;
					_c = new_c;
				}
			}

			reference				operator[] (size_type n) { return (_c[n]); }
			const_reference			operator[] (size_type n) const { return (_c[n]); }

			reference				at (size_type n) {
				if (n >= _size || n < 0)
					throw (std::out_of_range("vector"));
				return (*(_c + n));
			}
			const_reference			at (size_type n) const {
				if (n >= _size || n < 0)
					throw (std::out_of_range("vector"));
				return (*(_c + n));
			}

			reference				front () { return (*_c); }
			const_reference			front () const { return (*_c); }

			reference				back () { return (*(_c + _size - 1)); }
			const_reference			back () const { return (*(_c + _size - 1)); }

			template< class InputIterator >
			void					assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullPtr) {
				clear();

				size_type	n = ft::distance(first, last);
				if (n >_capacity)
					reserve(n);

				for (size_type i = 0; i < n; i++, _size++)
					_alloc.construct(_c + i, *first++);
			}
			void					assign (size_type n, const value_type& val) {
				clear();

				if (n > _capacity)
					reserve(n);

				for (size_type i = 0; i < n; i++, _size++)
					_alloc.construct(_c + i, val);
			}

			void					push_back (const value_type& val) {
				if (!_capacity) {
					_capacity++;
					_c	= _alloc.allocate(_capacity);
					_alloc.construct(_c, val);
				}
				else {
					if (_size + 1 > _capacity)
						reserve(_capacity * 2);
					_alloc.construct(_c + _size, val);
				}
				_size++;
			}
			void					pop_back () {
				_alloc.destroy(&back());
				_size--;
			}

			iterator				insert (iterator position, const value_type& val) {
				size_type	pos = position - begin();

				if (!_capacity)
					reserve(1);
				else if (_size + 1 > _capacity)
					reserve(_size + 1);

				for (size_type i = _size; i > pos; i--) {
					_alloc.construct(_c + i, *(_c + i - 1));
					_alloc.destroy(_c + i - 1);
				}
				_alloc.construct(_c + pos, val);
				_size++;

				return (iterator(_c + pos));
			}
			void					insert (iterator position, size_type n, const value_type& val) {
				size_type	pos = position - begin();

				if (!_capacity)
					reserve(n);
				else if (_size + n > _capacity)
					reserve(_size + n);

				for (size_type i = _size + n - 1; i > pos + n - 1; i--) {
					_alloc.construct(_c + i, *(_c + i - n));
					_alloc.destroy(_c + i - n);
				}
				for (size_type i = pos; i < pos + n; i++)
					_alloc.construct(_c + i, val);
				_size += n;
			}
			template< class InputIterator >
			void					insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullPtr) {
				size_type	n = ft::distance(first, last);
				size_type	pos = position - begin();

				if (!_capacity)
					reserve(n);
				else if (_size + n > _capacity)
					reserve(_size + n);

				for (size_type i = _size + n - 1; i > pos + n - 1; i--) {
					_alloc.construct(_c + i, *(_c + i - n));
					_alloc.destroy(_c + i - n);
				}
				for (size_type i = pos; i < pos + n; i++)
					_alloc.construct(_c + i, *first++);
				_size += n;
			}

			iterator				erase (iterator position) {
				size_type	pos = position - begin();
				for (size_type i = pos; i < _size - 1; i++)
					_alloc.construct(_c + i, *(_c + i + 1));

				pop_back();

				return (position);
			}
			iterator				erase (iterator first, iterator last) {
				difference_type	n = ft::distance(first, last);

				size_type	pos = first - begin();
				for (size_type i = pos; i < _size - n; i++)
					_alloc.construct(_c + i, *(_c + i + n));

				while (n--)
					pop_back();

				return (first);
			}

			void					swap (vector& x) {
				allocator_type	tmp_alloc		= x._alloc;
				pointer			tmp_c			= x._c;
				size_type		tmp_size		= x._size;
				size_type		tmp_capacity	= x._capacity;

				x._alloc	= _alloc;
				x._c		= _c;
				x._size		= _size;
				x._capacity	= _capacity;

				_alloc		= tmp_alloc;
				_c			= tmp_c;
				_size		= tmp_size;
				_capacity	= tmp_capacity;
			}

			void					clear () {
				while (!empty())
					pop_back();
			}

			allocator_type			get_allocator () const { return (allocator_type()); }

		private:
			allocator_type			_alloc;
			pointer					_c;
			size_type				_size;
			size_type				_capacity;

		};

	template< class T, class Alloc >
	bool	operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (lhs.size() != rhs.size() ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template< class T, class Alloc >
	bool	operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }
	template< class T, class Alloc >
	bool	operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class T, class Alloc >
	bool	operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }
	template< class T, class Alloc >
	bool	operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }
	template< class T, class Alloc >
	bool	operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
	template< class T, class Alloc >
	void	swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif

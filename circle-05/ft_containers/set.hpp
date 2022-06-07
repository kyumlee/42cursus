#ifndef __SET_HPP__
# define __SET_HPP__

# include "./red_black_tree.hpp"

namespace	ft {

	template< class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class	set {
		public:
			typedef				T										key_type;
			typedef				T										value_type;
			typedef				Compare									key_compare;
			typedef				Compare									value_compare;
			typedef				Alloc									allocator_type;
			typedef	typename	allocator_type::reference				reference;
			typedef	typename	allocator_type::const_reference			const_reference;
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;
			typedef				ft::rbt_iterator<value_type, true>		iterator;
			typedef				ft::rbt_iterator<value_type, true>		const_iterator;
			typedef				ft::reverse_iterator<iterator>			reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef				std::ptrdiff_t							difference_type;
			typedef				std::size_t								size_type;

			explicit	set (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _c(comp) {}
			template< class InputIterator >
			set (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _c(comp) { insert(first, last); }
			set (const set& x)
				: _alloc(x._alloc), _comp(x._comp), _c(_comp) { insert(x.begin(), x.end()); }

			~set () { clear(); }

			set&				operator= (const set& x) { _c = x._c; return (*this); }

			iterator				begin () { return (_c.begin()); }
			const_iterator			begin () const { return (_c.begin()); }

			iterator				end () { return (_c.end()); }
			const_iterator			end () const { return (_c.end()); }

			reverse_iterator		rbegin () { return (_c.rbegin()); }
			const_reverse_iterator	rbegin () const { return (_c.rbegin()); }

			reverse_iterator		rend () { return (_c.rend()); }
			reverse_iterator		rend () const { return (_c.rend()); }

			bool					empty () const { return (_c.empty()); }
			size_type				size () const { return (_c.size()); }
			size_type				max_size () const { return (_c.max_size()); }

			ft::pair<iterator,bool>	insert (const value_type& val) { return (_c.insert(val)); }
			iterator				insert (iterator position, const value_type& val) {
				(void)position;
				return (insert(val).first);
			}
			template< class InputIterator >
			void					insert (InputIterator first, InputIterator last) {
				while (first != last)
					insert(*first++);
			}

			void					erase (iterator position) { erase(*position); }
			size_type				erase (const value_type& val) { return (_c.erase(val)); }
			void					erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}

			void					swap (set& x) {
				allocator_type	temp_alloc	= x._alloc;
				key_compare		temp_comp	= x._comp;

				x._alloc	= _alloc;
				x._comp		= _comp;

				_alloc		= temp_alloc;
				_comp		= temp_comp;

				_c.swap(x._c);
			}

			void					clear () { _c.clear(); }

			key_compare				key_comp () const { return (key_compare()); }

			value_compare			value_comp () const { return (value_compare()); }

			iterator				find (const value_type& val) { return (_c.search(val)); }
			const_iterator			find (const value_type& val) const { return (_c.search(val)); }

			size_type				count (const value_type& val) const { return (_c.count(val)); }

			iterator				lower_bound (const value_type& val) { return (_c.lower_bound(val)); }
			const_iterator			lower_bound (const value_type& val) const { return (_c.lower_bound(val)); }

			iterator				upper_bound (const value_type& val) { return (_c.upper_bound(val)); }
			const_iterator			upper_bound (const value_type& val) const { return (_c.upper_bound(val)); }

			ft::pair<iterator,iterator>	equal_range (const value_type& val) { return (ft::make_pair(lower_bound(val), upper_bound(val))); }
			ft::pair<const_iterator,const_iterator>	equal_range (const value_type& val) const { return (ft::make_pair(lower_bound(val), upper_bound(val))); }

			allocator_type			get_allocator () const { return (allocator_type()); }

		private:
			allocator_type								_alloc;
			key_compare									_comp;
			ft::RedBlackTree<value_type, key_compare>	_c;

	};

	template< class T, class Compare, class Alloc >
	bool	operator== (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (lhs.size() != rhs.size() ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template< class T, class Compare, class Alloc >
	bool	operator!= (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (!(lhs == rhs)); }
	template< class T, class Compare, class Alloc >
	bool	operator<  (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class T, class Compare, class Alloc >
	bool	operator<= (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (!(rhs < lhs)); }
	template< class T, class Compare, class Alloc >
	bool	operator>  (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (rhs < lhs); }
	template< class T, class Compare, class Alloc >
	bool	operator>= (const ft::set<T,Compare,Alloc>& lhs, const ft::set<T,Compare,Alloc>& rhs) { return (!(lhs < rhs)); }

}

#endif

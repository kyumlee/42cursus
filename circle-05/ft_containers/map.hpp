#ifndef __MAP_HPP__
# define __MAP_HPP__

# include "./red_black_tree.hpp"

namespace	ft {

	template< class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair< const Key, T > > >
	class	map {
		public:
			typedef				Key												key_type;
			typedef				T												mapped_type;
			typedef				ft::pair<const key_type, mapped_type>			value_type;
			typedef				Compare											key_compare;

			class	value_compare : binary_function<value_type, value_type, bool> {
				friend class	map<key_type, mapped_type, key_compare>;

				public:
					bool	operator () (const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }

				protected:
					Compare	comp;
					value_compare (Compare c) : comp(c) {}
			};

			typedef				Alloc											allocator_type;
			typedef	typename	allocator_type::reference						reference;
			typedef	typename	allocator_type::const_reference					const_reference;
			typedef	typename	allocator_type::pointer							pointer;
			typedef	typename	allocator_type::const_pointer					const_pointer;
			typedef	typename	ft::rbt_iterator<value_type,false>				iterator;
			typedef	typename	ft::rbt_iterator<value_type,true>				const_iterator;
			typedef	typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	typename	std::ptrdiff_t									difference_type;
			typedef				std::size_t										size_type;

			explicit	map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _c(value_compare(_comp)) {}
			template< class InputIterator >
			map (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _comp(comp), _c(value_compare(_comp)) { insert(first, last); }

			map (const map& x)
				: _alloc(x._alloc), _comp(x._comp), _c(value_compare(_comp)) { insert(x.begin(), x.end()); }

			~map () { clear(); }

			map&					operator= (const map& x) {
				_c = x._c;
				return (*this);
			}

			iterator				begin () { return (_c.begin()); }
			const_iterator			begin () const { return (_c.begin()); }

			iterator				end () { return (_c.end()); }
			const_iterator			end () const { return (_c.end()); }

			reverse_iterator		rbegin () { return (_c.rbegin()); }
			const_reverse_iterator	rbegin () const { return (_c.rbegin()); }

			reverse_iterator		rend () { return (_c.rend()); }
			const_reverse_iterator	rend () const { return (_c.rend()); }

			bool					empty () const { return (_c.empty()); }
			size_type				size () const { return (_c.size()); }
			size_type				max_size () const { return (_c.max_size()); }

			mapped_type&			operator[] (const key_type& k) {
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			}

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

			void					erase (iterator position) { erase(position->first); }
			size_type				erase (const key_type& k) { return (_c.erase(ft::make_pair(k, mapped_type()))); }
			void					erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}

			void					swap (map& x) {
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
			value_compare			value_comp () const { return (value_compare(key_compare())); }

			iterator				find (const key_type& k) { return (_c.search(ft::make_pair(k, mapped_type()))); }
			const_iterator			find (const key_type& k) const { return (_c.search(ft::make_pair(k, mapped_type()))); }
			size_type				count (const key_type& k) const { return (_c.count(ft::make_pair(k, mapped_type()))); }

			iterator				lower_bound (const key_type& k) { return (_c.lower_bound(ft::make_pair(k, mapped_type()))); }
			const_iterator			lower_bound (const key_type& k) const { return (_c.lower_bound(ft::make_pair(k, mapped_type()))); }

			iterator				upper_bound (const key_type& k) { return (_c.upper_bound(ft::make_pair(k, mapped_type()))); }
			const_iterator			upper_bound (const key_type& k) const { return (_c.upper_bound(ft::make_pair(k, mapped_type()))); }

			ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const { return (ft::make_pair(lower_bound(k), upper_bound(k))); }
			ft::pair<iterator,iterator>				equal_range (const key_type& k) { return (ft::make_pair(lower_bound(k), upper_bound(k))); }

			allocator_type			get_allocator () const { return (allocator_type()); }

		private:
			allocator_type							_alloc;
			key_compare								_comp;
			RedBlackTree<value_type, value_compare>	_c;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool	operator== (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (lhs.size() != rhs.size() ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator!= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (!(lhs == rhs)); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator<  (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator<= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (!(rhs < lhs)); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>  (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (rhs < lhs); }
	template< class Key, class T, class Compare, class Alloc >
	bool	operator>= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) { return (!(lhs < rhs)); }

	template< class Key, class T, class Compare, class Alloc >
	void	swap (ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs) { lhs.swap(rhs); }

}

#endif

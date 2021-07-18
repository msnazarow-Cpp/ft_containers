#pragma once
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include <cstdlib>
#include <iterator>
#include "rbtree.hpp"
#include <limits>
namespace ft{
	template < class Key,                                     // map::key_type
			class T,                                       // map::mapped_type
			class Compare = ft::less<Key>,                     // map::key_compare
			class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
			> class map
			{
			public:
				typedef Key key_type;
				typedef T mapped_type;
				typedef ft::pair<const key_type, mapped_type> value_type;
				typedef Compare key_compare;
				class value_compare
				{
					friend class map;
					protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
				};
				typedef Alloc allocator_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename allocator_type::difference_type difference_type;
				typedef typename allocator_type::size_type size_type;
				typedef rbtree_iterator<value_type, value_compare> iterator;
				typedef rbtree_iterator<const value_type ,value_compare> const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			private:
				key_compare comp;
				ft::rbtree<ft::pair<const Key, T>, value_compare> tree;
				allocator_type _alloc;
				static bool keys_equal(const ft::pair<const Key, T> &p1, const ft::pair<const Key, T> &p2) {Compare comp; return !(comp(p1.first, p2.first) || comp(p2.first, p1.first));}
				static bool key_gr_eq(const ft::pair<const Key, T> &p1, const ft::pair<const Key, T> &p2) {Compare comp; return (!comp(p2.first, p1.first));}
				static bool key_sm(const ft::pair<const Key, T> &p1, const ft::pair<const Key, T> &p2 ){Compare comp; return comp(p1.first, p2.first);}
				
			public:
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):comp(comp), tree(value_compare(comp)), _alloc(alloc){}
				template <class InputIterator>
				map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): comp(comp), tree(first, last, value_compare(comp)), _alloc(alloc){}
				map (const map& x): tree(x.tree){}
				~map(){}
				map& operator= (const map& x){
					tree.operator=(x.tree);
					return (*this);
				}
				iterator begin() {return tree.begin();}
				const_iterator begin() const {return tree.begin();}
				iterator end() {return tree.end();}
				const_iterator end() const {return tree.end();}
				reverse_iterator rbegin() {return tree.rbegin();}
				const_reverse_iterator rbegin() const {return tree.rbegin();}
				reverse_iterator rend() {return tree.rend();}
				const_reverse_iterator rend() const {return tree.rend();}
				bool empty() const {return tree.empty();}
				size_type size() const {return tree.size();}
				size_type max_size() const {
					return std::numeric_limits<difference_type>::max() / (sizeof(ft::node<value_type>) );
					return tree.max_size();
					}
				mapped_type &operator[] (const key_type& k) { return ((insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()))).first).base()->data.second;}
				pair<iterator,bool> insert (const value_type& val)
				{
					size_type length_before = size();
					iterator it = tree.insert(val);
					bool elementInserted = size() > length_before;
					return ft::make_pair<iterator, bool>(it, elementInserted);
				}
				iterator insert (iterator position, const value_type& val)
				{ return tree.insert(position, val);}
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last){ tree.insert(first, last);}
				void erase (iterator position){ tree.erase(position);}
				size_type erase (const key_type& k) {return tree.eraseIf(keys_equal, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				void erase (iterator first, iterator last) {tree.erase(first, last);}
				void swap (map& x) {tree.swap(x.tree);}
				void clear() {tree.clear();}
				key_compare key_comp() const {return key_compare();}
				value_compare value_comp() const {return value_compare(Compare());}
				iterator find (const key_type& k) {return tree.find(keys_equal, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				const_iterator find (const key_type& k) const {return tree.find(keys_equal, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				size_type count (const key_type& k) const {return tree.countIf(keys_equal, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				iterator lower_bound (const key_type& k) {return tree.find(key_gr_eq, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				const_iterator lower_bound (const key_type& k) const {return tree.find(key_gr_eq, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				iterator upper_bound (const key_type& k) {return tree.find(key_sm, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				const_iterator upper_bound (const key_type& k) const {return tree.find(key_sm, ft::make_pair<key_type, mapped_type>(k, mapped_type()));}
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const {return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));}
				pair<iterator,iterator> equal_range (const key_type& k) {return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));}
			};

}
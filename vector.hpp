#include "allocator.hpp"

namespace ft{
	
	template<class T, class Alloc = std::allocator<T>> 
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef allocator_type::reference					reference;
			typedef allocator_type::const_reference				const_reference;
			typedef allocator_type::pointer						pointer;
			typedef allocator_type::const_pointer				const_pointer;
			typedef iterator_traits<iterator>::difference_type	difference_type;
			typedef size_t										size_type;
		private:
			pointer		_raw;
			size_type		;
		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : _Base(alloc), guaranteed_capacity(0) {}
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
					vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());	
			vector (const vector& x);
			vector(){}
			~vector(){}
			vector &operator = (const vector & vec){}
			begin(){}
			end(){}
			rbegin(){}
			rend(){}
			size(){}
			max_size(){}
			resize(){}
			capacity(){}
			empty(){}
			reserve(){}
			operator[](){}
			at(){}
			front(){}
			back(){}
			assign(){}
			push_back(){}
			pop_back(){}
			insert(){}
			swap(){}
			clear(){}

	};
}
